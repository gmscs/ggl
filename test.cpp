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
    ggl::vector3<float> div(4, 6, 8);
    div = div / 2;
    std::cout << "div1: " << ggl::to_string(div1) << "\n";
    std::cout << div1.length() << "\n";

    ggl::vector3<float> div2(3, 9, 27);
    ggl::vector3<float> div3 = div2 / 3;
    std::cout << ggl::to_string(div3) << "\n";

    std::cout << "1.57ish Radians to Degrees: " << ggl::radians_to_degrees(1.570796) << "\n";
    std::cout << "45 Degrees to Radians: " << ggl::degrees_to_radians(45) << "\n"; // converts to float
    std::cout <<"90.5 Degrees to Radians: " <<  ggl::degrees_to_radians(90.5) << "\n";

    std::cout << ggl::abs(-789.7) << "\n";

    std::cout << ggl::sqrt(10) << "\n"; // always converts to double

    ggl::matrix2<int> m(v, v2);
    std::cout << ggl::to_string(m.row1) << "\n" << ggl::to_string(m.row2) << "\n";

    std::cout << div1[2] << "\n";
    div1[2] = 7;
    std::cout << div1[2] << "\n";
    std::cout << ggl::to_string(div1) << "\n";

    ggl::matrix4<float> m2;
    ggl::print_mat(m2);
    std::cout << "\n";    

    ggl::matrix3<float> div_mat(div1, div2, div3);
    ggl::print_mat(div_mat);
    std::cout << "\n";    

    div_mat *= 2;
    ggl::print_mat(div_mat);    
    std::cout << "\n";    

    std::cout << ggl::to_string(div_mat[1]) << "\n";
    std::cout << div_mat[1][0] << "\n";
    std::cout << div_mat[1][1] << "\n";
    std::cout << div_mat[1][2] << "\n";
    std::cout << "Matrix Type: " << div_mat.type() << "\n";

    ggl::matrix2<int> mmul1(ggl::vector2<int> (1, 2), ggl::vector2<int> (2, 3));
    ggl::matrix2<int> mmul2(ggl::vector2<int> (2, 1), ggl::vector2<int> (3, 2));

    ggl::matrix2<int> mmul = mmul1 * mmul2;
    ggl::print_mat(mmul);

    ggl::matrix2<int> m2det(ggl::vector2<int>(1, 2), ggl::vector2<int>(3, 4));
    std::cout << determinant(m2det) << "\n";

    ggl::matrix3<int> m3det(ggl::vector3<int>(6, 1, 1), ggl::vector3<int>(4, -2, 5), ggl::vector3<int>(2, 8, 7));
    std::cout << determinant(m3det) << "\n";

    ggl::matrix4<float> m4i(1);
    ggl::print_mat(m4i);

    return 0;
}
