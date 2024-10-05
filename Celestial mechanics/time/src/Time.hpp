class Time {
    double jdInt_;
    double jdFrac_;

    public:
        Time(double jd1 = 0, double jd2 = 0) noexcept;

        Time static fromJD (double jd) noexcept;
        Time static fromMJD (double mjd) noexcept;
        Time static fromCalendar (int year, int month, int day);
};