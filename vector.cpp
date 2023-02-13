#include "vector.hpp"

namespace ggl {

template<typename T>
vector<T>::vector() {
    this->x = 0;
}

template<typename T>
vector2<T>::vector2() {
    this->x = 0;
    this->y = 0;
}

template<typename T>
vector3<T>::vector3() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

template<typename T>
vector4<T>::vector4() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->w = 0;
}

template<typename T>
vector<T>::vector(T a) {
    this->x = a;
}

template<typename T>
vector2<T>::vector2(T a, T b) {
    this->x = a;
    this->y = b;
}

template<typename T>
vector3<T>::vector3(T a, T b, T c) {
    this->x = a;
    this->y = b;
    this->z = c;
}

template<typename T>
vector4<T>::vector4(T a, T b, T c, T d) {
    this->x = a;
    this->y = b;
    this->z = c;
    this->w = d;
}

template<typename T>
T dot(vector<T>& v, vector<T>& b) {
    return v.x * b.x;
}

template<typename T>
T dot(vector2<T>& v, vector2<T>& b) {
    return (v.x * b.x) + (v.y * b.y);
}

template<typename T>
T dot(vector3<T>& v, vector3<T>& b) {
    return (v.x * b.x) + (v.y * b.y) + (v.z * b.z);
}

template<typename T>
T dot(vector4<T>& v, vector4<T>& b) {
    return (v.x * b.x) + (v.y * b.y) + (v.z * b.z) + (v.w * b.w);
}

template<typename T>
template<typename N>
vector<T>& vector<T>::operator=(vector<N> const &v) {
    this->x = static_cast<T>(v.x);
    return *this;
}

template<typename T>
template<typename N>
vector2<T>& vector2<T>::operator=(vector2<N> const &v) {
    this->x = static_cast<T>(v.x);
    this->y = static_cast<T>(v.y);
    return *this;
}

template<typename T>
template<typename N>
vector3<T>& vector3<T>::operator=(vector3<N> const &v) {
    this->x = static_cast<T>(v.x);
    this->y = static_cast<T>(v.y);
    this->z = static_cast<T>(v.z);
    return *this;
}

template<typename T>
template<typename N>
vector4<T>& vector4<T>::operator=(vector4<N> const &v) {
    this->x = static_cast<T>(v.x);
    this->y = static_cast<T>(v.y);
    this->z = static_cast<T>(v.z);
    this->w = static_cast<T>(v.w);
    return *this;
}

}//namespace ggl