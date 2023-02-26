#include "matrix.hpp"

namespace ggl {

template<typename T>
constexpr matrix2<T>::matrix2() {
    this->row1 = vector2<T>();
    this->row2 = vector2<T>();
}

template<typename T>
constexpr matrix3<T>::matrix3() {
    this->row1 = vector3<T>();
    this->row2 = vector3<T>();
    this->row3 = vector3<T>();
}

template<typename T>
constexpr matrix4<T>::matrix4() {
    this->row1 = vector4<T>();
    this->row2 = vector4<T>();
    this->row3 = vector4<T>();
    this->row4 = vector4<T>();
}

template<typename T>
constexpr matrix2<T>::matrix2(matrix2<T> const &m) {
    this->row1 = vector2<T>(m.row1);
    this->row2 = vector2<T>(m.row2);
}

template<typename T>
constexpr matrix3<T>::matrix3(matrix3<T> const &m) {
    this->row1 = vector3<T>(m.row1);
    this->row2 = vector3<T>(m.row2);
    this->row3 = vector3<T>(m.row3);
}

template<typename T>
constexpr matrix4<T>::matrix4(matrix4<T> const &m) {
    this->row1 = vector4<T>(m.row1);
    this->row2 = vector4<T>(m.row2);
    this->row3 = vector4<T>(m.row3);
    this->row4 = vector4<T>(m.row4);
}

template<typename T>
constexpr matrix2<T>::matrix2(vector2<T> const &a, vector2<T> const &b) {
    this->row1 = a;
    this->row2 = b;
}

template<typename T>
constexpr matrix3<T>::matrix3(vector3<T> const &a, vector3<T> const &b, vector3<T> const &c) {
    this->row1 = a;
    this->row2 = b;
    this->row3 = c;
}

template<typename T>
constexpr matrix4<T>::matrix4(vector4<T> const &a, vector4<T> const &b, vector4<T> const &c, vector4<T> const &d) {
    this->row1 = a;
    this->row2 = b;
    this->row3 = c;
    this->row4 = d;
}

template<typename T>
template<typename N>
constexpr matrix2<T>& matrix2<T>::operator=(matrix2<N> const &m) {
    this->row1 = m.row1;
    this->row2 = m.row2;
    return *this;
}

template<typename T>
template<typename N>
constexpr matrix3<T>& matrix3<T>::operator=(matrix3<N> const &m) {
    this->row1 = m.row1;
    this->row2 = m.row2;
    this->row3 = m.row3;
    return *this;
}

template<typename T>
template<typename N>
constexpr matrix4<T>& matrix4<T>::operator=(matrix4<N> const &m) {
    this->row1 = m.row1;
    this->row2 = m.row2;
    this->row3 = m.row3;
    this->row4 = m.row4;
    return *this;
}

template<typename T>
template<typename N>
constexpr matrix2<T>& matrix2<T>::operator+=(matrix2<N> const &m) {
    this->row1 += m.row1;
    this->row2 += m.row2;
    return *this;
}

template<typename T>
template<typename N>
constexpr matrix3<T>& matrix3<T>::operator+=(matrix3<N> const &m) {
    this->row1 += m.row1;
    this->row2 += m.row2;
    this->row3 += m.row3;
    return *this;
}

template<typename T>
template<typename N>
constexpr matrix4<T>& matrix4<T>::operator+=(matrix4<N> const &m) {
    this->row1 += m.row1;
    this->row2 += m.row2;
    this->row3 += m.row3;
    this->row4 += m.row4;
    return *this;
}

template<typename T>
template<typename N>
constexpr matrix2<T>& matrix2<T>::operator-=(matrix2<N> const &m) {
    this->row1 -= m.row1;
    this->row2 -= m.row2;
    return *this;
}

template<typename T>
template<typename N>
constexpr matrix3<T>& matrix3<T>::operator-=(matrix3<N> const &m) {
    this->row1 -= m.row1;
    this->row2 -= m.row2;
    this->row3 -= m.row3;
    return *this;
}

template<typename T>
template<typename N>
constexpr matrix4<T>& matrix4<T>::operator-=(matrix4<N> const &m) {
    this->row1 -= m.row1;
    this->row2 -= m.row2;
    this->row3 -= m.row3;
    this->row4 -= m.row4;
    return *this;
}

template<typename T>
template<typename N>
constexpr matrix2<T>& matrix2<T>::operator*=(N c) {
    this->row1 *= c;
    this->row2 *= c;
    return *this;
}

template<typename T>
template<typename N>
constexpr matrix3<T>& matrix3<T>::operator*=(N c) {
    this->row1 *= c;
    this->row2 *= c;
    this->row3 *= c;
    return *this;
}

template<typename T>
template<typename N>
constexpr matrix4<T>& matrix4<T>::operator*=(N c) {
    this->row1 *= c;
    this->row2 *= c;
    this->row3 *= c;
    this->row4 *= c;
    return *this;
}

template<typename T>
template<typename N>
constexpr matrix2<T>& matrix2<T>::operator/=(N c) {
    this->row2 /= c;
    this->row1 /= c;
    return *this;
}

template<typename T>
template<typename N>
constexpr matrix3<T>& matrix3<T>::operator/=(N c) {
    this->row1 /= c;
    this->row2 /= c;
    this->row3 /= c;
    return *this;
}

template<typename T>
template<typename N>
constexpr matrix4<T>& matrix4<T>::operator/=(N c) {
    this->row1 /= c;
    this->row2 /= c;
    this->row3 /= c;
    this->row4 /= c;
    return *this;
}

template<typename T>
constexpr vector2<T> const& matrix2<T>::operator[](int i) const {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->numRows()));
    if(i == 0) return this->row1;
    return this->row2;
}

template<typename T>
constexpr vector3<T> const& matrix3<T>::operator[](int i) const {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->numRows()));
    if(i == 0) return this->row1;
    else if(i == 1) return this->row2;
    return this->row3;
}

template<typename T>
constexpr vector4<T> const& matrix4<T>::operator[](int i) const {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->numRows()));
    if(i == 0) return this->row1;
    else if(i == 1) return this->row2;
    else if(i == 2) return this->row3;
    return this->row4;
}

template<typename T>
constexpr vector2<T>& matrix2<T>::operator[](int i) {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->numRows()));
    if(i == 0) return this->row1;
    return this->row2;
}

template<typename T>
constexpr vector3<T>& matrix3<T>::operator[](int i) {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->numRows()));
    if(i == 0) return this->row1;
    else if(i == 1) return this->row2;
    return this->row3;
}

template<typename T>
constexpr vector4<T>& matrix4<T>::operator[](int i) {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->numRows()));
    if(i == 0) return this->row1;
    else if(i == 1) return this->row2;
    else if(i == 2) return this->row3;
    return this->row4;
}

/* Sign flip */
template<typename T>
constexpr matrix2<T> operator-(matrix2<T> const &m) {
    matrix2<T> new_mat;
    new_mat.row1 = -m.row1;
    new_mat.row2 = -m.row2;
    return new_mat;
}

template<typename T>
constexpr matrix3<T> operator-(matrix3<T> const &m) {
    matrix3<T> new_mat;
    new_mat.row1 = -m.row1;
    new_mat.row2 = -m.row2;
    new_mat.row3 = -m.row3;
    return new_mat;
}

template<typename T>
constexpr matrix4<T> operator-(matrix4<T> const &m) {
    matrix4<T> new_mat;
    new_mat.row1 = -m.row1;
    new_mat.row2 = -m.row2;
    new_mat.row3 = -m.row3;
    new_mat.row4 = -m.row4;
    return new_mat;
}

/* Multiplication */
template<typename T>
constexpr matrix2<T> operator*(matrix2<T> const &m, matrix2<T> const &m2) {
    matrix2<T> new_mat;
    new_mat[0][0] = (m[0][0] * m2[0][0]) + (m[0][1] * m2[1][0]);
    new_mat[0][1] = (m[0][0] * m2[0][1]) + (m[0][1] * m2[1][1]);

    new_mat[1][0] = (m[1][0] * m2[0][0]) + (m[1][1] * m2[1][0]);
    new_mat[1][1] = (m[1][0] * m2[0][1]) + (m[1][1] * m2[1][1]);

    return new_mat;
}

template<typename T>
constexpr matrix3<T> operator*(matrix3<T> const &m, matrix3<T> const &m2) {
    matrix3<T> new_mat;
    new_mat[0][0] = (m[0][0] * m2[0][0]) + (m[0][1] * m2[1][0]) + (m[0][2] * m2[2][0]);
    new_mat[1][0] = (m[1][0] * m2[0][0]) + (m[1][1] * m2[1][0]) + (m[1][2] * m2[2][0]);
    new_mat[2][0] = (m[2][0] * m2[0][0]) + (m[2][1] * m2[1][0]) + (m[2][2] * m2[2][0]);

    new_mat[0][1] = (m[0][0] * m2[0][1]) + (m[0][1] * m2[1][1]) + (m[0][2] * m2[2][1]);
    new_mat[1][1] = (m[1][0] * m2[0][1]) + (m[1][1] * m2[1][1]) + (m[1][2] * m2[2][1]);
    new_mat[2][1] = (m[2][0] * m2[0][1]) + (m[2][1] * m2[1][1]) + (m[2][2] * m2[2][1]);

    new_mat[0][2] = (m[0][0] * m2[0][2]) + (m[0][1] * m2[1][2]) + (m[0][2] * m2[2][2]);
    new_mat[1][2] = (m[1][0] * m2[0][2]) + (m[1][1] * m2[1][2]) + (m[1][2] * m2[2][2]);
    new_mat[2][2] = (m[2][0] * m2[0][2]) + (m[2][1] * m2[1][2]) + (m[2][2] * m2[2][2]);

    return new_mat;
}

/* Printing */
template<typename T>
constexpr void print_mat(matrix2<T> const &m) {
    int i = 0;
    while(i < 2) {
        std::cout << ggl::to_string(m[i]) << "\n";
        i++;
    }
}

template<typename T>
constexpr void print_mat(matrix3<T> const &m) {
    int i = 0;
    while(i < 3) {
        std::cout << ggl::to_string(m[i]) << "\n";
        i++;
    }
}

template<typename T>
constexpr void print_mat(matrix4<T> const &m) {
    int i = 0;
    while(i < 4) {
	    std::cout << ggl::to_string(m[i]) << "\n";
        i++;
    }
}

} //namespace ggl
