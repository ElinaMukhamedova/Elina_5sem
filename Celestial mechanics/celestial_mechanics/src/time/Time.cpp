#include <cmath>
#include <string>
#include "Time.hpp"
#include "sofa.h"

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
    double mjd_int;
    double mjd_frac = std::modf(mjd, &mjd_int);
    return Time(mjd_int + 2400000, mjd_frac + .5);
}

Time Time::fromCalendar(int year, int month, int day, int hours, int minutes, double seconds) {
    double djm0;
    double djm;
    int result_iauCal2jd = iauCal2jd(year, month, day, &djm0, &djm);
    switch (result_iauCal2jd) {
        case -1:
            throw Exception("bad year (JD not computed)");
        case -2:
            throw Exception("bad month (JD not computed)");
        case -3:
            throw Exception("bad day (JD not computed)");
    }
    double days;
    int result_iauTf2d = iauTf2d('+', hours, minutes, seconds, &days);
    switch (result_iauTf2d) {
        case 1:
            throw Exception("hours outside range 0-23 (JD not computed)");
        case 2:
            throw Exception("minutes outside range 0-59 (JD not computed)");
        case 3:
            throw Exception("seconds outside range 0-59.999... (JD not computed)");
        default:
            return djm0 + djm + days;
    }
}

double Time::jdInt() const noexcept {
    return jdInt_;
}

double Time::jdFrac() const noexcept {
    return jdFrac_;
}

double Time::jd() const noexcept {
    return jdInt_ + jdFrac_;
}

double Time::mjd() const noexcept {
    double mjd_int = jdInt_ - 2400000;
    double mjd_frac = jdFrac_ - .5;
    return mjd_int + mjd_frac;
}

Exception::Exception(std::string error) : error_(error) {}