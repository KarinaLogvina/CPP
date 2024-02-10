#include "Base.hpp"
#include "func.hpp"
#include <iostrem>
#include <ctime>
#include <cstdlib>

int main () {
  srand(time(NULL));

  for (int i = 0; i < 3; i++)
  {
    Base * object = generate();
    identify(object);
    delete object;
  }
  std::cout << std::endl;

  Base * object = generate();
  identify(*object);
  delete object;

  return (0);
}