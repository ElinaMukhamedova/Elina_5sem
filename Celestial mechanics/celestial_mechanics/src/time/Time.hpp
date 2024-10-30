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

class Exception : public std::exception {
    const char * error_;

    public:
        Exception(const char * error) : error_(error){};
        const char * what() {return error_;};
};

double operator-(const Time& first, const Time& second) noexcept;
Time operator-(const Time& point, double delta) noexcept;
Time operator+(const Time& point, double delta) noexcept;

enum class Scale{UTC = 0, UT1 = 1};