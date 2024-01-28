//
// Created by Karina Logvina on 18.12.23.
//

#include "RobotomyRequestForm.hpp"

//RobotomyRequestForm::RobotomyRequestForm() {};
RobotomyRequestForm::~RobotomyRequestForm() {};

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm(target, 72, 45), _target(target) {};
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) :AForm(other), _target(other.getTarget()) {};
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
  AForm::operator=(rhs);
  if (this != &rhs)
    this->_target = rhs.getTarget();
  return *this;
}

std::string RobotomyRequestForm::getTarget() const {
  return this->_target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
  checkRequirementsToExecute(executor);
  if (rand() % 2 == 1) {
    std::cout << this->_target << " has been robotimezed succesfully by" << executor << std::endl;
  } else {
    std::cout << "Something happened with target: " << this->_target << " Robotomy failed." << std::endl;
  }
}