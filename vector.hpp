#include <stdlib.h>

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

};

}