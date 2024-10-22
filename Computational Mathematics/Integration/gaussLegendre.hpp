#include <array>
#include <type_traits>
#include <cmath>

template <typename A>
struct ArgumentGetter;

template <typename R, typename Arg>
struct ArgumentGetter<R(Arg)> {         // specialisation for all functions
    using Argument = Arg;               // ArgumentGetter<Callable>::Argument --> Arg
};

template <typename T>
using DifType = decltype(std::declval<T>() - std::declval<T>());    // DifType<T> --> type of 'duration'

template <typename T>
using DerivativeType = decltype(1.0 / (std::declval<T>() - std::declval<T>()));

template<typename T, std::size_t N>
class LegendrePolynomial {
private:
    const T start_;
    const T end_;
    std::array<double, N> weights_;
    std::array<T, N> roots_;

    struct Result {
        double value_;
        DerivativeType<T> derivative_;

        Result(double value, DerivativeType<T> derivative) : value_(value), derivative_(derivative){};
    };

    Result calculatePolynomialValueAndDerivative(T x) {
        Result result(x, 1);

        T value_minus_1 = 1;
        const T k = 1 / (x * x - 1);
        for(std::size_t step = 2; step <= N; step++) {
            double value = ((2 * step - 1) * x * result.value_ - (step - 1) * value_minus_1) / step;
            result.derivative_ = step * k * (x * value - result.value_);

            value_minus_1 = result.value_;
            result.value_ = value;
        }

        return result;
    }

    void calculateWeightAndRoot() {
        for(std::size_t step = 0; step <= N; step++) {
            T root = std::cos(M_PI * (step - 0.25) / (N + 0.5));           // Tricomi approximation
            Result result = calculatePolynomialValueAndDerivative(root);

            T ratio;
            do {
                ratio = result.value_ / result.derivative_;
                root -= ratio;
                result = calculatePolynomialValueAndDerivative(root);
            } while (std::abs(ratio) > 0);

            roots_[step] = root;
            weights_[step] = 2.0 / ((1 - root * root) * result.derivative_ * result.derivative_);
        }
    }

public:
    LegendrePolynomial(T start, T end)
        : start_(start), end_(end),  weights_(N + 1), roots_(N + 1) {
        calculateWeightAndRoot();
    }

    const std::array<double, N + 1> getWeights() const {
        return weights_;
    }

    const std::array<T, N + 1> getRoots() const {
        return roots_;
    }

};

template <typename Callable, std::size_t N>
decltype(auto) integrate(
    const Callable& func,
    const typename ArgumentGetter<Callable>::Argument& start,
    const typename ArgumentGetter<Callable>::Argument& end
                        ){
                            const LegendrePolynomial<typename ArgumentGetter<Callable>::Argument, N> legendrePolynomial(start, end);
                            const std::array<double, N + 1> & weights = legendrePolynomial.getWeights();
                            const std::array<typename ArgumentGetter<Callable>::Argument, N + 1> & roots = legendrePolynomial.getRoots();

                            const typename ArgumentGetter<Callable>::Argument half_width = 0.5 * (end - start);
                            const typename ArgumentGetter<Callable>::Argument centre_point = 0.5 * (start + end);

                            decltype(auto) integral = 0;
                            for(int step = 1; step <= N; step++) {
                                integral += weights[step] * func(half_width * roots[step] + centre_point);
                            }

                            return integral * half_width;
                        }

//template <typename Callable, std::size_t N>
//decltype(auto) integrate(
//    const Callable& func,
//    const typename ArgumentGetter<Callable>::Argument& start,
//    const typename ArgumentGetter<Callable>::Argument& end,
//    const DifType<typename ArgumentGetter<Callable>::Argument>& dx
//                        ){
//
//                        }