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