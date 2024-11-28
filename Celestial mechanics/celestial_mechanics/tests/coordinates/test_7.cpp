#include <gtest/gtest.h>
#include "celestial_mechanics/coordinates/ReferenceSystemConverter.hpp"
#include "celestial_mechanics/coordinates/EOPContainer.hpp"
#include "celestial_mechanics/time/Time.hpp"
#include "celestial_mechanics/time/TimeConverter.hpp"
#include <Core>
#include "tests/Paths.hpp"
#include "resources/coordinates_result.hpp"

class ReferenceSystemConverterTest : public testing::Test {
    protected:
        EOPContainer EOPcontainer = EOPContainer(resourcesPath() / "earth_rotation.csv");
        ReferenceSystemConverter coordinatesConverter = ReferenceSystemConverter(EOPcontainer);
};

TEST_F(ReferenceSystemConverterTest, 6700e3x_GCRStoITRSworks) {

    Eigen::Vector<double, 3> r_GCRS{6700e3, 0, 0};

    for (auto el : earthRotationResult) {

        double jd = el[0];
        const auto tt = Time<Scale::TT>::fromJD(jd);
        const auto utc = coordinatesConverter.timeConverter().convert<Scale::UTC>(tt);

        Eigen::Matrix<double, 3, 3> gcrs2itrs = coordinatesConverter.GCRStoITRS(utc);
        std::cout << gcrs2itrs << std::endl;
        std::cout << r_GCRS << std::endl;
        Eigen::Vector<double, 3> r_ITRS = gcrs2itrs * r_GCRS;
        std::cout << r_ITRS << std::endl;
        ASSERT_NEAR(r_ITRS(0), el[1], 1e-8);
        ASSERT_NEAR(r_ITRS(1), el[2], 1e-8);
        ASSERT_NEAR(r_ITRS(2), el[3], 1e-8);
    }
}