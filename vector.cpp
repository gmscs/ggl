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

/* += */
template<typename T>
template<typename N>
vector<T>& vector<T>::operator+=(vector<N> const &v) {
    this->x += static_cast<T>(v.x);
    return *this;
}

template<typename T>
template<typename N>
vector2<T>& vector2<T>::operator+=(vector2<N> const &v) {
    this->x += static_cast<T>(v.x);
    this->y += static_cast<T>(v.y);
    return *this;
}

template<typename T>
template<typename N>
vector3<T>& vector3<T>::operator+=(vector3<N> const &v) {
    this->x += static_cast<T>(v.x);
    this->y += static_cast<T>(v.y);
    this->z += static_cast<T>(v.z);
    return *this;
}

template<typename T>
template<typename N>
vector4<T>& vector4<T>::operator+=(vector4<N> const &v) {
    this->x += static_cast<T>(v.x);
    this->y += static_cast<T>(v.y);
    this->z += static_cast<T>(v.z);
    this->w += static_cast<T>(v.w);
    return *this;
}

/* -= */
template<typename T>
template<typename N>
vector<T>& vector<T>::operator-=(vector<N> const &v) {
    this->x -= static_cast<T>(v.x);
    return *this;
}

template<typename T>
template<typename N>
vector2<T>& vector2<T>::operator-=(vector2<N> const &v) {
    this->x -= static_cast<T>(v.x);
    this->y -= static_cast<T>(v.y);
    return *this;
}

template<typename T>
template<typename N>
vector3<T>& vector3<T>::operator-=(vector3<N> const &v) {
    this->x -= static_cast<T>(v.x);
    this->y -= static_cast<T>(v.y);
    this->z -= static_cast<T>(v.z);
    return *this;
}

template<typename T>
template<typename N>
vector4<T>& vector4<T>::operator-=(vector4<N> const &v) {
    this->x -= static_cast<T>(v.x);
    this->y -= static_cast<T>(v.y);
    this->z -= static_cast<T>(v.z);
    this->w -= static_cast<T>(v.w);
    return *this;
}

/* *= */
template<typename T>
template<typename N>
vector<T>& vector<T>::operator*=(N c) {
    this->x *= static_cast<T>(c);
    return *this;
}

template<typename T>
template<typename N>
vector2<T>& vector2<T>::operator*=(N c) {
    this->x *= static_cast<T>(c);
    this->y *= static_cast<T>(c);
    return *this;
}

template<typename T>
template<typename N>
vector3<T>& vector3<T>::operator*=(N c) {
    this->x *= static_cast<T>(c);
    this->y *= static_cast<T>(c);
    this->z *= static_cast<T>(c);
    return *this;
}

template<typename T>
template<typename N>
vector4<T>& vector4<T>::operator*=(N c) {
    this->x *= static_cast<T>(c);
    this->y *= static_cast<T>(c);
    this->z *= static_cast<T>(c);
    this->w *= static_cast<T>(c);
    return *this;
}

/* /= */
template<typename T>
template<typename N>
vector<T>& vector<T>::operator/=(N c) {
    this->x /= static_cast<T>(c);
    return *this;
}

template<typename T>
template<typename N>
vector2<T>& vector2<T>::operator/=(N c) {
    this->x /= static_cast<T>(c);
    this->y /= static_cast<T>(c);
    return *this;
}

template<typename T>
template<typename N>
vector3<T>& vector3<T>::operator/=(N c) {
    this->x /= static_cast<T>(c);
    this->y /= static_cast<T>(c);
    this->z /= static_cast<T>(c);
    return *this;
}

template<typename T>
template<typename N>
vector4<T>& vector4<T>::operator/=(N c) {
    this->x /= static_cast<T>(c);
    this->y /= static_cast<T>(c);
    this->z /= static_cast<T>(c);
    this->w /= static_cast<T>(c);
    return *this;
}

/* Sign flip */
template<typename T>
vector<T> operator-(vector<T> const &v) {
    vector<T> new_vec;
    new_vec.x = -v.x;
    return new_vec;
}

template<typename T>
vector2<T> operator-(vector2<T> const &v) {
    vector2<T> new_vec;
    new_vec.x = -v.x;
    new_vec.y = -v.y;
    return new_vec;
}

template<typename T>
vector3<T> operator-(vector3<T> const &v) {
    vector3<T> new_vec;
    new_vec.x = -v.x;
    new_vec.y = -v.y;
    new_vec.z = -v.z;
    return new_vec;
}

template<typename T>
vector4<T> operator-(vector4<T> const &v) {
    vector4<T> new_vec;
    new_vec.x = -v.x;
    new_vec.y = -v.y;
    new_vec.z = -v.z;
    new_vec.w = -v.w;
    return new_vec;
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

/* Multiplication */
template<typename T, typename N>
vector<T> operator*(vector<T> const &v, N c) {
    vector<T> new_vec;
    new_vec.x = v.x * c;
    return new_vec;
}

template<typename T, typename N>
vector2<T> operator*(vector2<T> const &v, N c) {
    vector<T> new_vec;
    new_vec.x = v.x * c;
    new_vec.y = v.y * c;
    return new_vec;
}

template<typename T, typename N>
vector3<T> operator*(vector3<T> const &v, N c) {
    vector3<T> new_vec;
    new_vec.x = v.x * c;
    new_vec.y = v.y * c;
    new_vec.z = v.z * c;
    return new_vec;
}

template<typename T, typename N>
vector4<T> operator*(vector4<T> const &v, N c) {
    vector4<T> new_vec;
    new_vec.x = v.x * c;
    new_vec.y = v.y * c;
    new_vec.z = v.z * c;
    new_vec.w = v.w * c;
    return new_vec;
}

/* Division */
template<typename T, typename N>
vector<T> operator/(vector<T> const &v, N c) {
    assert((void("division only accepts floating point parameters"), std::numeric_limits<T>::is_iec559));
    vector<T> new_vec;
    new_vec.x = v.x / c;
    return new_vec;
}

template<typename T, typename N>
vector2<T> operator/(vector2<T> const &v, N c) {
    assert((void("division only accepts floating point parameters"), std::numeric_limits<T>::is_iec559));
    vector<T> new_vec;
    new_vec.x = v.x / c;
    new_vec.y = v.y / c;
    return new_vec;
}

template<typename T, typename N>
vector3<T> operator/(vector3<T> const &v, N c) {
    assert((void("division only accepts floating point parameters"), std::numeric_limits<T>::is_iec559));
    vector3<T> new_vec;
    new_vec.x = v.x / c;
    new_vec.y = v.y / c;
    new_vec.z = v.z / c;
    return new_vec;
}

template<typename T, typename N>
vector4<T> operator/(vector4<T> const &v, N c) {
    assert((void("division only accepts floating point parameters"), std::numeric_limits<T>::is_iec559));
    vector4<T> new_vec;
    new_vec.x = v.x / c;
    new_vec.y = v.y / c;
    new_vec.z = v.z / c;
    new_vec.w = v.w / c;
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

/* Bool operators */
template<typename T>
bool operator==(vector<T> const &v, vector<T> const &b) {
    return v.x == b.x;
}

template<typename T>
bool operator==(vector2<T> const &v, vector2<T> const &b) {
    if(v.x == b.x && v.y == b.y) {
        return true;
    }
    return false;
}

template<typename T>
bool operator==(vector3<T> const &v, vector3<T> const &b) {
    if(v.x == b.x && v.y == b.y && v.z == b.z) {
        return true;
    }
    return false;
}

template<typename T>
bool operator==(vector4<T> const &v, vector4<T> const &b) {
    if(v.x == b.x && v.y == b.y && v.z == b.z && v.w == b.w) {
        return true;
    }
    return false;
}

template<typename T>
bool operator!=(vector<T> const &v, vector<T> const &b) {
    return !(v == b);
}

template<typename T>
bool operator!=(vector2<T> const &v, vector2<T> const &b) {
    return !(v == b);
}

template<typename T>
bool operator!=(vector3<T> const &v, vector3<T> const &b) {
    return !(v == b);
}

template<typename T>
bool operator!=(vector4<T> const &v, vector4<T> const &b) {
    return !(v == b);
}

/* Brackets */
template<typename T>
T const& vector<T>::operator[](int i) const {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->length()));
    return this->x;
}

template<typename T>
T const& vector2<T>::operator[](int i) const {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->length()));
    if(i == 0) return this->x;
    return this->y;
}

template<typename T>
T const& vector3<T>::operator[](int i) const {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->length()));
    if(i == 0) return this->x;
    else if(i == 1) return this->y;
    return this->z;
}

template<typename T>
T const& vector4<T>::operator[](int i) const {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->length()));
    if(i == 0) return this->x;
    else if(i == 1) return this->y;
    else if(i == 2) return this->z;
    return this->w;
}

template<typename T>
T& vector<T>::operator[](int i) {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->length()));
    return this->x;
}

template<typename T>
T& vector2<T>::operator[](int i) {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->length()));
    if(i == 0) return this->x;
    return this->y;
}

template<typename T>
T& vector3<T>::operator[](int i) {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->length()));
    if(i == 0) return this->x;
    else if(i == 1) return this->y;
    return this->z;
}

template<typename T>
T& vector4<T>::operator[](int i) {
    assert((void("index cannot be less than 0"), i >= 0));
    assert((void("index exceeds vector size"), i < this->length()));
    if(i == 0) return this->x;
    else if(i == 1) return this->y;
    else if(i == 2) return this->z;
    return this->w;
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

/* Angle between 2 vectors */
template<typename T>
float angle(vector2<T>& v, vector2<T>& b) {
    vector2<T> normalized_v = normalize(v);
    vector2<T> normalized_b = normalize(b);
    
    return std::acos(v * b);
}

template<typename T>
float angle(vector3<T>& v, vector3<T>& b) {
    vector3<T> normalized_v = normalize(v);
    vector3<T> normalized_b = normalize(b);
    
    return std::acos(v * b);
}

template<typename T>
float angle(vector4<T>& v, vector4<T>& b) {
    vector4<T> normalized_v = normalize(v);
    vector4<T> normalized_b = normalize(b);
    
    return std::acos(v * b);
}

/* Cross product */
template<typename T>
float cross(vector2<T>& v, vector2<T>& b) {
    return (v.x * b.y) - (v.y * b.x);
}

template<typename T>
vector3<T> cross(vector3<T>& v, vector3<T>& b) {
    vector3<T> new_vec;
    new_vec.x = (v.y * b.z) - (v.z * b.y);
    new_vec.y = (v.z * b.x) - (v.x * b.z);
    new_vec.z = (v.x * b.y) - (v.y * b.x);
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