namespace ggl {

template<std::floating_point T>
struct vector {
    T x;

    constexpr vector();
    constexpr vector(vector const& v);
    explicit constexpr vector(T c);

    static constexpr int length() {
        return 1;
    }

    static constexpr const char* type() {
        return typeid(T).name();
    }

    template<std::floating_point N>
    constexpr vector<T>& operator=(vector<N> const& v);
    template<std::floating_point N>
    constexpr vector<T>& operator+=(vector<N> const& v);
    template<std::floating_point N>
    constexpr vector<T>& operator-=(vector<N> const& v);
    template<typename N>
    constexpr vector<T>& operator*=(N c);
    template<typename N>
    constexpr vector<T>& operator/=(N c);
    constexpr T const& operator[](int i) const;
    constexpr T& operator[](int i);

};

template<std::floating_point T>
struct vector2 {
    T x;
    T y;

    constexpr vector2();
    constexpr vector2(vector2 const& v);
    explicit constexpr vector2(T a, T b);

    static constexpr int length() {
        return 2;
    }

    static constexpr const char* type() {
        return typeid(T).name();
    }

    template<std::floating_point N>
    constexpr vector2<T>& operator=(vector2<N> const& v);
    template<std::floating_point N>
    constexpr vector2<T>& operator=(vector<N> const &v);
    template<std::floating_point N>
    constexpr vector2<T>& operator+=(vector2<N> const& v);
    template<std::floating_point N>
    constexpr vector2<T>& operator-=(vector2<N> const& v);
    template<typename N>
    constexpr vector2<T>& operator*=(N c);
    template<typename N>
    constexpr vector2<T>& operator/=(N c);
    constexpr T const& operator[](int i) const;
    constexpr T& operator[](int i);

};

template<std::floating_point T>
struct vector3 {
    T x;
    T y;
    T z;

    constexpr vector3();
    constexpr vector3(vector3 const& v);
    explicit constexpr vector3(T a, T b, T c);

    static constexpr int length() {
        return 3;
    }

    static constexpr const char* type() {
        return typeid(T).name();
    }

    template<std::floating_point N>
    constexpr vector3<T>& operator=(vector3<N> const& v);
    template<std::floating_point N>
    constexpr vector3<T>& operator=(vector2<N> const &v);
    template<std::floating_point N>
    constexpr vector3<T>& operator=(vector<N> const &v);
    template<std::floating_point N>
    constexpr vector3<T>& operator+=(vector3<N> const& v);
    template<std::floating_point N>
    constexpr vector3<T>& operator-=(vector3<N> const& v);
    template<typename N>
    constexpr vector3<T>& operator*=(N c);
    template<typename N>
    constexpr vector3<T>& operator/=(N c);
    constexpr T const& operator[](int i) const;
    constexpr T& operator[](int i);

};

template<std::floating_point T>
struct vector4 {
    T x;
    T y;
    T z;
    T w;

    constexpr vector4();
    constexpr vector4(vector4 const& v);
    explicit constexpr vector4(T a, T b, T c, T d);

    static constexpr int length() {
        return 4;
    }

    static constexpr const char* type() {
        return typeid(T).name();
    }

    template<std::floating_point N>
    constexpr vector4<T>& operator=(vector4<N> const& v);
    template<std::floating_point N>
    constexpr vector4<T>& operator=(vector3<N> const& v);
    template<std::floating_point N>
    constexpr vector4<T>& operator=(vector2<N> const& v);
    template<std::floating_point N>
    constexpr vector4<T>& operator=(vector<N> const& v);
    template<std::floating_point N>
    constexpr vector4<T>& operator+=(vector4<N> const& v);
    template<std::floating_point N>
    constexpr vector4<T>& operator-=(vector4<N> const& v);
    template<typename N>
    constexpr vector4<T>& operator*=(N c);
    template<typename N>
    constexpr vector4<T>& operator/=(N c);
    constexpr T const& operator[](int i) const;
    constexpr T& operator[](int i);

};

/* Sign flip */
template<std::floating_point T>
constexpr vector<T> operator-(vector<T> const& v);
template<std::floating_point T>
constexpr vector2<T> operator-(vector2<T> const& v);
template<std::floating_point T>
constexpr vector3<T> operator-(vector3<T> const& v);
template<std::floating_point T>
constexpr vector4<T> operator-(vector4<T> const& v);

/* Addition */
template<std::floating_point T>
constexpr vector<T> operator+(vector<T> const& v, vector<T> const& v2);
template<std::floating_point T>
constexpr vector2<T> operator+(vector2<T> const& v, vector2<T> const& v2);
template<std::floating_point T>
constexpr vector3<T> operator+(vector3<T> const& v, vector3<T> const& v2);
template<std::floating_point T>
constexpr vector4<T> operator+(vector4<T> const& v, vector4<T> const& v2);
template<std::floating_point T, typename N>
constexpr vector<T> operator+(vector<T> const &v, N c);
template<std::floating_point T, typename N>
constexpr vector2<T> operator+(vector2<T> const &v, N c);
template<std::floating_point T, typename N>
constexpr vector3<T> operator+(vector3<T> const &v, N c);
template<std::floating_point T, typename N>
constexpr vector4<T> operator+(vector4<T> const &v, N c);
template<std::floating_point T, typename N>
constexpr vector<T> operator+(N c, vector<T> const &v);
template<std::floating_point T, typename N>
constexpr vector2<T> operator+(N c, vector2<T> const &v);
template<std::floating_point T, typename N>
constexpr vector3<T> operator+(N c, vector3<T> const &v);
template<std::floating_point T, typename N>
constexpr vector4<T> operator+(N c, vector4<T> const &v);

/* Subtraction */
template<std::floating_point T>
constexpr vector<T> operator-(vector<T> const& v, vector<T> const& v2);
template<std::floating_point T>
constexpr vector2<T> operator-(vector2<T> const& v, vector2<T> const& v2);
template<std::floating_point T>
constexpr vector3<T> operator-(vector3<T> const& v, vector3<T> const& v2);
template<std::floating_point T>
constexpr vector4<T> operator-(vector4<T> const& v, vector4<T> const& v2);
template<std::floating_point T, typename N>
constexpr vector<T> operator-(vector<T> const &v, N c);
template<std::floating_point T, typename N>
constexpr vector2<T> operator-(vector2<T> const &v, N c);
template<std::floating_point T, typename N>
constexpr vector3<T> operator-(vector3<T> const &v, N c);
template<std::floating_point T, typename N>
constexpr vector4<T> operator-(vector4<T> const &v, N c);
template<std::floating_point T, typename N>
constexpr vector<T> operator-(N c, vector<T> const &v);
template<std::floating_point T, typename N>
constexpr vector2<T> operator-(N c, vector2<T> const &v);
template<std::floating_point T, typename N>
constexpr vector3<T> operator-(N c, vector3<T> const &v);
template<std::floating_point T, typename N>
constexpr vector4<T> operator-(N c, vector4<T> const &v);

/* Multiplication */
template<std::floating_point T, typename N>
constexpr vector<T> operator*(vector<T> const &v, N c);
template<std::floating_point T, typename N>
constexpr vector2<T> operator*(vector2<T> const &v, N c);
template<std::floating_point T, typename N>
constexpr vector3<T> operator*(vector3<T> const &v, N c);
template<std::floating_point T, typename N>
constexpr vector4<T> operator*(vector4<T> const &v, N c);

/* Division */
template<std::floating_point T, typename N>
constexpr vector<T> operator/(vector<T> const &v, N c);
template<std::floating_point T, typename N>
constexpr vector2<T> operator/(vector2<T> const &v, N c);
template<std::floating_point T, typename N>
constexpr vector3<T> operator/(vector3<T> const &v, N c);
template<std::floating_point T, typename N>
constexpr vector4<T> operator/(vector4<T> const &v, N c);

/* Dot product */
template<std::floating_point T>
constexpr T dot(vector<T>& v, vector<T>& b);
template<std::floating_point T>
constexpr T dot(vector2<T>& v, vector2<T>& b);
template<std::floating_point T>
constexpr T dot(vector3<T>& v, vector3<T>& b);
template<std::floating_point T>
constexpr T dot(vector4<T>& v, vector4<T>& b);
template<std::floating_point T>
constexpr T operator*(vector<T> const& v, vector<T> const& v2);
template<std::floating_point T>
constexpr T operator*(vector2<T> const& v, vector2<T> const& v2);
template<std::floating_point T>
constexpr T operator*(vector3<T> const& v, vector3<T> const& v2);
template<std::floating_point T>
constexpr T operator*(vector4<T> const& v, vector4<T> const& v2);

/* Bool operators */
template<std::floating_point T>
constexpr bool operator==(vector<T> const &v, vector<T> const &b);
template<std::floating_point T>
constexpr bool operator==(vector2<T> const &v, vector2<T> const &b);
template<std::floating_point T>
constexpr bool operator==(vector3<T> const &v, vector3<T> const &b);
template<std::floating_point T>
constexpr bool operator==(vector4<T> const &v, vector4<T> const &b);
template<std::floating_point T>
constexpr bool operator!=(vector<T> const &v, vector<T> const &b);
template<std::floating_point T>
constexpr bool operator!=(vector2<T> const &v, vector2<T> const &b);
template<std::floating_point T>
constexpr bool operator!=(vector3<T> const &v, vector3<T> const &b);
template<std::floating_point T>
constexpr bool operator!=(vector4<T> const &v, vector4<T> const &b);

/* Magnitude */
template<std::floating_point T>
constexpr T mag(vector<T> const& v);
template<std::floating_point T>
constexpr T mag(vector2<T> const& v);
template<std::floating_point T>
constexpr T mag(vector3<T> const& v);
template<std::floating_point T>
constexpr T mag(vector4<T> const& v);

/* Normalize */
template<std::floating_point T>
constexpr vector<T> normalize(vector<T> const& v);
template<std::floating_point T>
constexpr vector2<T> normalize(vector2<T> const& v);
template<std::floating_point T>
constexpr vector3<T> normalize(vector3<T> const& v);
template<std::floating_point T>
constexpr vector4<T> normalize(vector4<T> const& v);

/* Angle */
template<std::floating_point T>
constexpr float angle(vector2<T>& v, vector2<T>& b);
template<std::floating_point T>
constexpr float angle(vector3<T>& v, vector3<T>& b);
template<std::floating_point T>
constexpr float angle(vector4<T>& v, vector4<T>& b);

/* Cross product */
template<std::floating_point T>
constexpr T cross(vector2<T>& v, vector2<T>& b);
template<std::floating_point T>
constexpr vector3<T> cross(vector3<T>& v, vector3<T>& b);

/* Vector to string */
template<std::floating_point T>
constexpr std::string to_string(vector<T> const &v);
template<std::floating_point T>
constexpr std::string to_string(vector2<T> const &v);
template<std::floating_point T>
constexpr std::string to_string(vector3<T> const &v);
template<std::floating_point T>
constexpr std::string to_string(vector4<T> const &v);

/* Translation */
template<std::floating_point T, std::floating_point N>
constexpr vector2<T> translate(vector2<T> const &v, vector2<N> const &d);
template<std::floating_point T, std::floating_point N>
constexpr vector3<T> translate(vector3<T> const &v, vector3<N> const &d);
template<std::floating_point T, std::floating_point N>
constexpr vector4<T> translate(vector4<T> const &v, vector4<N> const &d);

/* Pointers */
template<typename T>
constexpr auto const* pointer(vector<T> const &v);
template<typename T>
constexpr auto* pointer(vector<T> &v);
template<typename T>
constexpr auto const* pointer(vector2<T> const &v);
template<typename T>
constexpr auto* pointer(vector2<T> &v);
template<typename T>
constexpr auto const* pointer(vector3<T> const &v);
template<typename T>
constexpr auto* pointer(vector3<T> &v);
template<typename T>
constexpr auto const* pointer(vector4<T> const &v);
template<typename T>
constexpr auto* pointer(vector4<T> &v);

} //namespace ggl
