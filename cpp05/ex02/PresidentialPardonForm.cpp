//
// Created by Karina Logvina on 18.12.23.
//

#include "PresidentialPardonForm.hpp"


//PresidentialPardonForm::PresidentialPardonForm();
PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm(target, 25, 5), _target(target) {};
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other), _target(other.getTarget()) {};

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
  AForm::operator=(rhs);
  if (this != &rhs)
    this->_target = rhs.getTarget();
  return *this;
}

std::string PresidentialPardonForm::getTarget() const {
  return this->_target;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  checkRequirementsToExecute(executor);
  std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}