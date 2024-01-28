//
// Created by Karina Logvina on 14.11.23.
//

#include "Bureaucrat.hpp"

# define NUM 12

int main() {
  {
    std::cout << "------- 1 ------" << std::endl;
    try {
      Bureaucrat biba("Biba", 2);
      std::cout << biba << std::endl;
      for (int i = 0; i < NUM; i++) {
        biba.incrementGrade();
        std::cout << biba << std::endl;
      }
    } catch (std::exception const &exception) {
      std::cout << "Error:" << exception.what() << std::endl;
    }
  }
  {
    std::cout << "------- 2 ------" << std::endl;
    try {
      Bureaucrat boba("Boba", 14);
      std::cout << boba << std::endl;
      for (int i = 0; i < NUM; i++) {
        boba.decrementGrade();
        std::cout << boba << std::endl;
      }
    } catch (std::exception const &exception) {
      std::cout << "Error:" << exception.what() << std::endl;
    }
  }

  {
    std::cout << "------- 3 ------" << std::endl;
    try {
      Bureaucrat leo("leo", -2);
      std::cout << leo << std::endl;
    } catch (std::exception const &exception) {
      std::cout << "Error:" << exception.what() << std::endl;
    }
  }
  {
    std::cout << "------- 4 ------" << std::endl;
    try {
      Bureaucrat kim("kim", 157);
      std::cout << kim << std::endl;
    } catch (std::exception const &exception) {
      std::cout << "Error:" << exception.what() << std::endl;
    }
  }

  {
    std::cout << "------- 5 ------" << std::endl;
    try {
      Bureaucrat over("Over", 140);
      std::cout << over << std::endl;
      for (int i = 0; i < NUM; i++) {
        over.incrementGrade();
        std::cout << over << std::endl;
      }
    } catch (std::exception const &exception) {
      std::cout << "Error:" << exception.what() << std::endl;
    }
  }

  {
    std::cout << "------- 6 ------" << std::endl;
    try {
      Bureaucrat low("Low", 5);
      std::cout << low << std::endl;
      for (int i = 0; i < NUM; i++) {
        low.decrementGrade();
        std::cout << low << std::endl;
      }
    } catch (std::exception const &exception) {
      std::cout << "Error:" << exception.what() << std::endl;
    }
  }
}