//
// Created by Karina Logvina on 21.01.24.
//

#include "Intern.hpp"

class AForm;

Intern::Intern(){};
Intern::~Intern() {};

Intern&Intern::operator=(const Intern &rhs) {
  (void)rhs;
  return *this;
}

Intern::Intern(Intern const & other) {
  *this = other;
}

static AForm * shrubberyCreateForm(std::string const & target) {
  return (new ShrubberyCreationForm(target));
}

static AForm * robotomyCreatetForm(std::string const & target) {
  return (new RobotomyRequestForm(target));
}

static AForm * pardonCreateForm(std::string const & target) {
  return (new PresidentialPardonForm(target));
}

const char * Intern::IncorrectFormException::what() const throw() {
  return "Incorrect form name";
}

AForm * Intern::makeForm(std::string const formName, std::string const target) {
  AForm * (* funcArr[3])(std::string const &target) = {
                  shrubberyCreateForm,
                  robotomyCreatetForm,
                  pardonCreateForm };
  std::string formNames[3] = {
                  "shrubbery creation",
                  "robotomy request",
                  "presidential pardon"};
  AForm * ret = NULL;

  try {
    for (int i = 0; i < 3; i++) {
      if (formName == formNames[i])
        ret = funcArr[i](target);
    }
    if (ret)
      std::cout << "Intern creates " << *ret << std::endl;
    else
      throw IncorrectFormException();
  }
  catch(const std::exception & e) {
    std::cerr << "Exception caught: " << e.what() << '\n';
  }
  return ret;
}
