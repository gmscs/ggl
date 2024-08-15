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
constexpr particle<T>::particle(T c) {
    this->position = vector3<T>(0);
    this->velocity = vector3<T>(0);
    this->force = vector3<T>(0);
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

template<std::floating_point T>
constexpr particle<T> verlet_int(particle<T> const &p, T delta_time, T damping) {
    particle<T> new_particle;
    if(!p.is_fixed) {
        ggl::vector3 accel = p.force / p.mass;
        ggl::vector3 new_pos = p.position + p.velocity * delta_time + 0.5f * accel * delta_time * delta_time;
        new_particle.velocity = (new_pos - p.position) / delta_time;
        new_particle.velocity *= damping;
        new_particle.position = new_pos;
        new_particle.force = p.force;
        new_particle.mass = p.mass;
        new_particle.is_fixed = false;
        return new_particle;
    }
    return p;
}

} //namespace ggl