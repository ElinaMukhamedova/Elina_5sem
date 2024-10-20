#include <array>
#include <type_traits>

template <typename A>
struct ArgumentGetter;

template <typename R, typename Arg>
struct ArgumentGetter<R(Arg)> {         // specialisation for all functions
    using Argument = Arg;               // Argument<R> --> Arg
};

template <typename T>
using Dif = decltype(std::declval<T>() - std::declval<T>());    // Dif<T> --> type of 'duration'

template <typename Callable, std::size_t N>
decltype(auto) integrate(
    const Callable& func,
    const typename ArgumentGetter<Callable>::Argument& start,
    const typename ArgumentGetter<Callable>::Argument& end
                        );

template <typename Callable, std::size_t N>
decltype(auto) integrate(
    const Callable& func,
    const typename ArgumentGetter<Callable>::Argument& start,
    const typename ArgumentGetter<Callable>::Argument& end,
    const Dif<typename ArgumentGetter<Callable>::Argument>& dx
                        );