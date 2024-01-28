//
// Created by Karina Logvina on 18.12.23.
//

#ifndef CPP05_ROBOTOMYREQUESTFORM_HPP
#define CPP05_ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm {
private:
  RobotomyRequestForm();
  std::string _target;

public:
  RobotomyRequestForm(std::string const & target);
  RobotomyRequestForm(RobotomyRequestForm const & other);
  ~RobotomyRequestForm();

  RobotomyRequestForm & operator=(RobotomyRequestForm const &rhs);
  std::string getTarget() const;
  void execute (Bureaucrat const & executor) const;
};


#endif
