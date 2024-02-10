
#include "Iter.hpp"

template<typename T>
void multiply(T &a) {
  a = a * 3;
}

template<typename T>
void print(T &a) {
  std::cout << a << std::endl;
}

int main() {
  {
    int arr[5] = {1, 3, 5, 7, 23};
    iter(arr, 5, multiply);
    for (int i = 0; i < 5; ++i) {
      std::cout << arr[i] << std::endl;
    }
  }
  std::cout << std::endl;
  {
    std::string arr[3] = {"cold", "hot", "moist"};
    iter(arr, 3, print);
  }
  return (0);
}