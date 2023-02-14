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

/* Addition */
template<typename T>
vector<T> operator+(vector<T> const &v, vector<T> const& v2) {
    vector<T> new_vec;
    new_vec.x = v.x + v2.x;
    return new_vec;
}

template<typename T>
vector2<T> operator+(vector2<T> const &v, vector2<T> const& v2) {
    vector2<T> new_vec;
    new_vec.x = v.x + v2.x;
    new_vec.y = v.y + v2.y;
    return new_vec;
}

template<typename T>
vector3<T> operator+(vector3<T> const &v, vector3<T> const& v2) {
    vector3<T> new_vec;
    new_vec.x = v.x + v2.x;
    new_vec.y = v.y + v2.y;
    new_vec.z = v.z + v2.z;
    return new_vec;
}

template<typename T>
vector4<T> operator+(vector4<T> const &v, vector4<T> const& v2) {
    vector4<T> new_vec;
    new_vec.x = v.x + v2.x;
    new_vec.y = v.y + v2.y;
    new_vec.z = v.z + v2.z;
    new_vec.w = v.w + v2.w;
    return new_vec;
}

/* Subtraction */
template<typename T>
vector<T> operator-(vector<T> const &v, vector<T> const& v2) {
    vector<T> new_vec;
    new_vec.x = v.x - v2.x;
    return new_vec;
}

template<typename T>
vector2<T> operator-(vector2<T> const &v, vector2<T> const& v2) {
    vector2<T> new_vec;
    new_vec.x = v.x - v2.x;
    new_vec.y = v.y - v2.y;
    return new_vec;
}

template<typename T>
vector3<T> operator-(vector3<T> const &v, vector3<T> const& v2) {
    vector3<T> new_vec;
    new_vec.x = v.x - v2.x;
    new_vec.y = v.y - v2.y;
    new_vec.z = v.z - v2.z;
    return new_vec;
}

template<typename T>
vector4<T> operator-(vector4<T> const &v, vector4<T> const& v2) {
    vector4<T> new_vec;
    new_vec.x = v.x - v2.x;
    new_vec.y = v.y - v2.y;
    new_vec.z = v.z - v2.z;
    new_vec.w = v.w - v2.w;
    return new_vec;
}

/* Dot product */
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
T operator*(vector<T> const &v, vector<T> const& b) {
    return v.x * b.x;;
}

template<typename T>
T operator*(vector2<T> const &v, vector2<T> const& b) {
    return (v.x * b.x) + (v.y * b.y);
}

template<typename T>
T operator*(vector3<T> const &v, vector3<T> const& b) {
    return (v.x * b.x) + (v.y * b.y) + (v.z * b.z);
}

template<typename T>
T operator*(vector4<T> const &v, vector4<T> const& b) {
    return (v.x * b.x) + (v.y * b.y) + (v.z * b.z) + (v.w * b.w);
}

/* Magnitude */
template<typename T>
T mag(vector<T>& v) {
    return sqrt(v.x * v.x);
}

template<typename T>
T mag(vector2<T>& v) {
    return sqrt((v.x * v.x) + (v.y * v.y));
}

template<typename T>
T mag(vector3<T>& v) {
    return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

template<typename T>
T mag(vector4<T>& v) {
    return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w));
}

/* Normalize */
template<typename T>
vector<T> normalize(vector<T>& v) {
    vector<T> new_vec;
    new_vec.x = v.x / mag(v);
    return new_vec;
}

template<typename T>
vector2<T> normalize(vector2<T>& v) {
    vector2<T> new_vec;
    new_vec.x = v.x / mag(v);
    new_vec.y = v.y / mag(v);
    return new_vec;
}

template<typename T>
vector3<T> normalize(vector3<T>& v) {
    vector3<T> new_vec;
    new_vec.x = v.x / mag(v);
    new_vec.y = v.y / mag(v);
    new_vec.z = v.z / mag(v);
    return new_vec;
}

template<typename T>
vector4<T> normalize(vector4<T>& v) {
    vector4<T> new_vec;
    new_vec.x = v.x / mag(v);
    new_vec.y = v.y / mag(v);
    new_vec.z = v.z / mag(v);
    new_vec.w = v.w / mag(v);
    return new_vec;
}

/* Vector to String */
template<typename T>
std::string to_string(vector<T>& v) {
    std::stringstream stream;
    stream << "[" << v.x << "]";
    return stream.str();
}

template<typename T>
std::string to_string(vector2<T>& v) {
    std::stringstream stream;
    stream << "[" << v.x << ", " << v.y << "]";
    return stream.str();
}

template<typename T>
std::string to_string(vector3<T>& v) {
    std::stringstream stream;
    stream << "[" << v.x << ", " << v.y << ", " << v.z << "]";
    return stream.str();
}

template<typename T>
std::string to_string(vector4<T>& v) {
    std::stringstream stream;
    stream << "[" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << "]";
    return stream.str();
}

}//namespace ggl