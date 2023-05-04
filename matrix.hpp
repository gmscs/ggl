namespace ggl {
template<std::floating_point T>
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

    template<std::floating_point N>
    constexpr matrix2<T>& operator=(matrix2<N> const& m);
    template<std::floating_point N>
    constexpr matrix2<T>& operator+=(matrix2<N> const& m);
    template<std::floating_point N>
    constexpr matrix2<T>& operator-=(matrix2<N> const& m);
    template<std::floating_point N>
    constexpr matrix2<T>& operator*=(matrix2<N> const& m);
    template<typename N>
    constexpr matrix2<T>& operator*=(N c);
    template<typename N>
    constexpr matrix2<T>& operator/=(N c);
    constexpr vector2<T> const& operator[](int i) const;
    constexpr vector2<T>& operator[](int i);
};

template<std::floating_point T>
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

    template<std::floating_point N>
    constexpr matrix3<T>& operator=(matrix3<N> const& m);
    template<std::floating_point N>
    constexpr matrix3<T>& operator+=(matrix3<N> const& m);
    template<std::floating_point N>
    constexpr matrix3<T>& operator-=(matrix3<N> const& m);
    template<std::floating_point N>
    constexpr matrix3<T>& operator*=(matrix3<N> const& m);
    template<typename N>
    constexpr matrix3<T>& operator*=(N c);
    template<typename N>
    constexpr matrix3<T>& operator/=(N c);
    constexpr vector3<T> const& operator[](int i) const;
    constexpr vector3<T>& operator[](int i);
};

template<std::floating_point T>
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

    template<std::floating_point N>
    constexpr matrix4<T>& operator=(matrix4<N> const& m);
    template<std::floating_point N>
    constexpr matrix4<T>& operator+=(matrix4<N> const& m);
    template<std::floating_point N>
    constexpr matrix4<T>& operator-=(matrix4<N> const& m);
    template<std::floating_point N>
    constexpr matrix4<T>& operator*=(matrix4<N> const& m);
    template<typename N>
    constexpr matrix4<T>& operator*=(N c);
    template<typename N>
    constexpr matrix4<T>& operator/=(N c);
    constexpr vector4<T> const& operator[](int i) const;
    constexpr vector4<T>& operator[](int i);
};

/* Sign flip */
template<std::floating_point T>
constexpr matrix2<T> operator-(matrix2<T> const& m);
template<std::floating_point T>
constexpr matrix3<T> operator-(matrix3<T> const& m);
template<std::floating_point T>
constexpr matrix4<T> operator-(matrix4<T> const& m);

/* Addition */
template<std::floating_point T>
constexpr matrix2<T> operator+(matrix2<T> const& m, matrix2<T> const& m2);
template<std::floating_point T>
constexpr matrix3<T> operator+(matrix3<T> const& m, matrix3<T> const& m2);
template<std::floating_point T>
constexpr matrix4<T> operator+(matrix4<T> const& m, matrix4<T> const& m2);

/* Subtraction */
template<std::floating_point T>
constexpr matrix2<T> operator-(matrix2<T> const& m, matrix2<T> const& m2);
template<std::floating_point T>
constexpr matrix3<T> operator-(matrix3<T> const& m, matrix3<T> const& m2);
template<std::floating_point T>
constexpr matrix4<T> operator-(matrix4<T> const& m, matrix4<T> const& m2);

/* Multiplication */
template<std::floating_point T>
constexpr matrix2<T> operator*(matrix2<T> const& m, matrix2<T> const& m2);
template<std::floating_point T>
constexpr matrix3<T> operator*(matrix3<T> const& m, matrix3<T> const& m2);
template<std::floating_point T>
constexpr matrix4<T> operator*(matrix4<T> const& m, matrix4<T> const& m2);
template<std::floating_point T, typename N>
constexpr matrix2<T> operator*(matrix2<T> const& m, N c);
template<std::floating_point T, typename N>
constexpr matrix3<T> operator*(matrix3<T> const& m, N c);
template<std::floating_point T, typename N>
constexpr matrix4<T> operator*(matrix4<T> const& m, N c);
template<std::floating_point T, typename N>
constexpr ggl::vector2<T> operator*(matrix2<T> const &m, ggl::vector2<T> const &v);
template<std::floating_point T, typename N>
constexpr ggl::vector3<T> operator*(matrix3<T> const &m, ggl::vector3<T> const &v);
template<std::floating_point T, typename N>
constexpr ggl::vector4<T> operator*(matrix4<T> const &m, ggl::vector4<T> const &v);

/* Division */
template<std::floating_point T, typename N>
constexpr matrix2<T> operator/(matrix2<T> const &m, N c);
template<std::floating_point T, typename N>
constexpr matrix3<T> operator/(matrix3<T> const &m, N c);
template<std::floating_point T, typename N>
constexpr matrix4<T> operator/(matrix4<T> const &m, N c);

/* Bool Operators */
template<std::floating_point T>
constexpr bool operator==(matrix2<T> const &v, matrix2<T> const &b);
template<std::floating_point T>
constexpr bool operator==(matrix3<T> const &v, matrix3<T> const &b);
template<std::floating_point T>
constexpr bool operator==(matrix4<T> const &v, matrix4<T> const &b);
template<std::floating_point T>
constexpr bool operator!=(matrix2<T> const &v, matrix2<T> const &b);
template<std::floating_point T>
constexpr bool operator!=(matrix3<T> const &v, matrix3<T> const &b);
template<std::floating_point T>
constexpr bool operator!=(matrix4<T> const &v, matrix4<T> const &b);

/* Determinant */
template<std::floating_point T>
constexpr T determinant(matrix2<T> const &m);
template<std::floating_point T>
constexpr T determinant(matrix3<T> const &m);
template<std::floating_point T>
constexpr T determinant(matrix4<T> const &m);

/* Inverse */
template<std::floating_point T>
constexpr matrix2<T> inverse(matrix2<T> const &m);
template<std::floating_point T>
constexpr matrix3<T> inverse(matrix3<T> const &m);
template<std::floating_point T>
constexpr matrix4<T> inverse(matrix4<T> const &m);

/* Printing */
template<std::floating_point T>
constexpr void print_mat(matrix2<T> const &m);
template<std::floating_point T>
constexpr void print_mat(matrix3<T> const &m);
template<std::floating_point T>
constexpr void print_mat(matrix4<T> const &m);

/* Special matrices */
template<std::floating_point T>
ggl::matrix4<T> get_projection_matrix(T near, T far, T fov, T width, T height);
template<std::floating_point T>
ggl::matrix3<T> minors_matrix(matrix3<T> const &m);
template<std::floating_point T>
ggl::matrix4<T> minots_matrix(matrix4<T> const &m);
template<std::floating_point T>
ggl::matrix3<T> cofactors_matrix(matrix3<T> const &m);
template<std::floating_point T>
ggl::matrix4<T> cofactors_matrix(matrix4<T> const &m);
template<std::floating_point T>
ggl::matrix3<T> transpose_matrix(matrix3<T> const &m);
template<std::floating_point T>
ggl::matrix4<T> transpose_matrix(matrix4<T> const &m);

template<std::floating_point T>
constexpr ggl::matrix4<T> translation_matrix(vector3<T> const &v);
template<std::floating_point T>
constexpr ggl::matrix3<T> translation_matrix(vector2<T> const &v);

template<std::floating_point T>
constexpr ggl::matrix3<T> rotation_matrix(T angle);
template<std::floating_point T>
constexpr ggl::matrix3<T> scaling_matrix(T width, T height);
template<std::floating_point T>
constexpr ggl::matrix4<T> scaling_matrix(T width, T height, T depth);

/* Translation */
template<std::floating_point T>
constexpr matrix3<T> translate(matrix3<T> const &m, vector3<T> const &v);

template<std::floating_point T>
constexpr matrix3<T> translate(matrix3<T> const &m, vector2<T> const &v);

template<std::floating_point T>
constexpr matrix4<T> translate(matrix4<T> const &m, vector4<T> const &v);

template<std::floating_point T>
constexpr matrix4<T> translate(matrix4<T> const &m, vector3<T> const &v);

/* Rotation */
template<std::floating_point T, std::floating_point N>
constexpr vector3<T> rotate_x(vector2<T> const &v, N angle);

template<std::floating_point T, std::floating_point N>
constexpr vector3<T> rotate_y(vector2<T> const &v, N angle);

template<std::floating_point T, std::floating_point N>
constexpr vector3<T> rotate_z(vector2<T> const &v, N angle);

template<std::floating_point T, std::floating_point N>
constexpr vector3<T> rotate_x(vector3<T> const &v, N angle);

template<std::floating_point T, std::floating_point N>
constexpr vector3<T> rotate_y(vector3<T> const &v, N angle);

template<std::floating_point T, std::floating_point N>
constexpr vector3<T> rotate_z(vector3<T> const &v, N angle);

template<std::floating_point T, std::floating_point N>
constexpr vector4<T> rotate_x(vector4<T> const &v, N angle);

template<std::floating_point T, std::floating_point N>
constexpr vector4<T> rotate_y(vector4<T> const &v, N angle);

template<std::floating_point T, std::floating_point N>
constexpr vector4<T> rotate_z(vector4<T> const &v, N angle);

template<std::floating_point T, std::floating_point N>
constexpr matrix3<T> rotate_x(matrix3<T> const &m, N angle);

template<std::floating_point T, std::floating_point N>
constexpr matrix3<T> rotate_y(matrix3<T> const &m, N angle);

template<std::floating_point T, std::floating_point N>
constexpr matrix3<T> rotate_z(matrix3<T> const &m, N angle);

template<std::floating_point T, std::floating_point N>
constexpr matrix4<T> rotate_x(matrix4<T> const &m, N angle);

template<std::floating_point T, std::floating_point N>
constexpr matrix4<T> rotate_y(matrix4<T> const &m, N angle);

template<std::floating_point T, std::floating_point N>
constexpr matrix4<T> rotate_z(matrix4<T> const &m, N angle);

/* Scaling */
template<std::floating_point T, typename N>
constexpr vector3<T> scale(vector3<T> const &v, vector2<N> const &d);

template<std::floating_point T, typename N>
constexpr vector4<T> scale(vector4<T> const &v, vector3<N> const &d);

template<std::floating_point T, typename N>
constexpr matrix3<T> scale(matrix3<T> const &m, vector2<N> const &d);

template<std::floating_point T, typename N>
constexpr matrix4<T> scale(matrix4<T> const &m, vector3<N> const &d);

/* Pointers */
template<typename T>
constexpr auto const* pointer(matrix2<T> const &m);

template<typename T>
constexpr auto* pointer(matrix2<T> &m);

template<typename T>
constexpr auto const* pointer(matrix3<T> const &m);

template<typename T>
constexpr auto* pointer(matrix3<T> &m);

template<typename T>
constexpr auto const* pointer(matrix4<T> const &m);

template<typename T>
constexpr auto* pointer(matrix4<T> &m);

}//namespace ggl
