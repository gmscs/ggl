namespace ggl {
template<std::floating_point T>
struct quaternion {
    T w;
    T x;
    T y;
    T z;
    
    constexpr quaternion();
    constexpr quaternion(quaternion const& q);
    constexpr quaternion(vector<T> const& v);
    constexpr quaternion(vector2<T> const& v);
    constexpr quaternion(vector3<T> const& v);
    constexpr quaternion(vector4<T> const& v);
    explicit constexpr quaternion(T w, T x, T y, T z);
    
    constexpr quaternion<T>& operator=(quaternion<T> const &q);
    constexpr quaternion<T>& operator+=(quaternion<T> const &q);
    constexpr quaternion<T>& operator-=(quaternion<T> const &q);
    constexpr quaternion<T>& operator*=(quaternion<T> const &q);
    constexpr quaternion<T>& operator/=(quaternion<T> const &q);
    constexpr quaternion<T>& operator*=(T c);
    constexpr quaternion<T>& operator/=(T c);
    
    constexpr T const& operator[](int i) const;
    constexpr T& operator[](int i);
};

template<std::floating_point T>
constexpr quaternion<T> inverse(quaternion<T> const& q);

template<std::floating_point T>
constexpr quaternion<T> norm(quaternion<T> const& q);

template<std::floating_point T>
constexpr T mag(quaternion<T> const& q);

template<std::floating_point T>
constexpr quaternion<T> operator+(quaternion<T> const &q, quaternion<T> const &q2);

template<std::floating_point T>
constexpr quaternion<T> operator-(quaternion<T> const &q, quaternion<T> const &q2);

template<std::floating_point T>
constexpr quaternion<T> operator*(quaternion<T> const &q, quaternion<T> const &q2);

template<std::floating_point T>
constexpr quaternion<T> operator*(quaternion<T> const& q, T c);

template<std::floating_point T>
constexpr quaternion<T> operator*(T c, quaternion<T> const& q);

template<std::floating_point T>
constexpr quaternion<T> operator/(quaternion<T> const& q, quaternion<T> const &q2);

template<std::floating_point T>
constexpr quaternion<T> operator/(quaternion<T> const& q, T c);

template<std::floating_point T>
constexpr quaternion<T> operator/(T c, quaternion<T> const& q);

template<std::floating_point T>
constexpr matrix4<T> quatToMatrix(quaternion<T> const& q);

}