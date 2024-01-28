//
// Created by Karina Logvina on 14.11.23.
//

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

# include <string>
# include <iostream>

class Bureaucrat {
private:
  Bureaucrat();

  std::string const _name;
  int _grade;

public:
  Bureaucrat(std::string const name, int grade);
  Bureaucrat(Bureaucrat const &other);
  Bureaucrat &operator=(Bureaucrat const &rhs);
  virtual ~Bureaucrat();

  std::string const &getName() const;
  int getGrade() const;

  void incrementGrade();
  void decrementGrade();

  //classes
  class GradeTooHighException : public std::exception{
    public:
      const char * what() const throw();
  };
  class GradeTooLowException : public std::exception{
    public:
      const char * what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif
