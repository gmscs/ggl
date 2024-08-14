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

} //namespace ggl