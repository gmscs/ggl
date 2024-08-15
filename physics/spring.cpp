#include "spring.hpp"

namespace ggl {

template<std::floating_point T>
constexpr spring<T>::spring() {
    this->id = 0;
    this->id_next = 1;
    this->rest_length = 0.0f;
    this->stiffness = 100.0f;
}

template<std::floating_point T>
constexpr spring<T>::spring(spring<T> const &s) {
    this->id = s.id;
    this->id_next = s.id_next;
    this->rest_length = s.rest_length;
    this->stiffness = s.stiffness;
}

template<std::floating_point T>
constexpr spring<T>::spring(int i, int j, T rest_length, T stiffness) {
    this->id = i;
    this->id_next = j;
    this->rest_length = rest_length;
    this->stiffness = stiffness;
}

template<std::floating_point T>
constexpr vector3<T> spring_force(spring<T> const &s, particle<T> const &p1, particle<T> const &p2) {
    float distance = mag(p2.position - p1.position);
    vector3 force = s.stiffness * (distance - s.rest_length) * normalize(p2.position - p1.position);
    return force;
}


} //namespace ggl