#include "math.hpp"

namespace ggl {

constexpr std::floating_point auto radians_to_degrees(std::floating_point auto radians) {
    return radians * (180/PI);
}

float radians_to_degrees(int radians) {
    radians = static_cast<float>(radians);
    return radians * (180/PI);
}

constexpr std::floating_point auto degrees_to_radians(std::floating_point auto degrees) {
    return degrees * (PI/180);
}

float degrees_to_radians(int degrees) {
    degrees = static_cast<float>(degrees);
    return degrees * (PI/180);
}

template<typename T>
T abs(T val) {
    if(val >= 0) return val;
    return val * -1;
}

template<typename T> // just for fun, use std::sqrt instead since it's faster
double inline sqrt(T val) {
    double x;
    double v = static_cast<double>(val);

    __asm__ __inline__(
        "fsqrt"
        : "=t"(x)
        : "0"(v)
    );
    return x;
}
}//namespace ggl
