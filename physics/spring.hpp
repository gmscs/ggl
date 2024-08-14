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

} //namespace ggl