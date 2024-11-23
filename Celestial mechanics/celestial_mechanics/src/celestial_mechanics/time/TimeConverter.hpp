#pragma once

#include <sofa.h>
#include "Time.hpp"
#include "Exception.hpp"

template <typename DutContainer>
class TimeConverter {
    DutContainer dutContainer_;
    public:
        TimeConverter (const DutContainer& dutContainer) : dutContainer_(dutContainer) {};
        template<Scale To, Scale From> Time<To> convert(const Time<From>& from) const;

        template<> Time<Scale::UT1> convert<Scale::UT1, Scale::UTC>(const Time<Scale::UTC>& from) const {
            double ut11, ut12;
            double dut = dutContainer_.dut(from.mjd());
            int j = iauUtcut1(from.jdInt(), from.jdFrac(), dut, &ut11, &ut12);
            switch (j) {
                case -1:
                    throw Exception("unacceptable date");
                default:
                    return Time<Scale::UT1>(ut11, ut12);
            }
        }

        template<> Time<Scale::UTC> convert<Scale::UTC, Scale::UT1>(const Time<Scale::UT1>& from) const {
            const auto ut1_jdInt = from.jdInt();
            const auto ut1_jdFrac = from.jdFrac();
            
            const auto utc_0 = Time<Scale::UTC>(ut1_jdInt, ut1_jdFrac);
            const auto dut_0 = dutContainer_.dut(utc_0.mjd());

            double quasi1_1, quasi2_1;
            int j = iauUt1utc(ut1_jdInt, ut1_jdFrac, dut_0, &quasi1_1, &quasi2_1);
            if (j == -1)
                throw Exception("unacceptable date");
            const auto utc_1 = Time<Scale::UTC>(quasi1_1, quasi2_1);

            double quasi1_2, quasi2_2;
            const auto dut_1 = dutContainer_.dut(utc_1.mjd());
            j = iauUt1utc(ut1_jdInt, ut1_jdFrac, dut_1, &quasi1_2, &quasi2_2);
            if (j == -1)
                throw Exception("unacceptable date");
            const auto utc_2 = Time<Scale::UTC>(quasi1_2, quasi2_2);

            double quasi1_3, quasi2_3;
            const auto dut_2 = dutContainer_.dut(utc_2.mjd());
            j = iauUt1utc(ut1_jdInt, ut1_jdFrac, dut_2, &quasi1_3, &quasi2_3);
            if (j == -1)
                throw Exception("unacceptable date");
            const auto utc_3 = Time<Scale::UTC>(quasi1_3, quasi2_3);

            return utc_3;
        }

        template<> Time<Scale::TAI> convert<Scale::TAI, Scale::UTC>(const Time<Scale::UTC>& from) const {
            double tai1, tai2;
            int j = iauUtctai(from.jdInt(), from.jdFrac(), &tai1, &tai2);
            if (j == -1)
                throw Exception("unacceptable date");
            return Time<Scale::TAI>(tai1, tai2);
        }

        template<> Time<Scale::UTC> convert<Scale::UTC, Scale::TAI>(const Time<Scale::TAI>& from) const {
            double utc1, utc2;
            int j = iauTaiutc(from.jdInt(), from.jdFrac(), &utc1, &utc2);
            if (j == -1)
                throw Exception("unacceptable date");
            return Time<Scale::UTC>(utc1, utc2);
        }
};