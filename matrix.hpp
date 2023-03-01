namespace ggl {
template<typename T>
struct matrix2 {
    vector2<T> row1;
    vector2<T> row2;

    constexpr matrix2();
    constexpr matrix2(T c);
    constexpr matrix2(matrix2 const& m);
    explicit constexpr matrix2(vector2<T> const &a, vector2<T> const &b);

    static inline constexpr int numRows() {
        return 2;
    }

    static inline constexpr int numCols() {
        return 2;
    }

    static inline constexpr const char* type() {
        return typeid(T).name();
    }

    template<typename N>
    constexpr matrix2<T>& operator=(matrix2<N> const& m);
    template<typename N>
    constexpr matrix2<T>& operator+=(matrix2<N> const& m);
    template<typename N>
    constexpr matrix2<T>& operator-=(matrix2<N> const& m);
    template<typename N>
    constexpr matrix2<T>& operator*=(matrix2<N> const& m);
    template<typename N>
    constexpr matrix2<T>& operator*=(N c);
    template<typename N>
    constexpr matrix2<T>& operator/=(N c);
    constexpr vector2<T> const& operator[](int i) const;
    constexpr vector2<T>& operator[](int i);
};

template<typename T>
struct matrix3 {
    vector3<T> row1;
    vector3<T> row2;
    vector3<T> row3;

    constexpr matrix3();
    constexpr matrix3(T c);
    constexpr matrix3(matrix3 const& m);
    explicit constexpr matrix3(vector3<T> const &a, vector3<T> const &b, vector3<T> const &c);

    static inline constexpr int numRows() {
        return 3;
    }

    static inline constexpr int numCols() {
        return 3;
    }

    static inline constexpr const char* type() {
        return typeid(T).name();
    }

    template<typename N>
    constexpr matrix3<T>& operator=(matrix3<N> const& m);
    template<typename N>
    constexpr matrix3<T>& operator+=(matrix3<N> const& m);
    template<typename N>
    constexpr matrix3<T>& operator-=(matrix3<N> const& m);
    template<typename N>
    constexpr matrix3<T>& operator*=(matrix3<N> const& m);
    template<typename N>
    constexpr matrix3<T>& operator*=(N c);
    template<typename N>
    constexpr matrix3<T>& operator/=(N c);
    constexpr vector3<T> const& operator[](int i) const;
    constexpr vector3<T>& operator[](int i);
};

template<typename T>
struct matrix4 {
    vector4<T> row1;
    vector4<T> row2;
    vector4<T> row3;
    vector4<T> row4;

    constexpr matrix4();
    constexpr matrix4(T c);
    constexpr matrix4(matrix4 const& m);
    explicit constexpr matrix4(vector4<T> const &a, vector4<T> const &b, vector4<T> const &c, vector4<T> const &d);

    static inline constexpr int numRows() {
        return 4;
    }

    static inline constexpr int numCols() {
        return 4;
    }

    static inline constexpr const char* type() {
        return typeid(T).name();
    }

    template<typename N>
    constexpr matrix4<T>& operator=(matrix4<N> const& m);
    template<typename N>
    constexpr matrix4<T>& operator+=(matrix4<N> const& m);
    template<typename N>
    constexpr matrix4<T>& operator-=(matrix4<N> const& m);
    template<typename N>
    constexpr matrix4<T>& operator*=(matrix4<N> const& m);
    template<typename N>
    constexpr matrix4<T>& operator*=(N c);
    template<typename N>
    constexpr matrix4<T>& operator/=(N c);
    constexpr vector4<T> const& operator[](int i) const;
    constexpr vector4<T>& operator[](int i);
};

/* Sign flip */
template<typename T>
constexpr matrix2<T> operator-(matrix2<T> const& m);
template<typename T>
constexpr matrix3<T> operator-(matrix3<T> const& m);
template<typename T>
constexpr matrix4<T> operator-(matrix4<T> const& m);

/* Addition */
template<typename T>
constexpr matrix2<T> operator+(matrix2<T> const& m, matrix2<T> const& m2);
template<typename T>
constexpr matrix3<T> operator+(matrix3<T> const& m, matrix3<T> const& m2);
template<typename T>
constexpr matrix4<T> operator+(matrix4<T> const& m, matrix4<T> const& m2);

/* Subtraction */
template<typename T>
constexpr matrix2<T> operator-(matrix2<T> const& m, matrix2<T> const& m2);
template<typename T>
constexpr matrix3<T> operator-(matrix3<T> const& m, matrix3<T> const& m2);
template<typename T>
constexpr matrix4<T> operator-(matrix4<T> const& m, matrix4<T> const& m2);

/* Multiplication */
template<typename T>
constexpr matrix2<T> operator*(matrix2<T> const& m, matrix2<T> const& m2);
template<typename T>
constexpr matrix3<T> operator*(matrix3<T> const& m, matrix3<T> const& m2);
template<typename T>
constexpr matrix4<T> operator*(matrix4<T> const& m, matrix4<T> const& m2);
template<typename T, typename N>
constexpr matrix2<T> operator*(matrix2<T> const& m, N c);
template<typename T, typename N>
constexpr matrix3<T> operator*(matrix3<T> const& m, N c);
template<typename T, typename N>
constexpr matrix4<T> operator*(matrix4<T> const& m, N c);

/* Division */
template<std::floating_point T, typename N>
constexpr matrix2<T> operator/(matrix2<T> const &m, N c);
template<std::floating_point T, typename N>
constexpr matrix3<T> operator/(matrix3<T> const &m, N c);
template<std::floating_point T, typename N>
constexpr matrix4<T> operator/(matrix4<T> const &m, N c);
template<typename N>
constexpr matrix2<float> operator/(matrix2<int> const &m, N c);
template<typename N>
constexpr matrix3<float> operator/(matrix3<int> const &m, N c);
template<typename N>
constexpr matrix4<float> operator/(matrix4<int> const &m, N c);

/* Bool Operators */
template<typename T>
constexpr bool operator==(matrix2<T> const &v, matrix2<T> const &b);
template<typename T>
constexpr bool operator==(matrix3<T> const &v, matrix3<T> const &b);
template<typename T>
constexpr bool operator==(matrix4<T> const &v, matrix4<T> const &b);
template<typename T>
constexpr bool operator!=(matrix2<T> const &v, matrix2<T> const &b);
template<typename T>
constexpr bool operator!=(matrix3<T> const &v, matrix3<T> const &b);
template<typename T>
constexpr bool operator!=(matrix4<T> const &v, matrix4<T> const &b);

/* Determinant */
template<typename T>
constexpr T determinant(matrix2<T> const &m);
template<typename T>
constexpr T determinant(matrix3<T> const &m);
template<typename T>
constexpr T determinant(matrix4<T> const &m);

/* Inverse */
template<typename T>
constexpr matrix2<float> inverse(matrix2<T> const &m);
template<typename T>
constexpr matrix3<float> inverse(matrix3<T> const &m);
template<typename T>
constexpr matrix4<float> inverse(matrix4<T> const &m);

/* Printing */
template<typename T>
constexpr void print_mat(matrix2<T> const &m);
template<typename T>
constexpr void print_mat(matrix3<T> const &m);
template<typename T>
constexpr void print_mat(matrix4<T> const &m);

/* Special matrices */
template<typename T>
ggl::matrix4<T> get_projection_matrix(T near, T far, T fov, T width, T height);

/* Convert to float */
template<typename T>
ggl::matrix2<float> convert_to_float(matrix2<T> const &m);
template<typename T>
ggl::matrix3<float> convert_to_float(matrix3<T> const &m);
template<typename T>
ggl::matrix4<float> convert_to_float(matrix4<T> const &m);
}//namespace ggl
