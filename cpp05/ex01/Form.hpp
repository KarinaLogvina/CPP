//
// Created by Karina Logvina on 19.11.23.
//

#ifndef FORM_HPP
#define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
  private:
    Form();
    std::string const _name;
    int const _gradeToSignIn;
    int const _gradeToExecute;
    bool _isSigned;

  public:
    Form(std::string const name, int const gradeToSignIn, int const gradeToExecute);
    Form(Form const & other);
    ~Form();

    Form &operator=(Form const &rhs);

    std::string const &getName () const;
    bool getSigned() const;
    int const & getGradeToSign() const;
    int const & getGradeToExecute() const;

    void beSigned(Bureaucrat const & bureaucrat);

    class GradeTooHighException : public std::exception{
      public:
        const char * what() const throw();
    };
    class GradeTooLowException : public std::exception{
      public:
        const char * what() const throw();
    };
};

std::ostream & operator<<(std::ostream & os, Form const & form);

#endif
