#pragma once

#include <Core>
#include <sofa.h>
#include "celestial_mechanics/time/Time.hpp"
#include "celestial_mechanics/time/TimeConverter.hpp"
#include <array>
#include "EOPContainer.hpp"

class ReferenceSystemConverter {
    EOPContainer EOPContainer_;
    public:
        ReferenceSystemConverter (const EOPContainer& EOPContainer) : EOPContainer_(EOPContainer) {};

        Eigen::Matrix<double, 3, 3> GCRStoCIRS(Time<Scale::UTC> utc) {
            auto timeConverter = TimeConverter<EOPContainer>(EOPContainer_);
            const auto tt = timeConverter.convert<Scale::TT>(utc);
            double tt1 = tt.jdInt(); double tt2 = tt.jdFrac();
            double dX = EOPContainer_.dX(utc.mjd());
            double dY = EOPContainer_.dY(utc.mjd());
            double X, Y;
            iauXy06(tt1, tt2, &X, &Y);
            double s = iauS06(tt1, tt2, X, Y);
            double c2i[3][3];
            iauC2ixys(X+dX, Y+dY, s, c2i);
            Eigen::Matrix<double, 3, 3> CelestialToIntermediate{{c2i[0][0], c2i[0][1], c2i[0][2]},
                                                                {c2i[1][0], c2i[1][1], c2i[1][2]},
                                                                {c2i[2][0], c2i[2][1], c2i[2][2]}};
            return CelestialToIntermediate;
        }
};