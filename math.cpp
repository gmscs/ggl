#include "math.hpp"

namespace ggl {

template<typename T>
T radians_to_degrees(T radians) {
    assert((void("radians_to_degrees only accepts floating point parameters"), std::numeric_limits<T>::is_iec559));
    return radians * (180/PI);
}

template<typename T>
T degrees_to_radians(T degrees) {
    assert((void("degrees_to_radians only accepts floating point parameters"), std::numeric_limits<T>::is_iec559));
    return degrees * (PI/180);
}

template<typename T>
T abs(T val) {
    if(val >= 0) return val;
    return val * -1;
}

template<typename T>
double inline sqrt(T val) {
    double x;
    double v = static_cast<double>(val);

    __asm__(
        "fsqrt  \n\t"
        : "=t"(x)
        : "0"(v)
    );
    return x;
}
}//namespace ggl