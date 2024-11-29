#include <gtest/gtest.h>
#include "celestial_mechanics/coordinates/ReferenceSystemConverter.hpp"
#include "celestial_mechanics/coordinates/EOPContainer.hpp"
#include "celestial_mechanics/time/Time.hpp"
#include "celestial_mechanics/time/DutContainer.hpp"
#include "celestial_mechanics/time/TimeConverter.hpp"
#include <Core>
#include <iostream>

class ReferenceSystemConverterTestFromSOFA : public testing::Test {
    protected:
        Time<Scale::UTC> utc = Time<Scale::UTC>::fromCalendar(2007, 4, 5, 12, 0, 0.0);
        const double das2r = 4.848136811095359935899141e-6;
        const double dmas2r = das2r / 1e3;
        EOPContainer EOPcontainer = EOPContainer({utc.mjd()}, {-0.072073685},
                                        {0.1750 * dmas2r}, {-0.2259 * dmas2r},
                                        {0.0349282 * das2r}, {0.4833163 * das2r});
        ReferenceSystemConverter coordinatesConverter = ReferenceSystemConverter(EOPcontainer);
};

TEST_F(ReferenceSystemConverterTestFromSOFA, GCRStoCIRSworks) {
    const auto celestial2intermediate = coordinatesConverter.GCRStoCIRS(utc);
    Eigen::Matrix<double, 3, 3> NPB {{+0.999999746339445, -0.000000005138822, -0.000712264729999},
                                    {-0.000000026475226, +0.999999999014975, -0.000044385241276},
                                    {+0.000712264729525, +0.000044385248875, +0.999999745354420}};
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            ASSERT_NEAR(celestial2intermediate(i, j), NPB(i, j), 1e-15);
}

TEST_F(ReferenceSystemConverterTestFromSOFA, rotateCIRStoTIRSworks) {
    const Eigen::Quaternion<double> intermediate2terrestrial = coordinatesConverter.rotateCIRStoTIRS(utc);
    std::cout << intermediate2terrestrial << std::endl;
    const Eigen::Matrix<double, 3, 3> myR = intermediate2terrestrial.toRotationMatrix();
    const auto ut1 = coordinatesConverter.timeConverter().convert<Scale::UT1>(utc);
    const auto era = iauEra00(ut1.jdInt(), ut1.jdFrac());
    double R[3][3] = {{1, 0, 0}, {0,1,0}, {0,0,1}};
    iauRz(era, R);
    std::cout << era << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            std::cout << R[i][j] << " ";
        std::cout << std::endl;
    }
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            ASSERT_NEAR(myR(i, j), R[i][j], 1e-15);
        }
}

TEST_F(ReferenceSystemConverterTestFromSOFA, GCRStoTIRSworks) {
    Eigen::Matrix<double, 3, 3> celestial2terrestrial = coordinatesConverter.GCRStoTIRS(utc).toRotationMatrix();
    Eigen::Matrix<double, 3, 3> withoutPolarMotion {{+0.973104317573127, +0.230363826247709, -0.000703332818416},
                                    {-0.230363798804181, +0.973104570735574, +0.000120888551078},
                                    {+0.000712264729525, +0.000044385248875, +0.999999745354420}};
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            std::cout << std::setprecision(15) << celestial2terrestrial(i, j) << " ";
        std::cout << std::endl;
    }
    
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            ASSERT_NEAR(celestial2terrestrial(i, j), withoutPolarMotion(i, j), 1e-14);
        }
}

TEST_F(ReferenceSystemConverterTestFromSOFA, GCRStoITRSworks) {
    Eigen::Matrix<double, 3, 3> gcrs2itrs = coordinatesConverter.GCRStoITRS(utc);
    Eigen::Matrix<double, 3, 3> withPolarMotion {{+0.973104317697536, +0.230363826239128, -0.000703163481769},
                                                {-0.230363800456036, +0.973104570632801, +0.000118545368117},
                                                {+0.000711560162594 ,+0.000046626402444, +0.999999745754024}};
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            ASSERT_NEAR(gcrs2itrs(i, j), withPolarMotion(i, j), 1e-14);
        }
}

TEST_F(ReferenceSystemConverterTestFromSOFA, GCRS2ITRSworks) {
    Eigen::Matrix<double, 3, 3> rc2i = coordinatesConverter.GCRS2ITRS(utc);
    Eigen::Matrix<double, 3, 3> rc2i_true {{+0.973104317697536, +0.230363826239128, -0.000703163481769},
                                                {-0.230363800456036, +0.973104570632801, +0.000118545368117},
                                                {+0.000711560162594 ,+0.000046626402444, +0.999999745754024}};
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            ASSERT_NEAR(rc2i(i, j), rc2i_true(i, j), 1e-14);
        }
}