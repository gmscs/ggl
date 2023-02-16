namespace ggl {
template<typename T>
struct matrix2 {
    vector2<T> row1;
    vector2<T> row2;

    matrix2();
    matrix2(matrix2 const& m);
    explicit matrix2(vector2<T> const &a, vector2<T> const &b);

    static inline constexpr int numRows() {
        return 2;
    }
};

template<typename T>
struct matrix3 {
    vector3<T> row1;
    vector3<T> row2;
    vector3<T> row3;

    matrix3();
    matrix3(matrix3 const& m);
    explicit matrix3(vector3<T> const &a, vector3<T> const &b, vector3<T> const &c);

    static inline constexpr int numRows() {
        return 3;
    }
};

template<typename T>
struct matrix4 {
    vector4<T> row1;
    vector4<T> row2;
    vector4<T> row3;
    vector4<T> row4;

    matrix4();
    matrix4(matrix4 const& m);
    explicit matrix4(vector4<T> const &a, vector4<T> const &b, vector4<T> const &c, vector4<T> const &d);

    static inline constexpr int numRows() {
        return 4;
    }
};

}//namespace ggl