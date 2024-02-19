#include "RPN.hpp"

int main (int ac, char **av) {
  RPN rpn;

  if (ac !=2) {
    std::cerr << "Error: not enough arguments" << std::endl;
  } else {
    try {
      rpn.reversePolishNotation(av[1]);
      std::cout << rpn << std::endl;
    } catch(const std::exception& e) {
      std::cerr << e.what() << std::endl;
    }
  }
  return (0);
}