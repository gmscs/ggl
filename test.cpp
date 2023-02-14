#include "ggl.hpp"

int main() {
    ggl::vector2<int> v2(3, 2);
    ggl::vector2<int> v(45, 1);

    std::cout << ggl::dot(v2, v) << "\n";
    std::cout << v2 * v << "\n";

    ggl::vector2<int> v3 = v2 + v;
    std::cout << ggl::to_string(v3) << "\n";

    ggl::vector3<float> v4(3, 1, 2);
    ggl::vector3<float> n = ggl::normalize(v4);
    std::cout << ggl::to_string(n) << "\n";

    ggl::vector3<float> vc1(2, 3, 4); 
    ggl::vector3<float> vc2(5, 6, 7);
    ggl::vector3<float> crossP = ggl::cross(vc1, vc2);
    std::cout << ggl::to_string(crossP) << "\n";
    
    crossP = -crossP;
    std::cout << ggl::to_string(crossP) << "\n";

    ggl::vector3<int> vvv(5, 4, 3);
    vvv -= ggl::vector3<int>(1, 1, 1);
    std::cout << ggl::to_string(vvv) << "\n";

    ggl::vector4<float> ddd = ggl::vector4<float>(9, 9.5, 9, 9.5) - ggl::vector4<float>(2, 2.5, 2, 2.5);
    std::cout << ggl::to_string(ddd) << "\n";

    ggl::vector3<int> eq1(1, 1, 1);
    ggl::vector3<int> eq2(1, 2, 1);
    bool t1 = eq1 == eq2;
    bool t2 = eq1 != eq2;
    std::cout << t1 << "\n";
    std::cout << t2 << "\n";

    std::cout << ggl::radians_to_degrees(1.570796) << "\n";
    std::cout << ggl::degrees_to_radians((double)90.0) << "\n"; // must be floating point type
    std::cout << ggl::degrees_to_radians(90.0f) << "\n"; // must be floating point type

    return 0;
}