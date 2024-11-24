#include <gtest/gtest.h>
#include "celestial_mechanics/time/Time.hpp"
#include "celestial_mechanics/time/DutContainer.hpp"
#include "celestial_mechanics/time/TimeConverter.hpp"
#include "tests/Paths.hpp"
#include "resources/time_2019_2020_result.hpp"
#include <cmath>
#include <iostream>

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

TEST_F(TimeConverterTest, UT1toTT) {
    for (auto el : timeResult) {
        const auto ut1 = Time<Scale::UT1>(el[1], el[2]);
        const auto tt_fromUT1 = timeConverter.convert<Scale::TT>(ut1);
        const auto tt_true = Time<Scale::TT>(el[7], el[8]);

        if (std::abs(el[8]) == 0.5)
            ASSERT_NEAR(std::abs(tt_fromUT1.jdFrac()), 0.5, 1e-15);
        else {
            ASSERT_NEAR(tt_fromUT1.jdInt(), el[7], 1e-15);
            ASSERT_NEAR(tt_fromUT1.jdFrac(), el[8], 1e-15);
        }
    }
}

TEST_F(TimeConverterTest, TTtoUT1) {
    for (auto el : timeResult) {
        const auto tt = Time<Scale::TT>(el[7], el[8]);
        const auto ut1_fromTT = timeConverter.convert<Scale::UT1>(tt);
        ASSERT_DOUBLE_EQ(ut1_fromTT.jdInt(), el[1]);
        ASSERT_DOUBLE_EQ(ut1_fromTT.jdFrac(), el[2]);
    }
}

TEST_F(TimeConverterTest, UTCtoTT) {
    for (auto el : timeResult) {
        const auto utc = Time<Scale::UTC>(el[3], el[4]);
        const auto tt_fromUTC = timeConverter.convert<Scale::TT>(utc);
        
        if (std::abs(el[8]) == 0.5)
            ASSERT_NEAR(std::abs(tt_fromUTC.jdFrac()), 0.5, 1e-17);
        else {
            ASSERT_NEAR(tt_fromUTC.jdInt(), el[7], 1e-17);
            ASSERT_NEAR(tt_fromUTC.jdFrac(), el[8], 1e-17);
        }
    }
}

TEST_F(TimeConverterTest, TTtoUTC) {
    for (auto el : timeResult) {
        const auto tt = Time<Scale::TT>(el[7], el[8]);
        const auto utc_fromTT = timeConverter.convert<Scale::UTC>(tt);
        const auto utc_true = Time<Scale::UTC>(el[3], el[4]);

        ASSERT_TRUE(utc_fromTT == utc_true);
        ASSERT_DOUBLE_EQ(utc_fromTT.jdInt(), el[3]);
        ASSERT_DOUBLE_EQ(utc_fromTT.jdFrac(), el[4]);
    }
}

TEST_F(TimeConverterTest, TTtoTCG) {
    for (auto el : timeResult) {
        const auto tt = Time<Scale::TT>(el[7], el[8]);
        const auto tcg_fromTT = timeConverter.convert<Scale::TCG>(tt);

        ASSERT_DOUBLE_EQ(tcg_fromTT.jdInt(), el[9]);
        ASSERT_DOUBLE_EQ(tcg_fromTT.jdFrac(), el[10]);
    }
}

TEST_F(TimeConverterTest, TCGtoTT) {
    for (auto el : timeResult) {
        const auto tcg = Time<Scale::TCG>(el[9], el[10]);
        const auto tt_fromTCG = timeConverter.convert<Scale::TT>(tcg);

        if (std::abs(el[8]) == 0.5)
            ASSERT_NEAR(std::abs(tt_fromTCG.jdFrac()), 0.5, 1e-16);
        else {
            ASSERT_NEAR(tt_fromTCG.jdInt(), el[7], 1e-16);
            ASSERT_NEAR(tt_fromTCG.jdFrac(), el[8], 1e-16);
        }
    }
}

TEST_F(TimeConverterTest, UT1toTCG) {
    for (auto el : timeResult) {
        const auto ut1 = Time<Scale::UT1>(el[1], el[2]);
        const auto tcg_fromUT1 = timeConverter.convert<Scale::TCG>(ut1);

        ASSERT_NEAR(tcg_fromUT1.jdInt(), el[9], 1e-15);
        ASSERT_NEAR(tcg_fromUT1.jdFrac(), el[10], 1e-15);
    }
}

TEST_F(TimeConverterTest, TCGtoUT1) {
    for (auto el : timeResult) {
        const auto tcg = Time<Scale::TCG>(el[9], el[10]);
        const auto ut1_fromTCG = timeConverter.convert<Scale::UT1>(tcg);

        ASSERT_NEAR(ut1_fromTCG.jdInt(), el[1], 1e-16);
        ASSERT_NEAR(ut1_fromTCG.jdFrac(), el[2], 1e-16);
    }
}