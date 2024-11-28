#include <gtest/gtest.h>
#include "celestial_mechanics/coordinates/ReferenceSystemConverter.hpp"
#include "celestial_mechanics/coordinates/EOPContainer.hpp"
#include "celestial_mechanics/time/Time.hpp"
#include "celestial_mechanics/time/DutContainer.hpp"
#include "celestial_mechanics/time/TimeConverter.hpp"
#include <Core>
#include <iostream>

TEST(ReferenceSystemConverterTest, GCRStoCIRSworks) {
    const auto utc = Time<Scale::UTC>::fromCalendar(2007, 4, 5, 12, 0, 0.0);
    const double das2r = 4.848136811095359935899141e-6;
    const double dmas2r = das2r / 1e3;
    auto EOPcontainer = EOPContainer({utc.mjd()}, {-0.072073685},
                                        {0.1750 * dmas2r}, {-0.2259 * dmas2r},
                                        {0.0349282 * das2r}, {0.4833163 * das2r});
    auto coordinatesConverter = ReferenceSystemConverter(EOPcontainer);
    const auto celestial2intermediate = coordinatesConverter.GCRStoCIRS(utc);
    Eigen::Matrix<double, 3, 3> NPB {{+0.999999746339445, -0.000000005138822, -0.000712264729999},
                                    {-0.000000026475226, +0.999999999014975, -0.000044385241276},
                                    {+0.000712264729525, +0.000044385248875, +0.999999745354420}};
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            ASSERT_NEAR(celestial2intermediate(i, j), NPB(i, j), 1e-15);
}