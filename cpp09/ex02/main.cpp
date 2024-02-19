#include "PmergeMe.hpp"

int main(int ac, char **av) {
  if (ac < 2) {
    std::cerr << "Error: no sequence provided" << std::endl;
    return (1);
  }
  try {
    PmergeMe input(ac, av);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  return 0;
}
