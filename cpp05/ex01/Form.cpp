//
// Created by Karina Logvina on 19.11.23.
//

#include "Form.hpp"

//Form::Form() {};
Form::~Form() {};

Form::Form(std::string const name, int const gradeToSignIn, int const gradeToExecute)
        : _name(name),
          _gradeToSignIn(gradeToSignIn),
          _gradeToExecute(gradeToExecute),
          _isSigned(false) {
  if (gradeToSignIn > 150 || gradeToExecute > 150) {
    throw GradeTooHighException();
  } else if (gradeToSignIn < 1 || gradeToExecute < 1) {
    throw GradeTooLowException();
  }
};

Form::Form(const Form &other)
        : _name(other.getName()),
          _gradeToSignIn(other.getGradeToSign()),
          _gradeToExecute(other.getGradeToExecute()),
          _isSigned(other.getSigned()) {};

Form&Form::operator=(const Form &rhs) {
  if (this != &rhs)
    this->_isSigned = rhs.getSigned();
  return *this;
}

std::string const & Form::getName() const {
  return this->_name;
}

bool Form::getSigned() const {
  return this->_isSigned;
}

const int &Form::getGradeToExecute() const {
  return this->_gradeToExecute;
}

const int &Form::getGradeToSign() const {
  return this->_gradeToSignIn;
}

const char * Form::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char * Form::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

void Form::beSigned(Bureaucrat const & bureaucrat) {
  if (bureaucrat.getGrade() > this->_gradeToSignIn) {
    throw GradeTooHighException();
  } else {
    this->_isSigned = true;
  }
}

std::ostream & operator<<(std::ostream & os, Form const & form) {
  os << "Form:" << form.getName() << ":";
  form.getSigned() ? os << "Signed" << "/" : os << "Unsigned" << "/";
  os << "GTS-" << form.getGradeToSign() << "/";
  os << "GTE-" << form.getGradeToExecute();
  return os;
}
