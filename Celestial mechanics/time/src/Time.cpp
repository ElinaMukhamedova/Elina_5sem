#include "Time.hpp"
#include <cmath>

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

