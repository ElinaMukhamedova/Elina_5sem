#pragma once

#include <Core>
//#include <Geometry>
#include <sofa.h>
#include "celestial_mechanics/time/Time.hpp"
#include "celestial_mechanics/time/TimeConverter.hpp"
#include <array>
#include "EOPContainer.hpp"

class ReferenceSystemConverter {
    EOPContainer EOPcontainer_;
    TimeConverter<EOPContainer> timeConverter_;
    public:
        ReferenceSystemConverter (const EOPContainer& EOPcontainer) : EOPcontainer_(EOPcontainer), timeConverter_(EOPcontainer_) {}

        Eigen::Matrix<double, 3, 3> GCRStoCIRS(Time<Scale::UTC> utc) {
            const auto tt = timeConverter_.convert<Scale::TT>(utc);
            double tt1 = tt.jdInt(); double tt2 = tt.jdFrac();
            double dX = EOPcontainer_.dX(utc.mjd());
            double dY = EOPcontainer_.dY(utc.mjd());
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

        Eigen::Matrix<double, 3, 3> CIRStoTIRS(Time<Scale::UTC> utc) {
            const auto ut1 = timeConverter_.convert<Scale::UT1>(utc);
            double ERA = iauEra00(ut1.jdInt(), ut1.jdFrac());

        }
};