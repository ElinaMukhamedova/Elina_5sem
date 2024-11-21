#include <gtest/gtest.h>
#include "celestial_mechanics/time/Time.hpp"
#include "celestial_mechanics/time/DutContainer.hpp"
#include "celestial_mechanics/time/TimeConverter.hpp"
#include "tests/Paths.hpp"
#include "resources/time_2019_2020_result.hpp"

class TimeConverterTest : public testing::Test {
    protected:
        DutContainer dutContainer;
        TimeConverter<DutContainer> timeConverter;

        void SetUp() {
            dutContainer = DutContainer(resourcesPath() / "earth_rotation.csv", ',', "mjd", "UT1-UTC s");
            timeConverter = TimeConverter<DutContainer>(dutContainer);
        }
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