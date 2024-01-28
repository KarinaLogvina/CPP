//
// Created by Karina Logvina on 18.12.23.
//

#ifndef CPP05_PRESIDENTIALPARDONFORM_HPP
#define CPP05_PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm {
private:
    PresidentialPardonForm();
    std::string _target;
public:
    PresidentialPardonForm(std::string const & target);
    PresidentialPardonForm(PresidentialPardonForm const & other);
    ~PresidentialPardonForm();

    PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
    std::string  getTarget() const;
    void execute(Bureaucrat const & executor) const;
};


#endif
