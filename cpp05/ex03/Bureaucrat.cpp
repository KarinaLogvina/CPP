//
// Created by Karina Logvina on 14.11.23.
//

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() {};
Bureaucrat::~Bureaucrat() {};

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade) {
  if (grade < 1) {
    throw GradeTooLowException();
  } else if (grade > 150) {
    throw GradeTooHighException();
  }
}

Bureaucrat::Bureaucrat(Bureaucrat const & other) :	_name(other.getName()), _grade(other.getGrade()) {}

Bureaucrat&Bureaucrat::operator=(const Bureaucrat &rhs) {
  if (this != &rhs)
    this->_grade = rhs.getGrade();
  return *this;
}

std::string const &Bureaucrat::getName() const {
  return _name;
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

int Bureaucrat::getGrade() const {
  return _grade;
}

void Bureaucrat::incrementGrade() {
  if (_grade >= 150) {
    throw GradeTooHighException();
  } else {
    _grade++;
  }
}


void Bureaucrat::decrementGrade() {
  if (_grade <= 1) {
    throw GradeTooLowException();
  } else {
    _grade--;
  }
}

void Bureaucrat::signForm(AForm & form) {
  try {
    form.beSigned(*this);
    std::cout << *this << " signed" << form << std::endl;
  } catch (const std::exception & e)
  {
    std::cout << *this << " couldn’t sign " << form
              << " because " << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(const AForm &form) {
 try {
   form.execute(*this);
   std::cout << *this << " executed" << form << std::endl;
 } catch (const std::exception & e)
 {
   std::cout << *this << " couldn’t executed " << form
             << " because " << e.what() << std::endl;
 }
}

std::ostream & operator<<(std::ostream & os, Bureaucrat const & bureaucrat)
{
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return os;
}
