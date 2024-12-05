#include <gtest/gtest.h>
#include "celestial_mechanics/coordinates/ReferenceSystemConverter.hpp"
#include "celestial_mechanics/coordinates/EOPContainer.hpp"
#include "celestial_mechanics/time/Time.hpp"
#include "celestial_mechanics/time/TimeConverter.hpp"
#include <Core>
#include <iomanip>
#include <iostream>

int main() {
    EOPContainer EOPcontainer = EOPContainer::buildFromFile("/Users/elinamukhamedova/Desktop/C++/Elina_5sem/Celestial mechanics/celestial_mechanics/resources/earth_rotation.csv");
    ReferenceSystemConverter coordinatesConverter = ReferenceSystemConverter(EOPcontainer);
    TimeConverter<EOPContainer> timeConverter = TimeConverter<EOPContainer>(EOPcontainer);

    Eigen::Vector<double, 3> r_GCRS{6700e3, 0, 0};
    
    const auto tt = Time<Scale::TT>::fromCalendar(2019, 9, 13, 12, 45, 0);
    std::cout << "tt.jdInt() = " << std::setprecision(17) <<  tt.jdInt() << std::endl;
    std::cout << "tt.jdFrac() = " << std::setprecision(17) <<  tt.jdFrac() << std::endl;
    
    const auto utc = timeConverter.convert<Scale::UTC>(tt);
    std::cout << "utc.jdInt() = " << std::setprecision(17) <<  utc.jdInt() << std::endl;
    std::cout << "utc.jdFrac() = " << std::setprecision(17) <<  utc.jdFrac() << std::endl;

    const auto ut1 = timeConverter.convert<Scale::UT1>(tt);
    std::cout << "ut1.jdInt() = " << std::setprecision(17) <<  ut1.jdInt() << std::endl;
    std::cout << "ut1.jdFrac() = " << std::setprecision(17) <<  ut1.jdFrac() << std::endl;

    std::cout << std::setprecision(17) << "dX = " << EOPcontainer.dX(utc.mjd()) << std::endl;
    std::cout << std::setprecision(17) << "dY = " << EOPcontainer.dY(utc.mjd()) << std::endl;
    std::cout << std::setprecision(17) << "xp = " << EOPcontainer.xTerr(utc.mjd()) << std::endl;
    std::cout << std::setprecision(17) << "yp = " << EOPcontainer.yTerr(utc.mjd()) << std::endl;

    Eigen::Matrix<double, 3, 3> result = coordinatesConverter.GCRS2ITRS(tt);
    std::cout << "rc2t matrix:" << std::endl;
    std::cout << std::setprecision(17) << result << std::endl;

    return 0;
}
