/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urosby <urosby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:24:46 by urosby            #+#    #+#             */
/*   Updated: 2024/02/17 17:37:11 by urosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

RPN::RPN() : _result(0){};
RPN::RPN(RPN const & other) { 
    *this = other; 
};

RPN::~RPN(){};

RPN & RPN::operator=(RPN const & rhs) {
    if (this != &rhs) {
        this->_result = rhs._result;
        this->_stack = rhs._stack;
    }
    return * this;
}

bool RPN::isOperator(char c) {
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

int RPN::getResult() const {
    return this->_result;
}

void RPN::calc(int number1, int number2, char oper) {
    switch (oper) {
    case '+':
        _stack.push(number1 + number2);
        break;
    case '-':
        _stack.push(number1 - number2);
        break;
    case '/':
        if (number2 == 0) {
            throw std::runtime_error("Error: division by 0");
        }
        _stack.push(number1 / number2);
        break;
    case '*':
        _stack.push(number1 * number2);
        break;
    default:
        break;
    }
}

void RPN::reversePolishNotation(std::string const & expr) {
  std::string token;

  for (size_t i = 0; i < expr.length(); i++)
  {
    char c = expr[i];
    if (c == ' ')
      continue;
    else if (isdigit(c))
      token += c;
    else if (isOperator(c))
    {
      if (_stack.size() < 2)
        throw std::runtime_error("Error: insufficient operands");
      int number2 = _stack.top();
      _stack.pop();
      int number1 = _stack.top();
      _stack.pop();
      calc(number1, number2, c);
    }
    else
      throw std::runtime_error("Error: invalid token");
    if (!token.empty())
    {
      _stack.push(atoi(token.c_str()));
      token.clear();
    }
  }
  if (_stack.size() != 1)
    throw std::runtime_error("Error: too many operands");
  _result = _stack.top();
  _stack.pop();
}

std::ostream &	operator<<(std::ostream & os, RPN const & i) {
	os << i.getResult();
	return os;
}
