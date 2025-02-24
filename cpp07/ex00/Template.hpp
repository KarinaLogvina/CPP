
#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

# include <iostream>

template <typename T>
void swap(T & a, T & b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <typename T>
T const & min (T & a, T & b) {
  return (a <=b ? a : b);
}

template <typename T>
T const & max (T & a, T & b) {
  return (a >=b ? a : b);
}

#endif

