//
// Created by Karina Logvina on 13.02.24.
//

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template<typename T>
typename T::iterator easyfind(T& container, int value) {
  typename T::iterator iter =  std::find(container.begin(), container.end(), value);
  if (iter == container.end()) {
    throw std::out_of_range("element not found");
  }
  return iter;
}

#endif