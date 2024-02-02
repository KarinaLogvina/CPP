//
// Created by Karina Logvina on 29.01.24.
//

#include "Serialization.hpp"

Serialization::Serialization() {};
Serialization::~Serialization() {};

Serialization &Serialization::operator=(const int &rhs) {
  (void)rhs;
  return *this;
}

Serialization::Serialization(const int &other) {
  *this = other;
}

uintptr_t Serialization::serialize(Data * ptr) {
  return (reinterpret_cast<uintptr_t>(ptr));
}

Data * Serialization::deserialize(uintptr_t raw) {
  return (reinterpret_cast<Data *>(raw));
}