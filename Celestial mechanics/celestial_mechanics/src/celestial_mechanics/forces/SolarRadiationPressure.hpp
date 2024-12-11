#pragma once

#include <calceph/calceph.h>
#include <Core>
#include <time/Time.hpp>
#include <string>
#include <cmath>
#include "TSIcontainer.hpp"

class SolarRadiationPressure {

    std::string pathEphemerides_;
    TSIcontainer TSIcontainer_;

    public:
        SolarRadiationPressure(const std::string& pathEphemerides, TSIcontainer& TSI)
            : pathEphemerides_(pathEphemerides), TSIcontainer_(TSI) {}

        struct SatelliteParameters {
            double S_srp;
        };

        template<typename Params>
        Eigen::Vector3d calcAcceleration(const Eigen::Vector3d& positionECI, const Eigen::Vector3d& velocityECI,
                                            const double mass, const SatelliteParameters& satParams,
                                                const Params& params){
            Time<Scale::TDB> tdb = params.tdb;
            double jdInt = tdb.jdInt(); double jdFrac = tdb.jdFrac();
            
            double tsi = TSIcontainer_.tsi(tdb);

            int res = calceph_sopen(pathEphemerides_.c_str());

            if (res) {
                double helioEarth[6];
                calceph_scompute(jdInt, jdFrac, 3, 11, helioEarth);

                Eigen::Vector3d SunEarth{helioEarth[0], helioEarth[1], helioEarth[2]};
                Eigen::Vector3d EarthSun{-helioEarth[0], -helioEarth[1], -helioEarth[2]};

                double helioMoon[6];
                calceph_scompute(jdInt, jdFrac, 10, 11, helioMoon);

                Eigen::Vector3d SunMoon{helioMoon[0], helioMoon[1], helioMoon[2]};
                Eigen::Vector3d MoonSun{-helioMoon[0], -helioMoon[1], -helioMoon[2]};

                Eigen::Vector3d MoonSatellite = MoonSun + SunEarth + positionECI;

                int shadow = 1;
                if (EarthSun.dot(positionECI) <= 0) {
                    double numeratorEarth = (EarthSun.cross(positionECI)).norm();
                    double denominatorEarth = positionECI.norm();
                    double rhoEarth = numeratorEarth / denominatorEarth;
                    if (rhoEarth < 6378140)
                        shadow = 0;
                }
                if (MoonSun.dot(MoonSatellite) <= 0) {
                    double numeratorMoon = (MoonSun.cross(MoonSatellite)).norm();
                    double denominatorMoon = MoonSatellite.norm();
                    double rhoMoon = numeratorMoon / denominatorMoon;
                    if (rhoMoon < 1737400)
                        shadow = 0;
                }

                Eigen::Vector3d SunSatellite = SunEarth + positionECI;
                Eigen::Vector3d n = SunSatellite.normalized();
                double SunSatelliteDistance = SunSatellite.norm();
                const double AU = 149597870700;
                Eigen::Vector3d j0 = tsi * std::pow(AU/SunSatelliteDistance, 2) * n;

                Eigen::Vector3d F_srp = (shadow * satParams.S_srp / 299792458) * j0;
                
                calceph_sclose();
            }
            else {
                throw Exception("Can't open the ephemerides file!");
            }

            return F_srp / mass;
        }

};