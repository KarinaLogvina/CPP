//
// Created by Karina Logvina on 14.11.23.
//

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
# define NUM 12

  int main(void)
  {
    Bureaucrat * bobby = new Bureaucrat("Bobby", NUM);
    {
      std::cout << "---------------test01---------------" << std::endl;

      ShrubberyCreationForm form("Garden");

      bobby->signForm(form);
      bobby->executeForm(form);
    }
    {
      std::cout << "---------------test02---------------" << std::endl;

      RobotomyRequestForm form("Scanner");

      bobby->signForm(form);
      bobby->executeForm(form);
    }
    {
      std::cout << "---------------test03---------------" << std::endl;

      PresidentialPardonForm form("Navalny");

      bobby->signForm(form);
      bobby->executeForm(form);
    }
    delete bobby;
    return (0);
  }
