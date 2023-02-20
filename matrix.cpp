#include "matrix.hpp"

namespace ggl {

template<typename T>
matrix2<T>::matrix2() {
    this->row1 = vector2<T>();
    this->row2 = vector2<T>();
}

template<typename T>
matrix3<T>::matrix3() {
    this->row1 = vector3<T>();
    this->row2 = vector3<T>();
    this->row3 = vector3<T>();
}

template<typename T>
matrix4<T>::matrix4() {
    this->row1 = vector4<T>();
    this->row2 = vector4<T>();
    this->row3 = vector4<T>();
    this->row4 = vector4<T>();
}

template<typename T>
matrix2<T>::matrix2(vector2<T> const &a, vector2<T> const &b) {
    this->row1 = a;
    this->row2 = b;
}

template<typename T>
matrix3<T>::matrix3(vector3<T> const &a, vector3<T> const &b, vector3<T> const &c) {
    this->row1 = a;
    this->row2 = b;
    this->row3 = c;
}

template<typename T>
matrix4<T>::matrix4(vector4<T> const &a, vector4<T> const &b, vector4<T> const &c, vector4<T> const &d) {
    this->row1 = a;
    this->row2 = b;
    this->row3 = c;
    this->row4 = d;
}

template<typename T>
template<typename N>
matrix2<T>& matrix2<T>::operator=(matrix2<N> const &m) {
    this->row1 = m.row1;
    this->row2 = m.row2;
    return *this;
}

template<typename T>
template<typename N>
matrix3<T>& matrix3<T>::operator=(matrix3<N> const &m) {
    this->row1 = m.row1;
    this->row2 = m.row2;
    this->row3 = m.row3;
    return *this;
}

template<typename T>
template<typename N>
matrix4<T>& matrix4<T>::operator=(matrix4<N> const &m) {
    this->row1 = m.row1;
    this->row2 = m.row2;
    this->row3 = m.row3;
    this->row4 = m.row4;
    return *this;
}

template<typename T>
template<typename N>
matrix2<T>& matrix2<T>::operator+=(matrix2<N> const &m) {
    this->row1 += m.row1;
    this->row2 += m.row2;
    return *this;
}

template<typename T>
template<typename N>
matrix3<T>& matrix3<T>::operator+=(matrix3<N> const &m) {
    this->row1 += m.row1;
    this->row2 += m.row2;
    this->row3 += m.row3;
    return *this;
}

template<typename T>
template<typename N>
matrix4<T>& matrix4<T>::operator+=(matrix4<N> const &m) {
    this->row1 += m.row1;
    this->row2 += m.row2;
    this->row3 += m.row3;
    this->row4 += m.row4;
    return *this;
}

template<typename T>
template<typename N>
matrix2<T>& matrix2<T>::operator-=(matrix2<N> const &m) {
    this->row1 -= m.row1;
    this->row2 -= m.row2;
    return *this;
}

template<typename T>
template<typename N>
matrix3<T>& matrix3<T>::operator-=(matrix3<N> const &m) {
    this->row1 -= m.row1;
    this->row2 -= m.row2;
    this->row3 -= m.row3;
    return *this;
}

template<typename T>
template<typename N>
matrix4<T>& matrix4<T>::operator-=(matrix4<N> const &m) {
    this->row1 -= m.row1;
    this->row2 -= m.row2;
    this->row3 -= m.row3;
    this->row4 -= m.row4;
    return *this;
}

template<typename T>
template<typename N>
matrix2<T>& matrix2<T>::operator*=(N c) {
    this->row1 *= c;
    this->row2 *= c;
    return *this;
}

template<typename T>
template<typename N>
matrix3<T>& matrix3<T>::operator*=(N c) {
    this->row1 *= c;
    this->row2 *= c;
    this->row3 *= c;
    return *this;
}

template<typename T>
template<typename N>
matrix4<T>& matrix4<T>::operator*=(N c) {
    this->row1 *= c;
    this->row2 *= c;
    this->row3 *= c;
    this->row4 *= c;
    return *this;
}

template<typename T>
template<typename N>
matrix2<T>& matrix2<T>::operator/=(N c) {
    this->row2 /= c;
    this->row1 /= c;
    return *this;
}

template<typename T>
template<typename N>
matrix3<T>& matrix3<T>::operator/=(N c) {
    this->row1 /= c;
    this->row2 /= c;
    this->row3 /= c;
    return *this;
}

template<typename T>
template<typename N>
matrix4<T>& matrix4<T>::operator/=(N c) {
    this->row1 /= c;
    this->row2 /= c;
    this->row3 /= c;
    this->row4 /= c;
    return *this;
}

template<typename T>
vector2<T> const& matrix2<T>::operator[](int i) const {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->numRows()));
    if(i == 0) return this->row1;
    return this->row2;
}

template<typename T>
vector3<T> const& matrix3<T>::operator[](int i) const {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->numRows()));
    if(i == 0) return this->row1;
    else if(i == 1) return this->row2;
    return this->row3;
}

template<typename T>
vector4<T> const& matrix4<T>::operator[](int i) const {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->numRows()));
    if(i == 0) return this->row1;
    else if(i == 1) return this->row2;
    else if(i == 2) return this->row3;
    return this->row4;
}

template<typename T>
vector2<T>& matrix2<T>::operator[](int i) {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->numRows()));
    if(i == 0) return this->row1;
    return this->row2;
}

template<typename T>
vector3<T>& matrix3<T>::operator[](int i) {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->numRows()));
    if(i == 0) return this->row1;
    else if(i == 1) return this->row2;
    return this->row3;
}

template<typename T>
vector4<T>& matrix4<T>::operator[](int i) {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->numRows()));
    if(i == 0) return this->row1;
    else if(i == 1) return this->row2;
    else if(i == 2) return this->row3;
    return this->row4;
}

} //namespace ggl