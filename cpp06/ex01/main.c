

#include "Serialization.hpp"
#include <stdlib.h>
#include <iostrem>

int main (int ac, char **av) {
  if (ac != 2) {
    std::cerr << "USAGE:  ./serialize [int_value]" << std::endl;
    return (1);
  }

  Data * data = new Data(atoi(av[1]));
  uintptr_t serialized = Serialization::serialize(data);

  Data * deserialized = Serialization::deserialize(serialized);

  if (deserialized == data)
    std::cout << "Serialization and deserialization completed successfully" << std::endl;

  std::cout << "Deserialized data value: " << deserialized->data << std::endl;

  delete data;

  return (0);
}