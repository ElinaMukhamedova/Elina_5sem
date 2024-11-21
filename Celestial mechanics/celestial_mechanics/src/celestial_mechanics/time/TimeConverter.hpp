#pragma once

#include <sofa.h>
#include "Time.hpp"
#include "Exception.hpp"

template <typename DutContainer>
class TimeConverter {
    DutContainer dutContainer_;
    public:
        TimeConverter() {}
        TimeConverter (const DutContainer& dutContainer) : dutContainer_(dutContainer) {};
        template<Scale To, Scale From> Time<To> convert(const Time<From>& from) const;

        template<> Time<Scale::UT1> convert<Scale::UT1, Scale::UTC>(const Time<Scale::UTC>& from) const {
            double ut11, ut12;
            double dut = dutContainer_.dut(from.mjd());
            int j = iauUtcut1(from.jdInt(), from.jdFrac(), dut, &ut11, &ut12);
            switch (j) {
                case 1:
                    throw Exception("dubious year");
                case -1:
                    throw Exception("unacceptable date");
                default:
                    return Time<Scale::UT1>(ut11, ut12);
            }
        }
};