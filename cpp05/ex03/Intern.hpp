//
// Created by Karina Logvina on 21.01.24.
//

#ifndef CPP05_INTERN_HPP
#define CPP05_INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern {
  public:
    Intern(void);
    ~Intern(void);
    Intern(Intern const & other);

    Intern & operator=(Intern const & rhs);
    class IncorrectFormException : public std::exception
    {
      public:
        const char *what() const throw();
    };

    AForm * makeForm(std::string const formName, std::string const target);
};


#endif