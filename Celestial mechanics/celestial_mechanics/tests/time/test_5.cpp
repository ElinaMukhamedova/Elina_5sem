#include <gtest/gtest.h>
#include "celestial_mechanics/time/Time.hpp"
#include "celestial_mechanics/time/DutContainer.hpp"
#include "celestial_mechanics/time/TimeConverter.hpp"
#include "tests/Paths.hpp"
#include "resources/time_2019_2020_result.hpp"
#include <iostream>
#include <cmath>

class TimeConverterTest : public testing::Test {
    protected:
        DutContainer dutContainer = DutContainer(resourcesPath() / "earth_rotation.csv", ',', "mjd", "UT1-UTC s");
        TimeConverter<DutContainer> timeConverter = TimeConverter<DutContainer>(dutContainer);
};

TEST_F(TimeConverterTest, UTCtoUT1_testFromSOFA) {
    const auto utc = Time<Scale::UTC>::fromCalendar(2006, 1, 15, 21, 4, 37.5);
    const auto ut1_fromUTC = timeConverter.convert<Scale::UT1>(utc);
    const auto ut1 = Time<Scale::UT1>::fromCalendar(2006, 1, 15, 21, 4, 37.8341);
    ASSERT_NEAR(ut1_fromUTC.mjd(), ut1.mjd(), 1e-6);
}

TEST_F(TimeConverterTest, UTCtoUT1) {
    for (auto el : timeResult) {
        const auto utc = Time<Scale::UTC> (el[3], el[4]);
        const auto ut1_fromUTC = timeConverter.convert<Scale::UT1>(utc);
        ASSERT_DOUBLE_EQ(ut1_fromUTC.jdInt(), el[1]);
        ASSERT_DOUBLE_EQ(ut1_fromUTC.jdFrac(), el[2]);
    }
}

TEST_F(TimeConverterTest, UT1toUTC) {
    for (auto el : timeResult) {
        const auto ut1 = Time<Scale::UT1> (el[1], el[2]);
        const auto utc_fromUT1 = timeConverter.convert<Scale::UTC>(ut1);
        ASSERT_NEAR(utc_fromUT1.jdInt(), el[3], 1e-15);
        ASSERT_NEAR(utc_fromUT1.jdFrac(), el[4], 1e-15);
    }
}

TEST_F(TimeConverterTest, UTCtoTAI) {
    for (auto el : timeResult) {
        const auto utc = Time<Scale::UTC> (el[3], el[4]);
        const auto tai_fromUTC = timeConverter.convert<Scale::TAI>(utc);
        ASSERT_NEAR(tai_fromUTC.jdInt(), el[5], 1e-17);
        ASSERT_NEAR(tai_fromUTC.jdFrac(), el[6], 1e-17);
    }
}

TEST_F(TimeConverterTest, TAItoUTC) {
    for (auto el : timeResult) {
        const auto tai = Time<Scale::TAI> (el[5], el[6]);
        const auto utc_fromTAI = timeConverter.convert<Scale::UTC>(tai);
        ASSERT_DOUBLE_EQ(utc_fromTAI.jdInt(), el[3]);
        ASSERT_DOUBLE_EQ(utc_fromTAI.jdFrac(), el[4]);
    }
}

TEST_F(TimeConverterTest, TAItoUT1) {
    for (auto el : timeResult) {
        const auto tai = Time<Scale::TAI> (el[5], el[6]);
        const auto ut1_fromTAI = timeConverter.convert<Scale::UT1>(tai);
        ASSERT_DOUBLE_EQ(ut1_fromTAI.jdInt(), el[1]);
        ASSERT_DOUBLE_EQ(ut1_fromTAI.jdFrac(), el[2]);
    }
}

TEST_F(TimeConverterTest, UT1toTAI) {
    for (auto el : timeResult) {
        const auto ut1 = Time<Scale::UT1>(el[1], el[2]);
        const auto tai_fromUT1 = timeConverter.convert<Scale::TAI>(ut1);
        ASSERT_NEAR(tai_fromUT1.jdInt(), el[5], 1e-15);
        ASSERT_NEAR(tai_fromUT1.jdFrac(), el[6], 1e-15);
    }
}

TEST_F(TimeConverterTest, TAItoTT) {
    for (auto el : timeResult) {
        const auto tai = Time<Scale::TAI>(el[5], el[6]);
        const auto tt_fromTAI = timeConverter.convert<Scale::TT>(tai);

        ASSERT_DOUBLE_EQ(tt_fromTAI.jd(), el[7] + el[8]);


        const auto tt_true = Time<Scale::TT>(el[7], el[8]);
        ASSERT_TRUE(tt_fromTAI == tt_true);

        if (std::abs(el[8]) == 0.5)
            ASSERT_DOUBLE_EQ(std::abs(tt_fromTAI.jdFrac()), 0.5);
        else {
            ASSERT_DOUBLE_EQ(tt_fromTAI.jdInt(), el[7]);
            ASSERT_DOUBLE_EQ(tt_fromTAI.jdFrac(), el[8]);
        }
    }
}

TEST_F(TimeConverterTest, TTtoTAI) {
    for (auto el : timeResult) {
        const auto tt = Time<Scale::TT>(el[7], el[8]);
        const auto tai_fromTT = timeConverter.convert<Scale::TAI>(tt);

        ASSERT_DOUBLE_EQ(tai_fromTT.jd(), el[5] + el[6]);

        const auto tai_true = Time<Scale::TAI>(el[5], el[6]);
        ASSERT_TRUE(tai_fromTT == tai_true);

        ASSERT_DOUBLE_EQ(tai_fromTT.jdInt(), el[5]);
        ASSERT_DOUBLE_EQ(tai_fromTT.jdFrac(), el[6]);
    }
}