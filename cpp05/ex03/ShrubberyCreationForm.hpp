//
// Created by Karina Logvina on 18.12.23.
//

#ifndef CPP05_SHRUBBERYCREATIONFORM_HPP
#define CPP05_SHRUBBERYCREATIONFORM_HPP

#include "ShrubberyCreationForm.hpp"
# include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm{
  private:
    ShrubberyCreationForm();
    std::string _target;

  public:
    ShrubberyCreationForm(std::string const & target);
    ShrubberyCreationForm(ShrubberyCreationForm const & other);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm & operator=(ShrubberyCreationForm const &rhs);
    std::string getTarget() const;
    void execute (Bureaucrat const & executor) const;
    class WriteToFileException : public std::exception
    {
    public:
      const char * what() const throw();
    };
};


#endif
