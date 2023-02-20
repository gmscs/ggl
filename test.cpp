#include "ggl.hpp"

int main() {
    ggl::vector2<int> v2(3, 2);
    ggl::vector2<int> v(45, 1);
    
    std::cout << "Type: " << v.type() << "\n";

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
    std::cout << "Type: " << ddd.type() << "\n";

    ggl::vector3<int> eq1(1, 1, 1);
    ggl::vector3<int> eq2(1, 2, 1);
    bool t1 = eq1 == eq2;
    bool t2 = eq1 != eq2;
    std::cout << t1 << "\n";
    std::cout << t2 << "\n";

    eq1 *= 3;
    std::cout << ggl::to_string(eq1) << "\n";
    ggl::vector3<int> eq3 = eq2 * 4;
    std::cout << ggl::to_string(eq3) << "\n";

    ggl::vector3<float> div1(4, 6, 8);
    div1 /= 2;
    std::cout << "div1: " << ggl::to_string(div1) << "\n";
    std::cout << div1.length() << "\n";

    ggl::vector3<float> div2(3, 9, 27);
    ggl::vector3<float> div3 = div2 / 3;
    std::cout << ggl::to_string(div3) << "\n";

    std::cout << ggl::radians_to_degrees(1.570796) << "\n";
    std::cout << ggl::degrees_to_radians((double)90.0) << "\n"; // must be floating point type
    std::cout << ggl::degrees_to_radians(90.0f) << "\n"; // must be floating point type

    std::cout << ggl::abs(-789.7) << "\n";

    std::cout << ggl::sqrt(10) << "\n"; // always converts to double

    ggl::matrix2<int> m(v, v2);
    std::cout << ggl::to_string(m.row1) << "\n" << ggl::to_string(m.row2) << "\n";

    std::cout << div1[2] << "\n";
    div1[2] = 7;
    std::cout << div1[2] << "\n";
    std::cout << ggl::to_string(div1) << "\n";

    ggl::matrix4<float> m2;
    // TODO: proper matrix printing
    std::cout << ggl::to_string(m2.row1) << "\n" << ggl::to_string(m2.row2) << "\n";
    std::cout << ggl::to_string(m2.row3) << "\n" << ggl::to_string(m2.row4) << "\n" << "\n";

    ggl::matrix3<float> div_mat(div1, div2, div3);
    std::cout << ggl::to_string(div_mat.row1) << "\n" << ggl::to_string(div_mat.row2) << "\n";
    std::cout << ggl::to_string(div_mat.row3) << "\n"<< "\n";

    div_mat *= 2;
    std::cout << ggl::to_string(div_mat.row1) << "\n" << ggl::to_string(div_mat.row2) << "\n";
    std::cout << ggl::to_string(div_mat.row3) << "\n"<< "\n";

    std::cout << ggl::to_string(div_mat[1]) << "\n";
    std::cout << div_mat[1][0] << "\n";
    std::cout << div_mat[1][1] << "\n";
    std::cout << div_mat[1][2] << "\n";

    return 0;
}