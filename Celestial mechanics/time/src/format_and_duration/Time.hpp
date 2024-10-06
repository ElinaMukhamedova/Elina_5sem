class Time {
    double jdInt_;
    double jdFrac_;

    public:
        Time(double jd1 = 0, double jd2 = 0) noexcept;

        Time static fromJD(double jd) noexcept;
        Time static fromMJD(double mjd) noexcept;

        class Exception {
            std::string error_;

            public:
                Exception(std::string error) : error_(error) {}
        };
        Time static fromCalendar(int year, int month, int day);
        
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

Duration operator-(const Time& first, const Time& second) noexcept;
Time operator-(const Time& point, Duration vect) noexcept;
Time operator+(const Time& point, Duration vect) noexcept;
