#pragma once

#include <calceph/calceph.h>
#include <Core>
#include <time/Time.hpp>
#include <string>
#include <cmath>
#include "TSIcontainer.hpp"
#include "Eternal.hpp"

class SolarRadiationPressure {

    Eternal eternal_;
    TSIcontainer TSIcontainer_;

    public:
        SolarRadiationPressure(Eternal& eternal, TSIcontainer& TSI)
            : eternal_(eternal), TSIcontainer_(TSI) {}

        struct SatelliteParameters {
            double S_srp;
        };

        template<typename Params>
        Eigen::Vector3d calcAcceleration(const Eigen::Vector3d& positionECI, const Eigen::Vector3d& velocityECI,
                                            const double mass, const SatelliteParameters& satParams,
                                                const Params& params){

            const Eigen::Quaternion eci2ICRF = params.eci2icrf;
            Time<Scale::TDB> tdb = params.tdb;
            double tsi = TSIcontainer_.tsi(tdb);

            const double AU = 149597870700;
            const double rEarthAU = 6378140 / AU;
            const double rMoonAU = 1737400 / AU;
            const double lightSpeed = 299792458;
            
            Eigen::Vector3d SunEarth = eternal_.vector<CelestialBody::Sun, CelestialBody::Earth>(tdb);
            Eigen::Vector3d EarthSun = -SunEarth;

            Eigen::Vector3d SunMoon = eternal_.vector<CelestialBody::Sun, CelestialBody::Moon>(tdb);
            Eigen::Vector3d MoonSun = -SunMoon;
            
            Eigen::Vector3d EarthSatellite = eci2icrf._transformVector(positionECI);
            Eigen::Vector3d MoonSatellite = MoonSun + SunEarth + positionECI;

            int shadow = 1;
            if (EarthSun.dot(EarthSatellite) <= 0) {
                double numeratorEarth = (EarthSun.cross(EarthSatellite)).norm();
                double denominatorEarth = EarthSatellite.norm();
                double rhoEarth = numeratorEarth / denominatorEarth;
                if (rhoEarth < rEarthAU)
                    shadow = 0;
            }
            if (MoonSun.dot(MoonSatellite) <= 0) {
                double numeratorMoon = (MoonSun.cross(MoonSatellite)).norm();
                double denominatorMoon = MoonSatellite.norm();
                double rhoMoon = numeratorMoon / denominatorMoon;
                if (rhoMoon < rMoonAU)
                    shadow = 0;
            }

            Eigen::Vector3d SunSatellite = SunEarth + EarthSatellite;
            Eigen::Vector3d n = SunSatellite.normalized();
            double SunSatelliteDistance = SunSatellite.norm();
            Eigen::Vector3d j0 = tsi * std::pow(AU/SunSatelliteDistance, 2) * n;

            Eigen::Vector3d F_srp = (shadow * satParams.S_srp / lightSpeed) * j0;

            return F_srp / mass;
        }

};