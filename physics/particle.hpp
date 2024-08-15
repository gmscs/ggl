namespace ggl {

template<std::floating_point T>
struct particle {
    vector3<T> position;
    vector3<T> velocity;
    vector3<T> force;

    T mass;
    bool is_fixed;

    constexpr particle();
    constexpr particle(T c);
    constexpr particle(particle const& p);
    explicit constexpr particle(vector3<T> const &p, vector3<T> const &v, vector3<T> const &f, T m, bool is_fixed);

    static inline constexpr const char* type() {
        return typeid(T).name();
    }

    constexpr particle<T>& operator=(particle<T> const& p);
};

template<std::floating_point T>
constexpr particle<T> verlet_int(particle<T> const &p, T delta_time, T damping);

} //namespace ggl