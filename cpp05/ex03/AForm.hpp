//
// Created by Karina Logvina on 19.11.23.
//

#ifndef AFORM_HPP
#define AFORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
  private:
    AForm();
    std::string const _name;
    int const _gradeToSignIn;
    int const _gradeToExecute;
    bool _isSigned;

  public:
    AForm(std::string const name, int const gradeToSignIn, int const gradeToExecute);
    AForm(AForm const & other);
    virtual ~AForm();

    AForm &operator=(AForm const &rhs);

    std::string const &getName() const;
    bool getSigned() const;
    int const & getGradeToSign() const;
    int const & getGradeToExecute() const;

    void beSigned(Bureaucrat const & bureaucrat);

    virtual void execute(Bureaucrat const & executor) const = 0;

    void checkRequirementsToExecute(Bureaucrat const & executor) const;

    class GradeTooHighException : public std::exception{
      public:
        const char * what() const throw();
    };

    class FormNotSignedException : public std::exception{
    public:
      const char * what() const throw();
    };

    class GradeTooLowException : public std::exception{
      public:
        const char * what() const throw();
    };
};
std::ostream & operator<<(std::ostream & os, AForm const & form);

#endif
