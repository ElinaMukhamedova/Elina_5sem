template<typename A>
struct ArgumentGetter;

template<typename R, typename Arg>
struct ArgumentGetter<R(Arg)> {
    using Argument = Arg;
};

template<typename RealType, typename Callable>
decltype(auto) solve(
    const Callable& func,
    const RealType& tau,
    const typename ArgumentGetter<Callable>::Argument& initialGuess,
    const unsigned int nIteration) {
        typename ArgumentGetter<Callable>::Argument x_prev = initialGuess;
        typename ArgumentGetter<Callable>::Argument x;
        for (int i = 1; i < nIteration; ++i)
            x = x_prev - tau * func(x_prev);
        return x;
    }