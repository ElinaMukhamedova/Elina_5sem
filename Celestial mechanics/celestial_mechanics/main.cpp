#include <gtest/gtest.h>
#include "celestial_mechanics/coordinates/ReferenceSystemConverter.hpp"
#include "celestial_mechanics/coordinates/EOPContainer.hpp"
#include "celestial_mechanics/time/Time.hpp"
#include "celestial_mechanics/time/TimeConverter.hpp"
#include <Core>
#include <iomanip>
#include <iostream>

int main() {
    EOPContainer EOPcontainer = EOPContainer("/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/celestial_mechanics/resources/earth_rotation.csv");
    ReferenceSystemConverter coordinatesConverter = ReferenceSystemConverter(EOPcontainer);

    Eigen::Vector<double, 3> r_GCRS{6700e3, 0, 0};
    
    const auto tt = Time<Scale::TT>::fromCalendar(2019, 9, 13, 12, 45, 0);
    std::cout << "tt.jdInt() = " << std::setprecision(17) <<  tt.jdInt() << std::endl;
    std::cout << "tt.jdFrac() = " << std::setprecision(17) <<  tt.jdFrac() << std::endl;
    
    const auto utc = coordinatesConverter.timeConverter().convert<Scale::UTC>(tt);
    std::cout << "utc.jdInt() = " << std::setprecision(17) <<  utc.jdInt() << std::endl;
    std::cout << "utc.jdFrac() = " << std::setprecision(17) <<  utc.jdFrac() << std::endl;

    const auto ut1 = coordinatesConverter.timeConverter().convert<Scale::UT1>(tt);
    std::cout << "ut1.jdInt() = " << std::setprecision(17) <<  ut1.jdInt() << std::endl;
    std::cout << "ut1.jdFrac() = " << std::setprecision(17) <<  ut1.jdFrac() << std::endl;

    std::cout << std::setprecision(17) << "dX = " << EOPcontainer.dX(utc.mjd()) << std::endl;
    std::cout << std::setprecision(17) << "dY = " << EOPcontainer.dY(utc.mjd()) << std::endl;
    std::cout << std::setprecision(17) << "xp = " << EOPcontainer.xTerr(utc.mjd()) << std::endl;
    std::cout << std::setprecision(17) << "yp = " << EOPcontainer.yTerr(utc.mjd()) << std::endl;

    std::cout << std::endl;

    Eigen::Matrix<double, 3, 3> gcrs2cirs = coordinatesConverter.GCRStoCIRS(utc);
    std::cout << "GCRS to CIRS (precession & nutation) matrix:" << std::endl;
    std::cout << std::setprecision(17) << gcrs2cirs << std::endl;

    std::cout << std::endl;

    Eigen::Matrix<double, 3, 3> cirs2tirs = coordinatesConverter.rotateCIRStoTIRS(utc).toRotationMatrix();
    std::cout << "CIRS to TIRS (intrinsic rotation) matrix:" << std::endl;
    std::cout << std::setprecision(17) << cirs2tirs << std::endl;

    std::cout << std::endl;

    Eigen::Matrix<double, 3, 3> tirs2itrs = coordinatesConverter.PolarMotion(utc).toRotationMatrix();
    std::cout << "TIRS to ITRS (polar motion) matrix:" << std::endl;
    std::cout << std::setprecision(17) << tirs2itrs << std::endl;

    std::cout << std::endl;

    Eigen::Matrix<double, 3, 3> gcrs2itrs = coordinatesConverter.GCRStoITRS(utc);
    std::cout << "GCRS to ITRS matrix:" << std::endl;
    std::cout << std::setprecision(17) << gcrs2cirs << std::endl;

    std::cout << std::endl;

    Eigen::Matrix<double, 3, 3> result = coordinatesConverter.GCRS2ITRS(utc);
    std::cout << "rc2t matrix:" << std::endl;
    std::cout << std::setprecision(17) << result << std::endl;

    return 0;
}
