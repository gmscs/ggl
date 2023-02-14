#include <stdlib.h>

namespace ggl {
const double PI = 3.141592653589793238462643383279502884; // TODO: temporary

template <typename T>
T radians_to_degrees(T radians)
{
    assert((void("radians_to_degrees only accepts floating point parameters"), std::numeric_limits<T>::is_iec559));
    return radians * (180/PI);
}

template <typename T>
T degrees_to_radians(T degrees)
{
    assert((void("degrees_to_radians only accepts floating point parameters"), std::numeric_limits<T>::is_iec559));
    return degrees * (PI/180);
}
}