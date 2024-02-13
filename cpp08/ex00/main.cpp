
#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

#define SIZE 	30
#define VALUE	10

int main() {
  {
    std::cout << "VECTOR:" << std::endl;

    std::vector<int> vec;
    std::vector<int>::iterator iter;

    for (int i = 0; i < SIZE; ++i) {
      vec.push_back(i + 1);
    }
    std::cout << "Vector size: " << vec.size() << std::endl;
    try {
      iter = easyfind(vec, VALUE);
      std::cout << "element: " << *iter << " was found" << std::endl;
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
    }
  }
  {
    std::cout << "List:" << std::endl;

    std::list<int> list;
    std::list<int>::iterator iter;

    for (int i = 0; i < SIZE; ++i) {
      list.push_back(i + 1);
    }
    std::cout << "List size: " << list.size() << std::endl;
    try {
      iter = easyfind(list, VALUE);
      std::cout << "element: " << *iter << " was found" << std::endl;
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
    }
  }

  return 0;
}