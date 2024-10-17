#include <compare>

class Time {
    double jdInt_;
    double jdFrac_;

    public:
        Time(double jd1 = 0, double jd2 = 0) noexcept;

        Time static fromJD(double jd) noexcept;
        Time static fromMJD(double mjd) noexcept;

        Time static fromCalendar(int year, int month, int day, int hours, int minutes, double seconds);
        
        double jdInt() const noexcept;
        double jdFrac() const noexcept;
        double jd() const noexcept;
        double mjd() const noexcept;

        auto operator<=>(const Time& other) const noexcept = default;
};

class Duration {
    double ticks;
    //MeasureType measure;

    public:
        double seconds() const noexcept;
};


class Exception {
    std::string error_;

    public:
        Exception(std::string error);
};

Duration operator-(const Time& first, const Time& second) noexcept;
Time operator-(const Time& point, Duration vect) noexcept;
Time operator+(const Time& point, Duration vect) noexcept;
