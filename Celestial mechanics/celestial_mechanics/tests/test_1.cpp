#include <gtest/gtest.h>
#include <time/Time.hpp>

class TimeTest : public testing::Test {
    protected:
        int iy, im, id, ihour, imin;
        double sec, jd, mjd;
        Time<Scale::UT1> JD;

        int iy_2, im_2, id_2, ihour_2, imin_2;
        double sec_2, jd_2, mjd_2;
        Time<Scale::UT1> JD_2;

        double delta;

        void SetUp() {
            iy = 2008; im = 2; id = 29;
            ihour = 23; imin = 59; sec = 59.9;
            jd = 2454526.499999; mjd = 54525.999999;

            iy_2 = 2008; im_2 = 3; id_2 = 1;
            ihour_2 = 5; imin_2 = 59; sec_2 = 59.9;
            jd_2 = 2454526.749999; mjd_2 = 54526.249999;

            delta = 0.25;
        }
};

TEST_F(TimeTest, fromJDWorks) {
    JD = Time<Scale::UT1>::fromJD(jd);
    EXPECT_EQ(JD.jdInt(), 2454526);
    EXPECT_NEAR(JD.jdFrac(), 0.499999, 1e-6);
    EXPECT_NEAR(JD.jd(), 2454526.499999, 1e-6);
    EXPECT_NEAR(JD.mjd(), 54525.999999, 1e-6);

    JD_2 = Time<Scale::UT1>::fromJD(jd_2);
    EXPECT_EQ(JD_2.jdInt(), 2454526);
    EXPECT_NEAR(JD_2.jdFrac(), 0.749999, 1e-6);
    EXPECT_NEAR(JD_2.jd(), 2454526.749999, 1e-6);
    EXPECT_NEAR(JD_2.mjd(), 54526.249999, 1e-6);
}

TEST_F(TimeTest, fromMJDWorks) {
    JD = Time<Scale::UT1>::fromMJD(mjd);
    EXPECT_EQ(JD.jdInt(), 2454526);
    EXPECT_NEAR(JD.jdFrac(), 0.499999, 1e-6);
    EXPECT_NEAR(JD.jd(), 2454526.499999, 1e-6);
    EXPECT_NEAR(JD.mjd(), 54525.999999, 1e-6);

    JD_2 = Time<Scale::UT1>::fromMJD(mjd_2);
    EXPECT_EQ(JD_2.jdInt(), 2454526);
    EXPECT_NEAR(JD_2.jdFrac(), 0.749999, 1e-6);
    EXPECT_NEAR(JD_2.jd(), 2454526.749999, 1e-6);
    EXPECT_NEAR(JD_2.mjd(), 54526.249999, 1e-6);
}

TEST_F(TimeTest, fromCalendarWorks) {
    JD = Time<Scale::UT1>::fromCalendar(iy, im, id, ihour, imin, sec);
    EXPECT_EQ(JD.jdInt(), 2454526);
    EXPECT_NEAR(JD.jdFrac(), 0.499999, 1e-6);
    EXPECT_NEAR(JD.jd(), 2454526.499999, 1e-6);
    EXPECT_NEAR(JD.mjd(), 54525.999999, 1e-6);

    JD_2 = Time<Scale::UT1>::fromCalendar(iy_2, im_2, id_2, ihour_2, imin_2, sec_2);
    EXPECT_EQ(JD_2.jdInt(), 2454526);
    EXPECT_NEAR(JD_2.jdFrac(), 0.749999, 1e-6);
    EXPECT_NEAR(JD_2.jd(), 2454526.749999, 1e-6);
    EXPECT_NEAR(JD_2.mjd(), 54526.249999, 1e-6);
}

TEST_F(TimeTest, comparisonWorks) {
    JD = Time<Scale::UT1>::fromJD(jd); JD_2 = Time<Scale::UT1>::fromJD(jd_2);
    EXPECT_TRUE(JD == JD);
    EXPECT_TRUE(JD <= JD);
    EXPECT_TRUE(JD >= JD);
    EXPECT_FALSE(JD > JD);
    EXPECT_FALSE(JD < JD);

    EXPECT_TRUE(JD <= JD_2);
    EXPECT_TRUE(JD < JD_2);
    EXPECT_FALSE(JD >= JD_2);
    EXPECT_FALSE(JD > JD_2);
    EXPECT_FALSE(JD == JD_2);
}

TEST_F(TimeTest, operatorsWork) {
    JD = Time<Scale::UT1>::fromJD(jd); JD_2 = Time<Scale::UT1>::fromJD(jd_2);
    EXPECT_NEAR(JD_2 - JD, 0.25, 1e-12);
    EXPECT_TRUE(JD + 0.25 == JD_2);
    EXPECT_TRUE(std::abs((JD_2 - 0.25) - JD) <= 1e-6);
    EXPECT_TRUE(JD_2 - 0.25 == JD);
}