#include "quaternion.hpp"

namespace ggl {

template<std::floating_type T>
constexpr quaternion<T>::quaternion() {
    this->w = 0;
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

template<std::floating_point T>
constexpr quaternion<T>::quaternion(T w, T x, T y, T z) {
    this->w = w;
    this->x = x;
    this->y = y;
    this->z = z;
}

template<std::floating_point T>
constexpr quaternion<T>::quaternion(vector<T> const& v) {
    this->w = 0;
    this->x = v.x;
    this->y = 0;
    this->z = 0;
}

template<std::floating_point T>
constexpr quaternion<T>::quaternion(vector2<T> const& v) {
    this->w = 0;
    this->x = v.x;
    this->y = v.y;
    this->z = 0;
}

template<std::floating_point T>
constexpr quaternion<T>::quaternion(vector3<T> const& v) {
    this->w = 0;
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
}

template<std::floating_point T>
constexpr quaternion<T>::quaternion(vector4<T> const& v) {
    this->w = v.w;
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
}

template<std::floating_point T>
constexpr quaternion<T>::quaternion(quaternion<T> const& q) {
    this->w = q.w;
    this->x = q.x;
    this->y = q.y;
    this->z = q.z;
}

template<std::floating_point T>
constexpr quaternion<T> operator+(quaternion<T> const& q, quaternion<T> const& q2) {
    quaternion<T> new_quat(q.w + q2.w, q.x + q2.x, q.y + q2.y, q.z + q2.z);
    return new_quat;
}

template<std::floating_point T>
constexpr quaternion<T> operator-(quaternion<T> const& q, quaternion<T> const& q2) {
    quaternion<T> new_quat(q.w - q2.w, q.x - q2.x, q.y - q2.y, q.z - q2.z);
    return new_quat;
}

template<std::floating_point T>
constexpr quaternion<T> operator*(quaternion<T> const& q, T c) {
    quaternion<T> new_quat(q.w * c, q.x * c, q.y * c, q.z * c);
    return new_quat;
}

template<std::floating_point T>
constexpr quaternion<T> operator*(T c, quaternion<T> const& q) {
    quaternion<T> new_quat(q.w * c, q.x * c, q.y * c, q.z * c);
    return new_quat;
}

template<std::floating_point T>
constexpr quaternion<T> operator/(quaternion<T> const& q, T c) {
    quaternion<T> new_quat(q.w / c, q.x / c, q.y / c, q.z / c);
    return new_quat;
}

template<std::floating_point T>
constexpr quaternion<T> operator/(T c, quaternion<T> const& q) {
    quaternion<T> new_quat(q.w / c, q.x / c, q.y / c, q.z / c);
    return new_quat;
}

template<std::floating_point T>
constexpr quaternion<T> operator*(quaternion<T> const& q, quaternion<T> const& q2) {
    quaternion<T> new_quat();
    new_quat.w = (q.w * q2.w) - (q.x * q2.x) - (q.y * q2.y) - (q.z * q2.z);
    new_quat.x = (q.w * q2.x) + (q.x * q2.w) + (q.y * q2.z) - (q.z * q2.y);
    new_quat.y = (q.w * q2.y) - (q.x * q2.z) + (q.y * q2.w) + (q.z * q2.x);
    new_quat.z = (q.w * q2.z) + (q.x * q2.y) - (q.y * q2.x) + (q.z * q2.w);
    return new_quat;
}

template<std::floating_point T>
constexpr T mag(quaternion<T> const& q) {
    return sqrt(w*w + x*x + y*y + z*z); 
}

template<std::floating_point T>
constexpr quaternion<T> norm(quaternion<T> const& q) {
    return q / mag(q);
}

}