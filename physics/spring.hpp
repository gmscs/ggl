namespace ggl {

template<std::floating_point T>
struct spring {
    int id;
    int id_next;

    T rest_length;
    T stiffness;

    constexpr spring();
    constexpr spring(spring const& s);
    explicit constexpr spring(int i, int j, T rest_length, T stiffness);

    static inline constexpr const char* type() {
        return typeid(T).name();
    }
};

template<std::floating_point T>
constexpr vector3<T> spring_force(spring<T> const &s, particle<T> const &p1, particle<T> const &p2);

} //namespace ggl