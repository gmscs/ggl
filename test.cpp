#include "ggl.hpp"

int main() {
    ggl::vector2<float> v2(3, 2);
    ggl::vector2<float> v(45, 1);

    std::cout << ggl::dot(v2, v) << "\n";
    std::cout << v2 * v << "\n";

    ggl::vector2<float> v3 = v2 + v;
    std::cout << ggl::to_string(v3) << "\n";

    ggl::vector3<float> v4(3, 1, 2);
    ggl::vector3<float> n = ggl::normalize(v4);
    std::cout << ggl::to_string(n) << "\n";
    return 0;
}