#include <gtest/gtest.h>
#include <time/Time.hpp>

class TimeTest : public testing::Test {
    protected:
        int iy, im, id, ihour, imin;
        double sec, jd, mjd;
        Time JD;

        int iy_2, im_2, id_2, ihour_2, imin_2;
        double sec_2, jd_2, mjd_2;
        Time JD_2;

        double delta;

        TimeTest() {
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
    JD = Time::fromJD(jd);
    EXPECT_EQ(JD.jdInt(), 2454526);
    EXPECT_NEAR(JD.jdFrac(), 0.499999, 0.000001);
    EXPECT_NEAR(JD.jd(), 2454526.499999, 0.000001);
    EXPECT_NEAR(JD.mjd(), 54525.999999, 0.000001);

    JD_2 = Time::fromJD(jd_2);
    EXPECT_EQ(JD_2.jdInt(), 2454526);
    EXPECT_NEAR(JD_2.jdFrac(), 0.749999, 0.000001);
    EXPECT_NEAR(JD_2.jd(), 2454526.749999, 0.000001);
    EXPECT_NEAR(JD_2.mjd(), 54526.249999, 0.000001);
}

TEST_F(TimeTest, fromMJDWorks) {
    JD = Time::fromMJD(mjd);
    EXPECT_EQ(JD.jdInt(), 2454526);
    EXPECT_NEAR(JD.jdFrac(), 0.499999, 0.000001);
    EXPECT_NEAR(JD.jd(), 2454526.499999, 0.000001);
    EXPECT_NEAR(JD.mjd(), 54525.999999, 0.000001);

    JD_2 = Time::fromMJD(mjd_2);
    EXPECT_EQ(JD_2.jdInt(), 2454526);
    EXPECT_NEAR(JD_2.jdFrac(), 0.749999, 0.000001);
    EXPECT_NEAR(JD_2.jd(), 2454526.749999, 0.000001);
    EXPECT_NEAR(JD_2.mjd(), 54526.249999, 0.000001);
}

TEST_F(TimeTest, fromCalendarWorks) {
    JD = Time::fromCalendar(iy, im, id, ihour, imin, sec);
    EXPECT_EQ(JD.jdInt(), 2454526);
    EXPECT_NEAR(JD.jdFrac(), 0.499999, 0.000001);
    EXPECT_NEAR(JD.jd(), 2454526.499999, 0.000001);
    EXPECT_NEAR(JD.mjd(), 54525.999999, 0.000001);

    JD_2 = Time::fromCalendar(iy_2, im_2, id_2, ihour_2, imin_2, sec_2);
    EXPECT_EQ(JD_2.jdInt(), 2454526);
    EXPECT_NEAR(JD_2.jdFrac(), 0.749999, 0.000001);
    EXPECT_NEAR(JD_2.jd(), 2454526.749999, 0.000001);
    EXPECT_NEAR(JD_2.mjd(), 54526.249999, 0.000001);
}

TEST_F(TimeTest, comparisonWorks) {
    JD = Time::fromJD(jd); JD_2 = Time::fromJD(jd_2);
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
