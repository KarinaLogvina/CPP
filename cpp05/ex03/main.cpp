#include "Bureaucrat.hpp"
#include "Intern.hpp"

# define NUM 12

int main(void) {
  Bureaucrat * bobby = new Bureaucrat("Jack Sparrow", NUM);
  Intern randomIntern;
  AForm *new_form = NULL;
  {
    std::cout << "____________1____________" << std::endl;
    new_form = randomIntern.makeForm("presidential pardon", "Biba");
    if (new_form) {
      bobby->signForm(*new_form);
      bobby->executeForm(*new_form);
      delete new_form;
    }
  }
  {
    std::cout << "____________2____________" << std::endl;
    new_form = randomIntern.makeForm("robotomy request", "Boba");
    if (new_form) {
      bobby->signForm(*new_form);
      bobby->executeForm(*new_form);
      delete new_form;
    }
  }
  {
    std::cout << "____________3____________" << std::endl;
    new_form = randomIntern.makeForm("shrubbery creation", "Lily");
    if (new_form) {
      bobby->signForm(*new_form);
      bobby->executeForm(*new_form);
      delete new_form;
    }
  }
  {
    std::cout << "____________4____________" << std::endl;
    new_form = randomIntern.makeForm("wrong form", "Dude");
    if (new_form) {
      bobby->executeForm(*new_form);
      bobby->signForm(*new_form);
      delete new_form;
    }
  }
  delete bobby;
  return (0);
}
