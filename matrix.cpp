#include "matrix.hpp"

namespace ggl {

template<std::floating_point T>
constexpr matrix2<T>::matrix2() {
    this->row1 = vector2<T>();
    this->row2 = vector2<T>();
}

template<std::floating_point T>
constexpr matrix3<T>::matrix3() {
    this->row1 = vector3<T>();
    this->row2 = vector3<T>();
    this->row3 = vector3<T>();
}

template<std::floating_point T>
constexpr matrix4<T>::matrix4() {
    this->row1 = vector4<T>();
    this->row2 = vector4<T>();
    this->row3 = vector4<T>();
    this->row4 = vector4<T>();
}

template<std::floating_point T>
constexpr matrix2<T>::matrix2(T c) {
    this->row1 = vector2<T>(c, 0);
    this->row2 = vector2<T>(0, c);
}

template<std::floating_point T>
constexpr matrix3<T>::matrix3(T c) {
    this->row1 = vector3<T>(c, 0, 0);
    this->row2 = vector3<T>(0, c, 0);
    this->row3 = vector3<T>(0, 0, c);
}

template<std::floating_point T>
constexpr matrix4<T>::matrix4(T c) {
    this->row1 = vector4<T>(c, 0, 0, 0);
    this->row2 = vector4<T>(0, c, 0, 0);
    this->row3 = vector4<T>(0, 0, c, 0);
    this->row4 = vector4<T>(0, 0, 0, c);
}

template<std::floating_point T>
constexpr matrix2<T>::matrix2(matrix2<T> const &m) {
    this->row1 = vector2<T>(m.row1);
    this->row2 = vector2<T>(m.row2);
}

template<std::floating_point T>
constexpr matrix3<T>::matrix3(matrix3<T> const &m) {
    this->row1 = vector3<T>(m.row1);
    this->row2 = vector3<T>(m.row2);
    this->row3 = vector3<T>(m.row3);
}

template<std::floating_point T>
constexpr matrix4<T>::matrix4(matrix4<T> const &m) {
    this->row1 = vector4<T>(m.row1);
    this->row2 = vector4<T>(m.row2);
    this->row3 = vector4<T>(m.row3);
    this->row4 = vector4<T>(m.row4);
}

template<std::floating_point T>
constexpr matrix2<T>::matrix2(vector2<T> const &a, vector2<T> const &b) {
    this->row1 = a;
    this->row2 = b;
}

template<std::floating_point T>
constexpr matrix3<T>::matrix3(vector3<T> const &a, vector3<T> const &b, vector3<T> const &c) {
    this->row1 = a;
    this->row2 = b;
    this->row3 = c;
}

template<std::floating_point T>
constexpr matrix4<T>::matrix4(vector4<T> const &a, vector4<T> const &b, vector4<T> const &c, vector4<T> const &d) {
    this->row1 = a;
    this->row2 = b;
    this->row3 = c;
    this->row4 = d;
}

template<std::floating_point T>
template<std::floating_point N>
constexpr matrix2<T>& matrix2<T>::operator=(matrix2<N> const &m) {
    this->row1 = m.row1;
    this->row2 = m.row2;
    return *this;
}

template<std::floating_point T>
template<std::floating_point N>
constexpr matrix3<T>& matrix3<T>::operator=(matrix3<N> const &m) {
    this->row1 = m.row1;
    this->row2 = m.row2;
    this->row3 = m.row3;
    return *this;
}

template<std::floating_point T>
template<std::floating_point N>
constexpr matrix4<T>& matrix4<T>::operator=(matrix4<N> const &m) {
    this->row1 = m.row1;
    this->row2 = m.row2;
    this->row3 = m.row3;
    this->row4 = m.row4;
    return *this;
}

template<std::floating_point T>
template<std::floating_point N>
constexpr matrix2<T>& matrix2<T>::operator+=(matrix2<N> const &m) {
    this->row1 += m.row1;
    this->row2 += m.row2;
    return *this;
}

template<std::floating_point T>
template<std::floating_point N>
constexpr matrix3<T>& matrix3<T>::operator+=(matrix3<N> const &m) {
    this->row1 += m.row1;
    this->row2 += m.row2;
    this->row3 += m.row3;
    return *this;
}

template<std::floating_point T>
template<std::floating_point N>
constexpr matrix4<T>& matrix4<T>::operator+=(matrix4<N> const &m) {
    this->row1 += m.row1;
    this->row2 += m.row2;
    this->row3 += m.row3;
    this->row4 += m.row4;
    return *this;
}

template<std::floating_point T>
template<std::floating_point N>
constexpr matrix2<T>& matrix2<T>::operator-=(matrix2<N> const &m) {
    this->row1 -= m.row1;
    this->row2 -= m.row2;
    return *this;
}

template<std::floating_point T>
template<std::floating_point N>
constexpr matrix3<T>& matrix3<T>::operator-=(matrix3<N> const &m) {
    this->row1 -= m.row1;
    this->row2 -= m.row2;
    this->row3 -= m.row3;
    return *this;
}

template<std::floating_point T>
template<std::floating_point N>
constexpr matrix4<T>& matrix4<T>::operator-=(matrix4<N> const &m) {
    this->row1 -= m.row1;
    this->row2 -= m.row2;
    this->row3 -= m.row3;
    this->row4 -= m.row4;
    return *this;
}

template<std::floating_point T>
template<typename N>
constexpr matrix2<T>& matrix2<T>::operator*=(N c) {
    this->row1 *= c;
    this->row2 *= c;
    return *this;
}

template<std::floating_point T>
template<typename N>
constexpr matrix3<T>& matrix3<T>::operator*=(N c) {
    this->row1 *= c;
    this->row2 *= c;
    this->row3 *= c;
    return *this;
}

template<std::floating_point T>
template<typename N>
constexpr matrix4<T>& matrix4<T>::operator*=(N c) {
    this->row1 *= c;
    this->row2 *= c;
    this->row3 *= c;
    this->row4 *= c;
    return *this;
}

template<std::floating_point T>
template<typename N>
constexpr matrix2<T>& matrix2<T>::operator/=(N c) {
    this->row2 /= c;
    this->row1 /= c;
    return *this;
}

template<std::floating_point T>
template<typename N>
constexpr matrix3<T>& matrix3<T>::operator/=(N c) {
    this->row1 /= c;
    this->row2 /= c;
    this->row3 /= c;
    return *this;
}

template<std::floating_point T>
template<typename N>
constexpr matrix4<T>& matrix4<T>::operator/=(N c) {
    this->row1 /= c;
    this->row2 /= c;
    this->row3 /= c;
    this->row4 /= c;
    return *this;
}

template<std::floating_point T>
constexpr vector2<T> const& matrix2<T>::operator[](int i) const {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->numRows()));
    if(i == 0) return this->row1;
    return this->row2;
}

template<std::floating_point T>
constexpr vector3<T> const& matrix3<T>::operator[](int i) const {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->numRows()));
    if(i == 0) return this->row1;
    else if(i == 1) return this->row2;
    return this->row3;
}

template<std::floating_point T>
constexpr vector4<T> const& matrix4<T>::operator[](int i) const {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->numRows()));
    if(i == 0) return this->row1;
    else if(i == 1) return this->row2;
    else if(i == 2) return this->row3;
    return this->row4;
}

template<std::floating_point T>
constexpr vector2<T>& matrix2<T>::operator[](int i) {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->numRows()));
    if(i == 0) return this->row1;
    return this->row2;
}

template<std::floating_point T>
constexpr vector3<T>& matrix3<T>::operator[](int i) {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->numRows()));
    if(i == 0) return this->row1;
    else if(i == 1) return this->row2;
    return this->row3;
}

template<std::floating_point T>
constexpr vector4<T>& matrix4<T>::operator[](int i) {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->numRows()));
    if(i == 0) return this->row1;
    else if(i == 1) return this->row2;
    else if(i == 2) return this->row3;
    return this->row4;
}

/* Sign flip */
template<std::floating_point T>
constexpr matrix2<T> operator-(matrix2<T> const &m) {
    matrix2<T> new_mat(-m.row1, -m.row2);
    return new_mat;
}

template<std::floating_point T>
constexpr matrix3<T> operator-(matrix3<T> const &m) {
    matrix3<T> new_mat(-m.row1, -m.row2, -m.row3);
    return new_mat;
}

template<std::floating_point T>
constexpr matrix4<T> operator-(matrix4<T> const &m) {
    matrix4<T> new_mat(-m.row1, -m.row2, -m.row3, -m.row4);
    return new_mat;
}

/* Addition */
template<std::floating_point T>
constexpr matrix2<T> operator+(matrix2<T> const &m, matrix2<T> const &m2) {
    matrix2<T> new_mat(m.row1 + m2.row1, m.row2 + m2.row2);
    return new_mat;
}

template<std::floating_point T>
constexpr matrix3<T> operator+(matrix3<T> const &m, matrix3<T> const &m2) {
    matrix3<T> new_mat(m.row1 + m2.row1, m.row2 + m2.row2, m.row3 + m2.row3);
    return new_mat;
}

template<std::floating_point T>
constexpr matrix4<T> operator+(matrix4<T> const &m, matrix4<T> const &m2) {
    matrix4<T> new_mat(m.row1 + m2.row1, m.row2 + m2.row2, m.row3 + m2.row3, m.row4 + m2.row4);
    return new_mat;
}

/* Subtraction */
template<std::floating_point T>
constexpr matrix2<T> operator-(matrix2<T> const &m, matrix2<T> const &m2) {
    matrix2<T> new_mat(m.row1 - m2.row1, m.row2 - m2.row2);
    return new_mat;
}

template<std::floating_point T>
constexpr matrix3<T> operator-(matrix3<T> const &m, matrix3<T> const &m2) {
    matrix3<T> new_mat(m.row1 - m2.row1, m.row2 - m2.row2, m.row3 - m2.row3);
    return new_mat;
}

template<std::floating_point T>
constexpr matrix4<T> operator-(matrix4<T> const &m, matrix4<T> const &m2) {
    matrix4<T> new_mat(m.row1 - m2.row1, m.row2 - m2.row2, m.row3 - m2.row3, m.row4 - m2.row4);
    return new_mat;
}

/* Multiplication */
template<std::floating_point T>
constexpr matrix2<T> operator*(matrix2<T> const &m, matrix2<T> const &m2) {
    matrix2<T> new_mat;
    new_mat[0][0] = (m[0][0] * m2[0][0]) + (m[0][1] * m2[1][0]);
    new_mat[0][1] = (m[0][0] * m2[0][1]) + (m[0][1] * m2[1][1]);

    new_mat[1][0] = (m[1][0] * m2[0][0]) + (m[1][1] * m2[1][0]);
    new_mat[1][1] = (m[1][0] * m2[0][1]) + (m[1][1] * m2[1][1]);

    return new_mat;
}

template<std::floating_point T>
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

template<std::floating_point T>
constexpr matrix4<T> operator*(matrix4<T> const &m, matrix4<T> const &m2) {
    matrix4<T> new_mat;
    new_mat[0][0] = (m[0][0] * m2[0][0]) + (m[0][1] * m2[1][0]) + (m[0][2] + m2[2][0]) + (m[0][3] * m2[3][0]);
    new_mat[1][0] = (m[1][0] * m2[0][0]) + (m[1][1] * m2[1][0]) + (m[1][2] + m2[2][0]) + (m[1][3] * m2[3][0]);
    new_mat[2][0] = (m[2][0] * m2[0][0]) + (m[2][1] * m2[1][0]) + (m[2][2] + m2[2][0]) + (m[2][3] * m2[3][0]);
    new_mat[3][0] = (m[3][0] * m2[0][0]) + (m[3][1] * m2[1][0]) + (m[3][2] + m2[2][0]) + (m[3][3] * m2[3][0]);

    new_mat[0][1] = (m[0][0] * m2[0][1]) + (m[0][1] * m2[1][1]) + (m[0][2] + m2[2][1]) + (m[0][3] * m2[3][1]);
    new_mat[1][1] = (m[1][0] * m2[0][1]) + (m[1][1] * m2[1][1]) + (m[1][2] + m2[2][1]) + (m[1][3] * m2[3][1]);
    new_mat[2][1] = (m[2][0] * m2[0][1]) + (m[2][1] * m2[1][1]) + (m[2][2] + m2[2][1]) + (m[2][3] * m2[3][1]);
    new_mat[3][1] = (m[3][0] * m2[0][1]) + (m[3][1] * m2[1][1]) + (m[3][2] + m2[2][1]) + (m[3][3] * m2[3][1]);

    new_mat[0][2] = (m[0][0] * m2[0][2]) + (m[0][1] * m2[1][2]) + (m[0][2] + m2[2][2]) + (m[0][3] * m2[3][2]);
    new_mat[1][2] = (m[1][0] * m2[0][2]) + (m[1][1] * m2[1][2]) + (m[1][2] + m2[2][2]) + (m[1][3] * m2[3][2]);
    new_mat[2][2] = (m[2][0] * m2[0][2]) + (m[2][1] * m2[1][2]) + (m[2][2] + m2[2][2]) + (m[2][3] * m2[3][2]);
    new_mat[3][2] = (m[3][0] * m2[0][2]) + (m[3][1] * m2[1][2]) + (m[3][2] + m2[2][2]) + (m[3][3] * m2[3][2]);

    new_mat[0][3] = (m[0][0] * m2[0][3]) + (m[0][1] * m2[1][3]) + (m[0][2] + m2[2][3]) + (m[0][3] * m2[3][3]);
    new_mat[1][3] = (m[1][0] * m2[0][3]) + (m[1][1] * m2[1][3]) + (m[1][2] + m2[2][3]) + (m[1][3] * m2[3][3]);
    new_mat[2][3] = (m[2][0] * m2[0][3]) + (m[2][1] * m2[1][3]) + (m[2][2] + m2[2][3]) + (m[2][3] * m2[3][3]);
    new_mat[3][3] = (m[3][0] * m2[0][3]) + (m[3][1] * m2[1][3]) + (m[3][2] + m2[2][3]) + (m[3][3] * m2[3][3]);

    return new_mat;
}

template<std::floating_point T, typename N>
constexpr matrix2<T> operator*(matrix2<T> const &m, N c) {
    matrix2<T> new_mat(m.row1 * c, m.row2 * c);
    return new_mat;
}

template<std::floating_point T, typename N>
constexpr matrix3<T> operator*(matrix3<T> const &m, N c) {
    matrix3<T> new_mat(m.row1 * c, m.row2 * c, m.row3 * c);
    return new_mat;
}

template<std::floating_point T, typename N>
constexpr matrix4<T> operator*(matrix4<T> const &m, N c){
    matrix4<T> new_mat(m.row1 * c, m.row2 * c, m.row3 * c, m.row4 * c);
    return new_mat;
}

template<std::floating_point T, typename N>
constexpr matrix2<T> operator*(N c, matrix2<T> const &m) {
    matrix2<T> new_mat(m.row1 * c, m.row2 * c);
    return new_mat;
}

template<std::floating_point T, typename N>
constexpr matrix3<T> operator*(N c, matrix3<T> const &m) {
    matrix3<T> new_mat(m.row1 * c, m.row2 * c, m.row3 * c);
    return new_mat;
}

template<std::floating_point T, typename N>
constexpr matrix4<T> operator*(N c, matrix4<T> const &m){
    matrix4<T> new_mat(m.row1 * c, m.row2 * c, m.row3 * c, m.row4 * c);
    return new_mat;
}

/* Division */
template<std::floating_point T, typename N>
constexpr matrix2<T> operator/(matrix2<T> const &m, N c) {
    matrix2<T> new_mat(m.row1 / c, m.row2 / c);
    return new_mat;
}

template<std::floating_point T, typename N>
constexpr matrix3<T> operator/(matrix3<T> const &m, N c) {
    matrix3<T> new_mat(m.row1 / c, m.row2 / c, m.row3 / c);
    return new_mat;
}

template<std::floating_point T, typename N>
constexpr matrix4<T> operator/(matrix4<T> const &m, N c) {
    matrix4<T> new_mat(m.row1 / c, m.row2 / c, m.row3 / c, m.row4 / c);
    return new_mat;
}

template<std::floating_point T, typename N>
constexpr matrix2<T> operator/(N c, matrix2<T> const &m) {
    matrix2<T> new_mat(m.row1 / c, m.row2 / c);
    return new_mat;
}

template<std::floating_point T, typename N>
constexpr matrix3<T> operator/(N c, matrix3<T> const &m) {
    matrix3<T> new_mat(m.row1 / c, m.row2 / c, m.row3 / c);
    return new_mat;
}

template<std::floating_point T, typename N>
constexpr matrix4<T> operator/(N c, matrix4<T> const &m) {
    matrix4<T> new_mat(m.row1 / c, m.row2 / c, m.row3 / c, m.row4 / c);
    return new_mat;
}

/* Boolean Operators */
template<std::floating_point T>
constexpr bool operator==(matrix2<T> const &m, matrix2<T> const &m2) {
    if(m.row1 == m2.row1 && m.row2 == m2.row2) return true;
    return false;
}

template<std::floating_point T>
constexpr bool operator==(matrix3<T> const &m, matrix3<T> const &m2) {
    if(m.row1 == m2.row1 && m.row2 == m2.row2 && m.row3 == m2.row3) return true;
    return false;
}

template<std::floating_point T>
constexpr bool operator==(matrix4<T> const &m, matrix4<T> const &m2) {
    if(m.row1 == m2.row1 && m.row2 == m2.row2 && m.row3 == m2.row3 && m.row4 == m2.row4) return true;
    return false;
}

template<std::floating_point T>
constexpr bool operator!=(matrix2<T> const &m, matrix2<T> const &m2) {
    return !(m == m2);
}

template<std::floating_point T>
constexpr bool operator!=(matrix3<T> const &m, matrix3<T> const &m2) {
    return !(m == m2);
}

template<std::floating_point T>
constexpr bool operator!=(matrix4<T> const &m, matrix4<T> const &m2) {
    return !(m == m2);
}

/* Determinant */
template<std::floating_point T>
constexpr T determinant(matrix2<T> const &m) {
    return ((m[0][0] * m[1][1]) - (m[0][1] * m[1][0]));
}

template<std::floating_point T>
constexpr T determinant(matrix3<T> const &m) {
    T det1 = m[0][0] * ((m[1][1] * m[2][2]) - (m[1][2] * m[2][1]));
    T det2 = m[0][1] * ((m[1][0] * m[2][2]) - (m[1][2] * m[2][0]));
    T det3 = m[0][2] * ((m[1][0] * m[2][1]) - (m[1][1] * m[2][0]));

    return det1 - det2 + det3;
}

template<std::floating_point T>
constexpr T determinant(matrix4<T> const &m) {
    matrix3<T> mat1(vector3<T>(m[1][1], m[1][2], m[1][3]), vector3<T>(m[2][1], m[2][2], m[2][3]), vector3<T>(m[3][1], m[3][2], m[3][3]));
    matrix3<T> mat2(vector3<T>(m[1][0], m[1][2], m[1][3]), vector3<T>(m[2][0], m[2][2], m[2][3]), vector3<T>(m[3][0], m[3][2], m[3][3]));
    matrix3<T> mat3(vector3<T>(m[1][0], m[1][1], m[1][3]), vector3<T>(m[2][0], m[2][1], m[2][3]), vector3<T>(m[3][0], m[3][1], m[3][3]));
    matrix3<T> mat4(vector3<T>(m[1][0], m[1][1], m[1][2]), vector3<T>(m[2][0], m[2][1], m[2][2]), vector3<T>(m[3][0], m[3][1], m[3][2]));

    T det1 = m[0][0] * determinant(mat1);
    T det2 = m[0][1] * determinant(mat2);
    T det3 = m[0][2] * determinant(mat3);
    T det4 = m[0][3] * determinant(mat4);

    return det1 - det2 + det3 - det4;
}

/* Inverse */
template<std::floating_point T>
constexpr matrix2<T> inverse(matrix2<T> const &m) {
    matrix2<T> new_mat(vector2<T>(m[1][1], -1*m[0][1]), vector2<T>(-1*m[1][0], m[0][0]));
    new_mat *= 1/determinant(new_mat);
    return new_mat;
}

template<std::floating_point T>
constexpr matrix3<T> inverse(matrix3<T> const &m) {
    matrix3<T> min = minors_matrix(m);
    matrix3<T> cof = cofactors_matrix(min);
    matrix3<T> transpose = transpose_matrix(cof);
    matrix3<T> inverse = (1 / determinant(m)) * transpose; //TODO: Negative 0
    return inverse;
}

template<std::floating_point T>
constexpr matrix4<T> inverse(matrix4<T> const &m) {
    matrix4<T> min = minors_matrix(m);
    matrix4<T> cof = cofactors_matrix(min);
    matrix4<T> transpose = transpose_matrix(cof);
    matrix4<T> inverse = (1 / determinant(m)) * transpose;
    return inverse;
}

/* Printing */
template<std::floating_point T>
constexpr void print_mat(matrix2<T> const &m) {
    int i = 0;
    while(i < 2) {
        std::cout << ggl::to_string(m[i]) << "\n";
        i++;
    }
}

template<std::floating_point T>
constexpr void print_mat(matrix3<T> const &m) {
    int i = 0;
    while(i < 3) {
        std::cout << ggl::to_string(m[i]) << "\n";
        i++;
    }
}

template<std::floating_point T>
constexpr void print_mat(matrix4<T> const &m) {
    int i = 0;
    while(i < 4) {
	    std::cout << ggl::to_string(m[i]) << "\n";
        i++;
    }
}

/* Special Matrices*/
template<std::floating_point T>
ggl::matrix4<T> get_projection_matrix(T near, T far, T fov, T width, T height)
{
    ggl::matrix4<T> proj;
    float aspect_ratio = width / height;
    proj[0][0] = (T)(1.0f / std::tan(fov/2)) / aspect_ratio;
    proj[1][1] = (T)(1.0f / std::tan(fov/2));
    proj[2][2] = (T)(-far - near) / (far - near);
    proj[3][2] = (T)-1.0;
    proj[2][3] = (T)(-2 * far * near) / (far - near);
    return proj;
}

template<std::floating_point T>
ggl::matrix3<T> minors_matrix(matrix3<T> const &m) {
    matrix3<T> new_mat;

    new_mat[0][0] = determinant(matrix2<T>(vector2<T>(m[1][1], m[1][2]), vector2<T>(m[2][1], m[2][2])));
    new_mat[0][1] = determinant(matrix2<T>(vector2<T>(m[1][0], m[1][2]), vector2<T>(m[2][0], m[2][2])));
    new_mat[0][2] = determinant(matrix2<T>(vector2<T>(m[1][0], m[1][1]), vector2<T>(m[2][0], m[2][1])));

    new_mat[1][0] = determinant(matrix2<T>(vector2<T>(m[0][1], m[0][2]), vector2<T>(m[2][1], m[2][2])));
    new_mat[1][1] = determinant(matrix2<T>(vector2<T>(m[0][0], m[0][2]), vector2<T>(m[2][0], m[2][2])));
    new_mat[1][2] = determinant(matrix2<T>(vector2<T>(m[0][0], m[0][1]), vector2<T>(m[2][0], m[2][1])));

    new_mat[2][0] = determinant(matrix2<T>(vector2<T>(m[0][1], m[0][2]), vector2<T>(m[1][1], m[1][2])));
    new_mat[2][1] = determinant(matrix2<T>(vector2<T>(m[0][0], m[0][2]), vector2<T>(m[1][0], m[1][2])));
    new_mat[2][2] = determinant(matrix2<T>(vector2<T>(m[0][0], m[0][1]), vector2<T>(m[1][0], m[1][1])));

    return new_mat;
}

template<std::floating_point T>
ggl::matrix4<T> minors_matrix(matrix4<T> const & m) {
    matrix4<T> new_mat;

    new_mat[0][0] = determinant(matrix3<T>(vector3<T>(m[1][1], m[1][2], m[1][3]), vector3<T>(m[2][1], m[2][2], m[2][3]), vector3<T>(m[3][1], m[3][2], m[3][3])));
    new_mat[0][1] = determinant(matrix3<T>(vector3<T>(m[1][0], m[1][2], m[1][3]), vector3<T>(m[2][0], m[2][2], m[2][3]), vector3<T>(m[3][0], m[3][2], m[3][3])));
    new_mat[0][2] = determinant(matrix3<T>(vector3<T>(m[1][0], m[1][1], m[1][3]), vector3<T>(m[2][0], m[2][1], m[2][3]), vector3<T>(m[3][0], m[3][1], m[3][3])));
    new_mat[0][3] = determinant(matrix3<T>(vector3<T>(m[1][0], m[1][1], m[1][2]), vector3<T>(m[2][0], m[2][1], m[2][2]), vector3<T>(m[3][0], m[3][1], m[3][2])));

    new_mat[1][0] = determinant(matrix3<T>(vector3<T>(m[0][1], m[0][2], m[0][3]), vector3<T>(m[2][1], m[2][2], m[2][3]), vector3<T>(m[3][1], m[3][2], m[3][3])));
    new_mat[1][1] = determinant(matrix3<T>(vector3<T>(m[0][0], m[0][2], m[0][3]), vector3<T>(m[2][0], m[2][2], m[2][3]), vector3<T>(m[3][0], m[3][2], m[3][3])));
    new_mat[1][2] = determinant(matrix3<T>(vector3<T>(m[0][0], m[0][1], m[0][3]), vector3<T>(m[2][0], m[2][1], m[2][3]), vector3<T>(m[3][0], m[3][1], m[3][3])));
    new_mat[1][3] = determinant(matrix3<T>(vector3<T>(m[0][0], m[0][1], m[0][2]), vector3<T>(m[2][0], m[2][1], m[2][2]), vector3<T>(m[3][0], m[3][1], m[3][2])));

    new_mat[2][0] = determinant(matrix3<T>(vector3<T>(m[0][1], m[0][2], m[0][3]), vector3<T>(m[1][1], m[1][2], m[1][3]), vector3<T>(m[3][1], m[3][2], m[3][3])));
    new_mat[2][1] = determinant(matrix3<T>(vector3<T>(m[0][0], m[0][2], m[0][3]), vector3<T>(m[1][0], m[1][2], m[1][3]), vector3<T>(m[3][0], m[3][2], m[3][3])));
    new_mat[2][2] = determinant(matrix3<T>(vector3<T>(m[0][0], m[0][1], m[0][3]), vector3<T>(m[1][0], m[1][1], m[1][3]), vector3<T>(m[3][0], m[3][1], m[3][3])));
    new_mat[2][3] = determinant(matrix3<T>(vector3<T>(m[0][0], m[0][1], m[0][2]), vector3<T>(m[1][0], m[1][1], m[1][2]), vector3<T>(m[3][0], m[3][1], m[3][2])));

    new_mat[3][0] = determinant(matrix3<T>(vector3<T>(m[0][1], m[0][2], m[0][3]), vector3<T>(m[1][1], m[1][2], m[1][3]), vector3<T>(m[2][1], m[2][2], m[2][3])));
    new_mat[3][1] = determinant(matrix3<T>(vector3<T>(m[0][0], m[0][2], m[0][3]), vector3<T>(m[1][0], m[1][2], m[1][3]), vector3<T>(m[2][0], m[2][2], m[2][3])));
    new_mat[3][2] = determinant(matrix3<T>(vector3<T>(m[0][0], m[0][1], m[0][3]), vector3<T>(m[1][0], m[1][1], m[1][3]), vector3<T>(m[2][0], m[2][1], m[2][3])));
    new_mat[3][3] = determinant(matrix3<T>(vector3<T>(m[0][0], m[0][1], m[0][2]), vector3<T>(m[1][0], m[1][1], m[1][2]), vector3<T>(m[2][0], m[2][1], m[2][2])));

    return new_mat;
}

template<std::floating_point T>
ggl::matrix3<T> cofactors_matrix(matrix3<T> const &m) {
    matrix3<T> new_mat = m;
    new_mat[0][1] *= -1;
    new_mat[1][0] *= -1;
    new_mat[1][2] *= -1;
    new_mat[2][1] *= -1;
    return new_mat;
}

template<std::floating_point T>
ggl::matrix4<T> cofactors_matrix(matrix4<T> const &m) {
    matrix4<T> new_mat = m;
    new_mat[0][1] *= -1;
    new_mat[0][3] *= -1;
    new_mat[1][0] *= -1;
    new_mat[1][2] *= -1;
    new_mat[2][1] *= -1;
    new_mat[2][3] *= -1;
    new_mat[3][0] *= -1;
    new_mat[3][2] *= -1;
    return new_mat;
}

template<std::floating_point T>
ggl::matrix3<T> transpose_matrix(matrix3<T> const &m) {
    matrix3<T> new_mat = m;
    new_mat[0][1] = m[1][0];
    new_mat[1][0] = m[0][1];
    new_mat[0][2] = m[2][0];
    new_mat[2][0] = m[0][2];
    new_mat[1][2] = m[2][1];
    new_mat[2][1] = m[1][2];
    return new_mat;
}

template<std::floating_point T>
ggl::matrix4<T> transpose_matrix(matrix4<T> const &m) {
    matrix4<T> new_mat = m;
    new_mat[0][1] = m[1][0];
    new_mat[1][0] = m[0][1];
    new_mat[0][2] = m[2][0];
    new_mat[2][0] = m[0][2];
    new_mat[1][2] = m[2][1];
    new_mat[2][1] = m[1][2];
    new_mat[0][3] = m[3][0];
    new_mat[3][0] = m[0][3];
    new_mat[1][3] = m[3][1];
    new_mat[3][1] = m[1][3];
    new_mat[3][2] = m[2][3];
    new_mat[2][3] = m[3][2];
    return new_mat;
}

/* Translation */
template<std::floating_point T>
ggl::matrix2<T> translate(matrix2<T> const &m, vector2<T> const &v) {
    return matrix2<T>(m.row1 + v.x, m.row2 + v.y);
}

template<std::floating_point T>
ggl::matrix3<T> translate(matrix3<T> const &m, vector3<T> const &v) {
    return matrix3<T>(m.row1 + v.x, m.row2 + v.y, m.row3 + v.z);
}

template<std::floating_point T>
ggl::matrix3<T> translate(matrix3<T> const &m, vector2<T> const &v) {
    return matrix3<T>(m.row1 + v.x, m.row2 + v.y, m.row3);
}

template<std::floating_point T>
ggl::matrix4<T> translate(matrix4<T> const &m, vector4<T> const &v) {
    return matrix4<T>(m.row1 + v.x, m.row2 + v.y, m.row3 + v.z, m.row4 + v.w);
}

template<std::floating_point T>
ggl::matrix4<T> translate(matrix4<T> const &m, vector3<T> const &v) {
    return matrix4<T>(m.row1 + v.x, m.row2 + v.y, m.row3 + v.z, m.row4);
}

template<std::floating_point T>
ggl::matrix4<T> translate(matrix4<T> const &m, vector2<T> const &v) {
    return matrix4<T>(m.row1 + v.x, m.row2 + v.y, m.row3, m.row4);
}

} //namespace ggl
