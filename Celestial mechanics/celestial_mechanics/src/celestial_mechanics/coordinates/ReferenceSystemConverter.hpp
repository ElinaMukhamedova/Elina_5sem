#pragma once

#include <Core>
#include <Geometry>
#include <sofa.h>
#include "celestial_mechanics/time/Time.hpp"
#include "celestial_mechanics/time/TimeConverter.hpp"
#include <array>
#include "EOPContainer.hpp"
#include <iomanip>
#include <iostream>

class ReferenceSystemConverter {
    EOPContainer EOPcontainer_;
    TimeConverter<EOPContainer> timeConverter_;
    public:
        ReferenceSystemConverter (const EOPContainer& EOPcontainer) : EOPcontainer_(EOPcontainer), timeConverter_(EOPcontainer_) {}

        TimeConverter<EOPContainer> timeConverter() {return timeConverter_;}

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

        Eigen::Quaternion<double> rotationCIRStoTIRS(Time<Scale::UTC> utc) {
            const auto ut1 = timeConverter_.convert<Scale::UT1>(utc);
            double ERA = iauEra00(ut1.jdInt(), ut1.jdFrac());
            std::cout << std::setprecision(15) << "ERA = " << ERA << std::endl;
            Eigen::Quaternion<double> IntermediateToTerrestrial(Eigen::AngleAxis<double>(-ERA, Eigen::Vector<double, 3>{0, 0, 1}));
            return IntermediateToTerrestrial;
        }

        Eigen::Quaternion<double> GCRStoTIRS(Time<Scale::UTC> utc) {
            Eigen::Quaternion<double> c2i = Eigen::Quaternion<double>(GCRStoCIRS(utc));
            return rotationCIRStoTIRS(utc) * c2i;
        }

        Eigen::Quaternion<double> PolarMotion(Time<Scale::UTC> utc) {
            const auto tt = timeConverter_.convert<Scale::TT>(utc);
            double xTerr = EOPcontainer_.xTerr(utc.mjd());
            double yTerr = EOPcontainer_.yTerr(utc.mjd());
            double sTerr = iauSp00(tt.jdInt(), tt.jdFrac());
            double pm[3][3];
            iauPom00(xTerr, yTerr, sTerr, pm);
            Eigen::Matrix<double, 3, 3> pmMatrix{{pm[0][0], pm[0][1], pm[0][2]},
                                            {pm[1][0], pm[1][1], pm[1][2]},
                                            {pm[2][0], pm[2][1], pm[2][2]}};
            return Eigen::Quaternion<double>(pmMatrix);
        }

        Eigen::Matrix<double, 3, 3> GCRStoITRS(Time<Scale::UTC> utc) {
            Eigen::Quaternion<double> gcrs2itrs = PolarMotion(utc) * GCRStoTIRS(utc);
            return gcrs2itrs.toRotationMatrix();
        }

        Eigen::Matrix<double, 3, 3> ITRStoGCRS(Time<Scale::UTC> utc) {
            Eigen::Quaternion<double> itrs2gcrs = GCRStoTIRS(utc).conjugate() * PolarMotion(utc).conjugate();
            return itrs2gcrs.toRotationMatrix();
        }

        Eigen::Matrix<double, 3, 3> GCRS2ITRS(Time<Scale::UTC> utc) {
            double utcMJD = utc.mjd();

            const auto ut1 = timeConverter_.convert<Scale::UT1>(utc);
            double era = iauEra00(ut1.jdInt(), ut1.jdFrac());

            const auto tt = timeConverter_.convert<Scale::TT>(utc);
            double tt1 = tt.jdInt(); double tt2 = tt.jdFrac();
            double dX = EOPcontainer_.dX(utcMJD); double dY = EOPcontainer_.dY(utcMJD);
            double X, Y;
            iauXy06(tt1, tt2, &X, &Y);
            double s = iauS06(tt1, tt2, X, Y);
            double rc2i[3][3];
            iauC2ixys(X+dX, Y+dY, s, rc2i);

            double rpom[3][3];
            double xTerr = EOPcontainer_.xTerr(utcMJD); double yTerr = EOPcontainer_.yTerr(utcMJD);
            double sTerr = iauSp00(tt1, tt2);
            iauPom00(xTerr, yTerr, sTerr, rpom);

            double rc2t[3][3];
            iauC2tcio(rc2i, era, rpom, rc2t);

            return Eigen::Matrix<double, 3, 3> {{rc2t[0][0], rc2t[0][1], rc2t[0][2]},
                                                {rc2t[1][0], rc2t[1][1], rc2t[1][2]},
                                                {rc2t[2][0], rc2t[2][1], rc2t[2][2]}};
        }
};