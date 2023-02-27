#include "vector.hpp"

namespace ggl {

template<typename T>
constexpr vector<T>::vector() {
    this->x = 0;
}

template<typename T>
constexpr vector2<T>::vector2() {
    this->x = 0;
    this->y = 0;
}

template<typename T>
constexpr vector3<T>::vector3() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

template<typename T>
constexpr vector4<T>::vector4() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->w = 0;
}

template<typename T>
constexpr vector<T>::vector(vector<T> const &v) {
    this->x = v.x;
}

template<typename T>
constexpr vector2<T>::vector2(vector2<T> const &v) {
    this->x = v.x;
    this->y = v.y;
}

template<typename T>
constexpr vector3<T>::vector3(vector3<T> const &v) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
}

template<typename T>
constexpr vector4<T>::vector4(vector4<T> const &v) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    this->w = v.w;
}

template<typename T>
constexpr vector<T>::vector(T a) {
    this->x = a;
}

template<typename T>
constexpr vector2<T>::vector2(T a, T b) {
    this->x = a;
    this->y = b;
}

template<typename T>
constexpr vector3<T>::vector3(T a, T b, T c) {
    this->x = a;
    this->y = b;
    this->z = c;
}

template<typename T>
constexpr vector4<T>::vector4(T a, T b, T c, T d) {
    this->x = a;
    this->y = b;
    this->z = c;
    this->w = d;
}

template<typename T>
template<typename N>
constexpr vector<T>& vector<T>::operator=(vector<N> const &v) {
    this->x = static_cast<T>(v.x);
    return *this;
}

template<typename T>
template<typename N>
constexpr vector2<T>& vector2<T>::operator=(vector2<N> const &v) {
    this->x = static_cast<T>(v.x);
    this->y = static_cast<T>(v.y);
    return *this;
}

template<typename T>
template<typename N>
constexpr vector3<T>& vector3<T>::operator=(vector3<N> const &v) {
    this->x = static_cast<T>(v.x);
    this->y = static_cast<T>(v.y);
    this->z = static_cast<T>(v.z);
    return *this;
}

template<typename T>
template<typename N>
constexpr vector4<T>& vector4<T>::operator=(vector4<N> const &v) {
    this->x = static_cast<T>(v.x);
    this->y = static_cast<T>(v.y);
    this->z = static_cast<T>(v.z);
    this->w = static_cast<T>(v.w);
    return *this;
}

/* += */
template<typename T>
template<typename N>
constexpr vector<T>& vector<T>::operator+=(vector<N> const &v) {
    this->x += static_cast<T>(v.x);
    return *this;
}

template<typename T>
template<typename N>
constexpr vector2<T>& vector2<T>::operator+=(vector2<N> const &v) {
    this->x += static_cast<T>(v.x);
    this->y += static_cast<T>(v.y);
    return *this;
}

template<typename T>
template<typename N>
constexpr vector3<T>& vector3<T>::operator+=(vector3<N> const &v) {
    this->x += static_cast<T>(v.x);
    this->y += static_cast<T>(v.y);
    this->z += static_cast<T>(v.z);
    return *this;
}

template<typename T>
template<typename N>
constexpr vector4<T>& vector4<T>::operator+=(vector4<N> const &v) {
    this->x += static_cast<T>(v.x);
    this->y += static_cast<T>(v.y);
    this->z += static_cast<T>(v.z);
    this->w += static_cast<T>(v.w);
    return *this;
}

/* -= */
template<typename T>
template<typename N>
constexpr vector<T>& vector<T>::operator-=(vector<N> const &v) {
    this->x -= static_cast<T>(v.x);
    return *this;
}

template<typename T>
template<typename N>
constexpr vector2<T>& vector2<T>::operator-=(vector2<N> const &v) {
    this->x -= static_cast<T>(v.x);
    this->y -= static_cast<T>(v.y);
    return *this;
}

template<typename T>
template<typename N>
constexpr vector3<T>& vector3<T>::operator-=(vector3<N> const &v) {
    this->x -= static_cast<T>(v.x);
    this->y -= static_cast<T>(v.y);
    this->z -= static_cast<T>(v.z);
    return *this;
}

template<typename T>
template<typename N>
constexpr vector4<T>& vector4<T>::operator-=(vector4<N> const &v) {
    this->x -= static_cast<T>(v.x);
    this->y -= static_cast<T>(v.y);
    this->z -= static_cast<T>(v.z);
    this->w -= static_cast<T>(v.w);
    return *this;
}

/* *= */
template<typename T>
template<typename N>
constexpr vector<T>& vector<T>::operator*=(N c) {
    this->x *= static_cast<T>(c);
    return *this;
}

template<typename T>
template<typename N>
constexpr vector2<T>& vector2<T>::operator*=(N c) {
    this->x *= static_cast<T>(c);
    this->y *= static_cast<T>(c);
    return *this;
}

template<typename T>
template<typename N>
constexpr vector3<T>& vector3<T>::operator*=(N c) {
    this->x *= static_cast<T>(c);
    this->y *= static_cast<T>(c);
    this->z *= static_cast<T>(c);
    return *this;
}

template<typename T>
template<typename N>
constexpr vector4<T>& vector4<T>::operator*=(N c) {
    this->x *= static_cast<T>(c);
    this->y *= static_cast<T>(c);
    this->z *= static_cast<T>(c);
    this->w *= static_cast<T>(c);
    return *this;
}

/* /= */
template<typename T>
template<typename N>
constexpr vector<T>& vector<T>::operator/=(N c) {
    this->x /= static_cast<T>(c);
    return *this;
}

template<typename T>
template<typename N>
constexpr vector2<T>& vector2<T>::operator/=(N c) {
    this->x /= static_cast<T>(c);
    this->y /= static_cast<T>(c);
    return *this;
}

template<typename T>
template<typename N>
constexpr vector3<T>& vector3<T>::operator/=(N c) {
    this->x /= static_cast<T>(c);
    this->y /= static_cast<T>(c);
    this->z /= static_cast<T>(c);
    return *this;
}

template<typename T>
template<typename N>
constexpr vector4<T>& vector4<T>::operator/=(N c) {
    this->x /= static_cast<T>(c);
    this->y /= static_cast<T>(c);
    this->z /= static_cast<T>(c);
    this->w /= static_cast<T>(c);
    return *this;
}

/* Sign flip */
template<typename T>
constexpr vector<T> operator-(vector<T> const &v) {
    vector<T> new_vec(-v.x);
    return new_vec;
}

template<typename T>
constexpr vector2<T> operator-(vector2<T> const &v) {
    vector2<T> new_vec(-v.x, -v.y);
    return new_vec;
}

template<typename T>
constexpr vector3<T> operator-(vector3<T> const &v) {
    vector3<T> new_vec(-v.x, -v.y, -v.z);
    return new_vec;
}

template<typename T>
constexpr vector4<T> operator-(vector4<T> const &v) {
    vector4<T> new_vec(-v.x, -v.y, -v.z, -v.w);
    return new_vec;
}

/* Addition */
template<typename T>
constexpr vector<T> operator+(vector<T> const &v, vector<T> const& v2) {
    vector<T> new_vec(v.x + v2.x);
    return new_vec;
}

template<typename T>
constexpr vector2<T> operator+(vector2<T> const &v, vector2<T> const& v2) {
    vector2<T> new_vec(v.x + v2.x, v.y + v2.y);
    return new_vec;
}

template<typename T>
constexpr vector3<T> operator+(vector3<T> const &v, vector3<T> const& v2) {
    vector3<T> new_vec(v.x + v2.x, v.y + v2.y, v.z + v2.z);
    return new_vec;
}

template<typename T>
constexpr vector4<T> operator+(vector4<T> const &v, vector4<T> const& v2) {
    vector4<T> new_vec(v.x + v2.x, v.y + v2.y, v.z + v2.z, v.w + v2.w);
    return new_vec;
}

/* Subtraction */
template<typename T>
constexpr vector<T> operator-(vector<T> const &v, vector<T> const& v2) {
    vector<T> new_vec(v.x - v2.x);
    return new_vec;
}

template<typename T>
constexpr vector2<T> operator-(vector2<T> const &v, vector2<T> const& v2) {
    vector2<T> new_vec(v.x - v2.x, v.y - v2.y);
    return new_vec;
}

template<typename T>
constexpr vector3<T> operator-(vector3<T> const &v, vector3<T> const& v2) {
    vector3<T> new_vec(v.x - v2.x, v.y - v2.y, v.z - v2.z);
    return new_vec;
}

template<typename T>
constexpr vector4<T> operator-(vector4<T> const &v, vector4<T> const& v2) {
    vector4<T> new_vec(v.x - v2.x, v.y - v2.y, v.z - v2.z, v.w - v2.w);
    return new_vec;
}

/* Multiplication */
template<typename T, typename N>
constexpr vector<T> operator*(vector<T> const &v, N c) {
    vector<T> new_vec(v.x * c);
    return new_vec;
}

template<typename T, typename N>
constexpr vector2<T> operator*(vector2<T> const &v, N c) {
    vector<T> new_vec(v.x * c, v.y * c);
    return new_vec;
}

template<typename T, typename N>
constexpr vector3<T> operator*(vector3<T> const &v, N c) {
    vector3<T> new_vec(v.x * c, v.y * c, v.z * c);
    return new_vec;
}

template<typename T, typename N>
constexpr vector4<T> operator*(vector4<T> const &v, N c) {
    vector4<T> new_vec(v.x * c, v.y * c, v.z * c, v.w * c);
    return new_vec;
}

/* Division */
template<typename T, typename N>
constexpr vector<T> operator/(vector<T> const &v, N c) {
    assert((void("division only accepts floating point parameters"), std::numeric_limits<T>::is_iec559));
    vector<T> new_vec(v.x / c);
    return new_vec;
}

template<typename T, typename N>
constexpr vector2<T> operator/(vector2<T> const &v, N c) {
    assert((void("division only accepts floating point parameters"), std::numeric_limits<T>::is_iec559));
    vector<T> new_vec(v.x / c, v.y / c);
    return new_vec;
}

template<typename T, typename N>
constexpr vector3<T> operator/(vector3<T> const &v, N c) {
    assert((void("division only accepts floating point parameters"), std::numeric_limits<T>::is_iec559));
    vector3<T> new_vec(v.x / c, v.y / c, v.z / c);
    return new_vec;
}

template<typename T, typename N>
constexpr vector4<T> operator/(vector4<T> const &v, N c) {
    assert((void("division only accepts floating point parameters"), std::numeric_limits<T>::is_iec559));
    vector4<T> new_vec(v.x / c, v.y / c, v.z / c, v.w / c);
    return new_vec;
}

/* Dot product */
template<typename T>
constexpr T dot(vector<T>& v, vector<T>& b) {
    return v.x * b.x;
}

template<typename T>
constexpr T dot(vector2<T>& v, vector2<T>& b) {
    return (v.x * b.x) + (v.y * b.y);
}

template<typename T>
constexpr T dot(vector3<T>& v, vector3<T>& b) {
    return (v.x * b.x) + (v.y * b.y) + (v.z * b.z);
}

template<typename T>
constexpr T dot(vector4<T>& v, vector4<T>& b) {
    return (v.x * b.x) + (v.y * b.y) + (v.z * b.z) + (v.w * b.w);
}

template<typename T>
constexpr T operator*(vector<T> const &v, vector<T> const& b) {
    return v.x * b.x;;
}

template<typename T>
constexpr T operator*(vector2<T> const &v, vector2<T> const& b) {
    return (v.x * b.x) + (v.y * b.y);
}

template<typename T>
constexpr T operator*(vector3<T> const &v, vector3<T> const& b) {
    return (v.x * b.x) + (v.y * b.y) + (v.z * b.z);
}

template<typename T>
constexpr T operator*(vector4<T> const &v, vector4<T> const& b) {
    return (v.x * b.x) + (v.y * b.y) + (v.z * b.z) + (v.w * b.w);
}

/* Bool operators */
template<typename T>
constexpr bool operator==(vector<T> const &v, vector<T> const &b) {
    return v.x == b.x;
}

template<typename T>
constexpr bool operator==(vector2<T> const &v, vector2<T> const &b) {
    if(v.x == b.x && v.y == b.y) {
        return true;
    }
    return false;
}

template<typename T>
constexpr bool operator==(vector3<T> const &v, vector3<T> const &b) {
    if(v.x == b.x && v.y == b.y && v.z == b.z) {
        return true;
    }
    return false;
}

template<typename T>
constexpr bool operator==(vector4<T> const &v, vector4<T> const &b) {
    if(v.x == b.x && v.y == b.y && v.z == b.z && v.w == b.w) {
        return true;
    }
    return false;
}

template<typename T>
constexpr bool operator!=(vector<T> const &v, vector<T> const &b) {
    return !(v == b);
}

template<typename T>
constexpr bool operator!=(vector2<T> const &v, vector2<T> const &b) {
    return !(v == b);
}

template<typename T>
constexpr bool operator!=(vector3<T> const &v, vector3<T> const &b) {
    return !(v == b);
}

template<typename T>
constexpr bool operator!=(vector4<T> const &v, vector4<T> const &b) {
    return !(v == b);
}

/* Brackets */
template<typename T>
constexpr T const& vector<T>::operator[](int i) const {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->length()));
    return this->x;
}

template<typename T>
constexpr T const& vector2<T>::operator[](int i) const {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->length()));
    if(i == 0) return this->x;
    return this->y;
}

template<typename T>
constexpr T const& vector3<T>::operator[](int i) const {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->length()));
    if(i == 0) return this->x;
    else if(i == 1) return this->y;
    return this->z;
}

template<typename T>
constexpr T const& vector4<T>::operator[](int i) const {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->length()));
    if(i == 0) return this->x;
    else if(i == 1) return this->y;
    else if(i == 2) return this->z;
    return this->w;
}

template<typename T>
constexpr T& vector<T>::operator[](int i) {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->length()));
    return this->x;
}

template<typename T>
constexpr T& vector2<T>::operator[](int i) {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->length()));
    if(i == 0) return this->x;
    return this->y;
}

template<typename T>
constexpr T& vector3<T>::operator[](int i) {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->length()));
    if(i == 0) return this->x;
    else if(i == 1) return this->y;
    return this->z;
}

template<typename T>
constexpr T& vector4<T>::operator[](int i) {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->length()));
    if(i == 0) return this->x;
    else if(i == 1) return this->y;
    else if(i == 2) return this->z;
    return this->w;
}
/* Magnitude */
template<typename T>
constexpr T mag(vector<T>& v) {
    return sqrt(v.x * v.x);
}

template<typename T>
constexpr T mag(vector2<T>& v) {
    return sqrt((v.x * v.x) + (v.y * v.y));
}

template<typename T>
constexpr T mag(vector3<T>& v) {
    return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

template<typename T>
constexpr T mag(vector4<T>& v) {
    return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w));
}

/* Normalize */
template<typename T>
constexpr vector<T> normalize(vector<T>& v) {
    vector<T> new_vec(v.x / mag(v));
    return new_vec;
}

template<typename T>
constexpr vector2<T> normalize(vector2<T>& v) {
    vector2<T> new_vec(v.x / mag(v), v.y / mag(v));
    return new_vec;
}

template<typename T>
constexpr vector3<T> normalize(vector3<T>& v) {
    vector3<T> new_vec(v.x / mag(v), v.y / mag(v), v.z / mag(v));
    return new_vec;
}

template<typename T>
constexpr vector4<T> normalize(vector4<T>& v) {
    vector4<T> new_vec(v.x / mag(v), v.y / mag(v), v.z / mag(v), v.w / mag(v));
    return new_vec;
}

/* Angle between 2 vectors */
template<typename T>
constexpr float angle(vector2<T>& v, vector2<T>& b) {
    vector2<T> normalized_v = normalize(v);
    vector2<T> normalized_b = normalize(b);
    
    return std::acos(v * b);
}

template<typename T>
constexpr float angle(vector3<T>& v, vector3<T>& b) {
    vector3<T> normalized_v = normalize(v);
    vector3<T> normalized_b = normalize(b);
    
    return std::acos(v * b);
}

template<typename T>
constexpr float angle(vector4<T>& v, vector4<T>& b) {
    vector4<T> normalized_v = normalize(v);
    vector4<T> normalized_b = normalize(b);
    
    return std::acos(v * b);
}

/* Cross product */
template<typename T>
constexpr float cross(vector2<T>& v, vector2<T>& b) {
    return (v.x * b.y) - (v.y * b.x);
}

template<typename T>
constexpr vector3<T> cross(vector3<T>& v, vector3<T>& b) {
    vector3<T> new_vec((v.y * b.z) - (v.z * b.y), (v.z * b.x) - (v.x * b.z), (v.x * b.y) - (v.y * b.x));
    return new_vec;
}

/* Vector to String */
template<typename T>
constexpr std::string to_string(vector<T> const &v) {
    std::stringstream stream;
    stream << "[" << v.x << "]";
    return stream.str();
}

template<typename T>
constexpr std::string to_string(vector2<T> const &v) {
    std::stringstream stream;
    stream << "[" << v.x << ", " << v.y << "]";
    return stream.str();
}

template<typename T>
constexpr std::string to_string(vector3<T> const &v) {
    std::stringstream stream;
    stream << "[" << v.x << ", " << v.y << ", " << v.z << "]";
    return stream.str();
}

template<typename T>
constexpr std::string to_string(vector4<T> const &v) {
    std::stringstream stream;
    stream << "[" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << "]";
    return stream.str();
}

}//namespace ggl
