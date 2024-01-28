//
// Created by Karina Logvina on 19.11.23.
//

#include "AForm.hpp"

//Form::Form() {};
AForm::~AForm() {};

AForm::AForm(std::string const name, int const gradeToSignIn, int const gradeToExecute)
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

AForm::AForm(const AForm &other)
        : _name(other.getName()),
          _gradeToSignIn(other.getGradeToSign()),
          _gradeToExecute(other.getGradeToExecute()),
          _isSigned(other.getSigned()) {};

AForm&AForm::operator=(const AForm &rhs) {
  if (this != &rhs)
    this->_isSigned = rhs.getSigned();
  return *this;
}

std::string const & AForm::getName() const {
  return this->_name;
}

bool AForm::getSigned() const {
  return this->_isSigned;
}

const int &AForm::getGradeToExecute() const {
  return this->_gradeToExecute;
}

const int &AForm::getGradeToSign() const {
  return this->_gradeToSignIn;
}

const char * AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char * AForm::FormNotSignedException::what() const throw() {
  return "Form not signed";
}


void AForm::checkRequirementsToExecute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw FormNotSignedException();
	else if (executor.getGrade() > this->_gradeToExecute)
		throw GradeTooLowException();
}

const char * AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

void AForm::beSigned(Bureaucrat const & bureaucrat) {
  if (bureaucrat.getGrade() > this->_gradeToSignIn) {
    throw GradeTooHighException();
  } else {
    this->_isSigned = true;
  }
}

std::ostream & operator<<(std::ostream & os, AForm const & form) {
  os << "Form:" << form.getName() << ":";
  form.getSigned() ? os << "Signed" << "/" : os << "Unsigned" << "/";
  os << "GTS-" << form.getGradeToSign() << "/";
  os << "GTE-" << form.getGradeToExecute();
  return os;
}
