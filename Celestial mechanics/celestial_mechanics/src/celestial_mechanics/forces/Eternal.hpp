#pragma once

#include <calceph.h>
#include <Core>
#include "celestial_mechanics/time/Time.hpp"
#include "celestial_mechanics/Exception.hpp"

enum class CelestialBody{Mercury = 1, Venus = 2, Earth = 3, Mars = 4, Jupiter = 5, Saturn = 6,
                        Uranus = 7, Neptune = 8, Pluto = 9, Moon = 10, Sun = 11};

class Eternal {
    t_calcephbin *peph;
    
    public:
        Eternal(const std::string& pathEphemerides) : peph{nullptr} {
            peph = calceph_open(pathEphemerides.c_str());
            if (!peph){
                throw Exception("Can't open the ephemerides file!");
            }
        }

        ~Eternal(){
            calceph_close(peph);
        }

        template<CelestialBody Centre, CelestialBody Target>
        Eigen::Vector3d vector(Time<Scale::TDB> tdb) {
            double jdInt = tdb.jdInt(); double jdFrac = tdb.jdFrac();

            double PositionVelocity[6];
            calceph_compute(peph, jdInt, jdFrac, (int)Target, (int)Centre, PositionVelocity);

            return Eigen::Vector3d {PositionVelocity[0], PositionVelocity[1], PositionVelocity[2]};
        }
};