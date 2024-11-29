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

TEST_F(ReferenceSystemConverterTest, 6700e3x_GCRS2ITRSworks) {

    Eigen::Vector<double, 3> r_GCRS{6700e3, 0, 0};

    for (auto el : earthRotationResult) {

        double ttJD = el[0];
        const auto tt = Time<Scale::TT>::fromJD(ttJD);
        const auto utc = coordinatesConverter.timeConverter().convert<Scale::UTC>(tt);

        Eigen::Matrix<double, 3, 3> gcrs2itrs = coordinatesConverter.GCRS2ITRS(utc);
        Eigen::Vector<double, 3> r_ITRS = gcrs2itrs * r_GCRS;

        ASSERT_NEAR(r_ITRS(0), el[1], 0.1);
        ASSERT_NEAR(r_ITRS(1), el[2], 0.1);
        ASSERT_NEAR(r_ITRS(2), el[3], 0.1);

        ASSERT_NEAR((r_ITRS(0) - el[1]) / el[1], 0, 1e-5);
        ASSERT_NEAR((r_ITRS(1) - el[2]) / el[2], 0, 1e-5);
        ASSERT_NEAR((r_ITRS(2) - el[3]) / el[3], 0, 1e-5);
    }
}

TEST_F(ReferenceSystemConverterTest, 6700e3y_GCRS2ITRSworks) {

    Eigen::Vector<double, 3> r_GCRS{0, 6700e3, 0};

    for (auto el : earthRotationResult) {

        double ttJD = el[0];
        const auto tt = Time<Scale::TT>::fromJD(ttJD);
        const auto utc = coordinatesConverter.timeConverter().convert<Scale::UTC>(tt);

        Eigen::Matrix<double, 3, 3> gcrs2itrs = coordinatesConverter.GCRS2ITRS(utc);
        Eigen::Vector<double, 3> r_ITRS = gcrs2itrs * r_GCRS;

        ASSERT_NEAR(r_ITRS(0), el[4], 0.1);
        ASSERT_NEAR(r_ITRS(1), el[5], 0.1);
        ASSERT_NEAR(r_ITRS(2), el[6], 0.1);
    }
}

TEST_F(ReferenceSystemConverterTest, 6700e3z_GCRS2ITRSworks) {

    Eigen::Vector<double, 3> r_GCRS{0, 0, 6700e3};

    for (auto el : earthRotationResult) {

        double ttJD = el[0];
        const auto tt = Time<Scale::TT>::fromJD(ttJD);
        const auto utc = coordinatesConverter.timeConverter().convert<Scale::UTC>(tt);

        Eigen::Matrix<double, 3, 3> gcrs2itrs = coordinatesConverter.GCRS2ITRS(utc);
        Eigen::Vector<double, 3> r_ITRS = gcrs2itrs * r_GCRS;

        ASSERT_NEAR(r_ITRS(0), el[7], 0.1);
        ASSERT_NEAR(r_ITRS(1), el[8], 0.1);
        ASSERT_NEAR(r_ITRS(2), el[9], 0.1);
    }
}