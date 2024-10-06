#include <cmath>
#include "Time.hpp"
#include <sofa/sofa.h>

Time::Time(double jd1, double jd2) {
    double jd1_int;
    double jd1_frac = std::modf(jd1, &jd1_int);
    double jd2_int;
    double jd2_frac = std::modf(jd2, &jd2_int);
    jdInt_ = jd1_int + jd2_int;
    jdFrac_ = jd1_frac + jd2_frac;
}

Time Time::fromJD(double jd) noexcept {
    double jd_int;
    double jd_frac = std::modf(jd, &jd_int);
    return Time(jd_int, jd_frac);
}

Time Time::fromMJD(double mjd) noexcept {
    return fromJD(mjd + 2400000.5);
}

Time Time::fromCalendar(int year, int month, int day) {
    double djm0;
    double djm;
    int result = sofa::iauCal2jd(year, month, day, &djm0, &djm);
    switch (result) {
        case -1:
            throw Time::Exception("bad year (JD not computed)");
        case -2:
            throw Time::Exception("bad month (JD not computed)");
        case -3:
            throw Time::Exception("bad day (JD not computed)");
        default:
            return Time::fromMJD(djm);
    }
}

double Time::jdInt() {
    return jdInt_;
}

double Time::jdFrac() {
    return jdFrac_;
}

double Time::jd() {
    return jdInt_ + jdFrac_;
}

double Time::mjd() {
    return Time::jd() - 2400000.5;
}