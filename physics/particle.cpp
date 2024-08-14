#include "particle.hpp"

namespace ggl {

template<std::floating_point T>
constexpr particle<T>::particle() {
    this->position = vector3<T>();
    this->velocity = vector3<T>();
    this->force = vector3<T>();
    this->mass = 0.0f;
    this->is_fixed = false;
}

template<std::floating_point T>
constexpr particle<T>::particle(particle<T> const &p) {
    this->position = vector3<T>(p.position);
    this->velocity = vector3<T>(p.velocity);
    this->force = vector3<T>(p.force);
    this->mass = p.mass;
    this->is_fixed = p.is_fixed;
}

template<std::floating_point T>
constexpr particle<T>::particle(vector3<T> const &p, vector3<T> const &v, vector3<T> const &f, T m, bool is_fixed) {
    this->position = p;
    this->velocity = v;
    this->force = f;
    this->mass = m;
    this->is_fixed = is_fixed;
}

template<std::floating_point T>
constexpr particle<T>& particle<T>:: operator=(particle<T> const &p) {
    this->position = vector3<T>(p.position);
    this->velocity = vector3<T>(p.velocity);
    this->force = vector3<T>(p.force);
    this->mass = p.mass;
    this->is_fixed = p.is_fixed;

    return *this;
}

} //namespace ggl