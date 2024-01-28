//
// Created by Karina Logvina on 18.12.23.
//

# include "ShrubberyCreationForm.hpp"
# include <fstream>

//ShrubberyCreationForm::ShrubberyCreationForm() {};
ShrubberyCreationForm::~ShrubberyCreationForm() {};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(target, 145, 137), _target(target){};
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other), _target(other.getTarget()) {};

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
  AForm::operator=(rhs);
  if (this != &rhs)
    this->_target = rhs.getTarget();
  return *this;
}

std::string ShrubberyCreationForm::getTarget() const {
  return this->_target;
}

const char * ShrubberyCreationForm::WriteToFileException::what() const throw() {
  return "Error. Can not create file";
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
  checkRequirementsToExecute(executor);
  std::string outputFile = this->_target + "_shrubbery";
  std::ofstream ofs(outputFile.c_str());
  std::string christmas_Tree =
  "                  t                  \n"
  "                 .#.                 \n"
  "                .###.                \n"
  "               .#%##%.               \n"
  "              .%##%###.              \n"
  "             .##%###%##.             \n"
  "            .#%###%##%##.            \n"
  "                  #                  \n"
  "                  #                  \n";
  ofs << christmas_Tree;
  ofs.close();
  if (ofs.fail())
    throw WriteToFileException();
}