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
    double jd = mjd + 2400000.5;
    double jd_int;
    double jd_frac = std::modf(jd, &jd_int);
    return Time(jd_int, jd_frac);
}

Time Time::fromCalendar(int year, int month, int day, int hours, int minutes, double seconds) {
    double djm0;
    double djm;
    int result_iauCal2jd = sofa::iauCal2jd(year, month, day, &djm0, &djm);
    switch (result_iauCal2jd) {
        case -1:
            throw Exception("bad year (JD not computed)");
        case -2:
            throw Exception("bad month (JD not computed)");
        case -3:
            throw Exception("bad day (JD not computed)");
    }
    double days;
    int result_iauTf2d = sofa::iauTf2d("+", hours, minutes, seconds, &days);
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
    return jdInt_ + jdFrac_ - 2400000.5;
}

Exception::Exception(std::string error) : error_(error) {}