#include <stdlib.h>
#include <sstream>

namespace ggl {

template<typename T>
struct vector {
    T x;

    vector();
    vector(vector const& v);
    explicit vector(T c);

    static inline constexpr int length() {
        return 1;
    }

    template<typename N>
    vector<T>& operator=(vector<N> const& v);
    template<typename N>
    vector<T>& operator+=(vector<N> const& v);
    template<typename N>
    vector<T>& operator-=(vector<N> const& v);
    template<typename N>
    vector<T>& operator*=(N c);
    template<typename N>
    vector<T>& operator/=(N c);

};

template<typename T>
struct vector2 {
    T x;
    T y;

    vector2();
    vector2(vector2 const& v);
    explicit vector2(T a, T b);

    static inline constexpr int length() {
        return 2;
    }

    template<typename N>
    vector2<T>& operator=(vector2<N> const& v);
    template<typename N>
    vector2<T>& operator+=(vector2<N> const& v);
    template<typename N>
    vector2<T>& operator-=(vector2<N> const& v);
    template<typename N>
    vector2<T>& operator*=(N c);
    template<typename N>
    vector2<T>& operator/=(N c);

};

template<typename T>
struct vector3 {
    T x;
    T y;
    T z;

    vector3();
    vector3(vector3 const& v);
    explicit vector3(T a, T b, T c);

    static inline constexpr int length() {
        return 3;
    }

    template<typename N>
    vector3<T>& operator=(vector3<N> const& v);
    template<typename N>
    vector3<T>& operator+=(vector3<N> const& v);
    template<typename N>
    vector3<T>& operator-=(vector3<N> const& v);
    template<typename N>
    vector3<T>& operator*=(N c);
    template<typename N>
    vector3<T>& operator/=(N c);

};

template<typename T>
struct vector4 {
    T x;
    T y;
    T z;
    T w;

    vector4();
    vector4(vector4 const& v);
    explicit vector4(T a, T b, T c, T d);

    static inline constexpr int length() {
        return 4;
    }

    template<typename N>
    vector4<T>& operator=(vector4<N> const& v);
    template<typename N>
    vector4<T>& operator+=(vector4<N> const& v);
    template<typename N>
    vector4<T>& operator-=(vector4<N> const& v);
    template<typename N>
    vector4<T>& operator*=(N c);
    template<typename N>
    vector4<T>& operator/=(N c);

};

/* Sign flip */
template<typename T>
vector<T> operator-(vector<T> const& v);
template<typename T>
vector2<T> operator-(vector2<T> const& v);
template<typename T>
vector3<T> operator-(vector3<T> const& v);
template<typename T>
vector4<T> operator-(vector4<T> const& v);

/* Addition */
template<typename T>
vector<T> operator+(vector<T> const& v, vector<T> const& v2);
template<typename T>
vector2<T> operator+(vector2<T> const& v, vector2<T> const& v2);
template<typename T>
vector3<T> operator+(vector3<T> const& v, vector3<T> const& v2);
template<typename T>
vector4<T> operator+(vector4<T> const& v, vector4<T> const& v2);

/* Subtraction */
template<typename T>
vector<T> operator-(vector<T> const& v, vector<T> const& v2);
template<typename T>
vector2<T> operator-(vector2<T> const& v, vector2<T> const& v2);
template<typename T>
vector3<T> operator-(vector3<T> const& v, vector3<T> const& v2);
template<typename T>
vector4<T> operator-(vector4<T> const& v, vector4<T> const& v2);

/* Multiplication */
template<typename T, typename N>
vector<T> operator*(vector<T> const &v, N c);
template<typename T, typename N>
vector2<T> operator*(vector2<T> const &v, N c);
template<typename T, typename N>
vector3<T> operator*(vector3<T> const &v, N c);
template<typename T, typename N>
vector4<T> operator*(vector4<T> const &v, N c);

/* Division */ // TODO: types
template<typename T, typename N>
vector<T> operator/(vector<T> const &v, N c);
template<typename T, typename N>
vector2<T> operator/(vector2<T> const &v, N c);
template<typename T, typename N>
vector3<T> operator/(vector3<T> const &v, N c);
template<typename T, typename N>
vector4<T> operator/(vector4<T> const &v, N c);

/* Dot product */
template<typename T>
T dot(vector<T>& v, vector<T>& b);
template<typename T>
T dot(vector2<T>& v, vector2<T>& b);
template<typename T>
T dot(vector3<T>& v, vector3<T>& b);
template<typename T>
T dot(vector4<T>& v, vector4<T>& b);
template<typename T>
T operator*(vector<T> const& v, vector<T> const& v2);
template<typename T>
T operator*(vector2<T> const& v, vector2<T> const& v2);
template<typename T>
T operator*(vector3<T> const& v, vector3<T> const& v2);
template<typename T>
T operator*(vector4<T> const& v, vector4<T> const& v2);

/* Bool operators */
template<typename T>
bool operator==(vector<T> const &v, vector<T> const &b);
template<typename T>
bool operator==(vector2<T> const &v, vector2<T> const &b);
template<typename T>
bool operator==(vector3<T> const &v, vector3<T> const &b);
template<typename T>
bool operator==(vector4<T> const &v, vector4<T> const &b);
template<typename T>
bool operator!=(vector<T> const &v, vector<T> const &b);
template<typename T>
bool operator!=(vector2<T> const &v, vector2<T> const &b);
template<typename T>
bool operator!=(vector3<T> const &v, vector3<T> const &b);
template<typename T>
bool operator!=(vector4<T> const &v, vector4<T> const &b);

/* Magnitude */
template<typename T>
T mag(vector<T>& v);
template<typename T>
T mag(vector2<T>& v);
template<typename T>
T mag(vector3<T>& v);
template<typename T>
T mag(vector4<T>& v);

/* Normalize */
template<typename T>
vector<T> normalize(vector<T>& v);
template<typename T>
vector2<T> normalize(vector2<T>& v);
template<typename T>
vector3<T> normalize(vector3<T>& v);
template<typename T>
vector4<T> normalize(vector4<T>& v);

/* Angle */
template<typename T>
float angle(vector2<T>& v, vector2<T>& b);
template<typename T>
float angle(vector3<T>& v, vector3<T>& b);
template<typename T>
float angle(vector4<T>& v, vector4<T>& b);

/* Cross product */
template<typename T>
float cross(vector2<T>& v, vector2<T>& b);
template<typename T>
vector3<T> cross(vector3<T>& v, vector3<T>& b);

/* Vector to string */
template<typename T>
std::string to_string(vector<T>& v);
template<typename T>
std::string to_string(vector2<T>& v);
template<typename T>
std::string to_string(vector3<T>& v);
template<typename T>
std::string to_string(vector4<T>& v);

}