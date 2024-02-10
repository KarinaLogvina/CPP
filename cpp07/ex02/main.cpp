
#include "Array.hpp"
#include <iostream>

int main() {
  {
    std::cout << "-----01-----" << std::endl;
    Array<int> emptyArray;
    std::cout << emptyArray.size() << std::endl;
  }
  {
    std::cout << "-----02-----" << std::endl;
    Array<int> array = Array<int>(3u);
    array[0] = 0;
    array[1] = 1;
    array[2] = 2;
    std::cout << array.size() << std::endl;
    std::cout << array[1] << std::endl;
  }
  {
    std::cout << "-----03-----" << std::endl;
    Array<int> array = Array<int>(3u);
    array[0] = 0;
    array[1] = 1;
    array[2] = 2;
    Array<int> copied = array;
    copied[2]= 42;
    std::cout << array.size() << std::endl;
    for (unsigned int i = 0; i < array.size(); ++i) {
      std::cout << array[i] << std::endl;
    }
    for (unsigned int i = 0; i < copied.size(); ++i) {
      std::cout << "copied: " << copied[i] << std::endl;
    }
    {
      std::cout << "-----04-----" << std::endl;
      try
      {
        Array<float> array = Array<float>(4u);
        array[0] = 42.42f;
        for (int i = 0; i < 4; i++)
          std::cout << "Index: " << i << "; Value: " << array[i] << std::endl;
      }
      catch(const std::exception& e)
      {
        std::cerr << e.what() << '\n';
      }
    }
    {
      std::cout << "-----05-----" << std::endl;
      try
      {
        Array<int> array = Array<int>(3u);
        array[0] = 4;
        array[1] = 42;
        array[2] = 47;
        std::cout << array[3] << std::endl;
      }
      catch(const std::exception& e)
      {
        std::cerr<< "Exception caught: " << e.what() << '\n';
      }
    }
  }
}