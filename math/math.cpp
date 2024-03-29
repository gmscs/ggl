#include "math.hpp"

namespace ggl {

template<std::floating_point T>
constexpr T radians_to_degrees(T radians) {
    return radians * (180/PI);
}

float radians_to_degrees(int radians) {
    radians = static_cast<float>(radians);
    return radians * (180/PI);
}

template<std::floating_point T>
constexpr T degrees_to_radians(T degrees) {
    return degrees * (PI/180);
}

float degrees_to_radians(int degrees) {
    degrees = static_cast<float>(degrees);
    return degrees * (PI/180);
}

template<std::floating_point T>
constexpr T get_aspect_ratio(T width, T height) {
    return width / height;
}

float get_aspect_ratio(int width, int height) {
    width = static_cast<float>(width);
    height = static_cast<float>(height);
    return width / height;
}


template<typename T>
T abs(T val) {
    if(val >= 0) return val;
    return val * -1;
}

template<typename T> // just for fun, use std::sqrt instead since it's faster
double inline asmsqrt(T val) {
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
