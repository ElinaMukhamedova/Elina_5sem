#pragma once

#include <calceph.h>
#include <Core>
#include "celestial_mechanics/time/Time.hpp"
#include "celestial_mechanics/Exception.hpp"

enum class Himmellegeme{Merkur = 1, Venus = 2, Jorden = 3, Mars = 4, Jupiter = 5, Saturn = 6,
                        Uranus = 7, Neptun = 8, Pluto = 9, Månen = 10, Sola = 11};

class Evig {
    t_calcephbin *peph;
    
    public:
        Evig(const std::string& pathEphemerides) : peph{nullptr} {
            peph = calceph_open(pathEphemerides.c_str());
            if (!peph){
                throw Exception("Kan ikke åpne efemerider filen!");
            }
        }

        ~Evig(){
            calceph_close(peph);
        }

        template<Himmellegeme Sentrum, Himmellegeme Mål>
        Eigen::Vector3d vector(Time<Scale::TDB> tdb) {
            double jdInt = tdb.jdInt(); double jdFrac = tdb.jdFrac();

            double PosisjonHastighet[6];
            calceph_compute(peph, jdInt, jdFrac, (int)Mål, (int)Sentrum, PosisjonHastighet);

            return Eigen::Vector3d {PosisjonHastighet[0], PosisjonHastighet[1], PosisjonHastighet[2]};
        }
};