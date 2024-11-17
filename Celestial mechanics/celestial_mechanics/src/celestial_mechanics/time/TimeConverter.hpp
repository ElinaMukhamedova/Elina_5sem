template <typename DutContainer>
class TimeConverter {
    DutContainer dutContainer_;
    public:
        TimeConverter (const DutContainer& dutContainer);
        template<Scale To, Scale From>
        Time<To> convert(const Time<From>& from) const;
};