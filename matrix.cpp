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

} //namespace ggl