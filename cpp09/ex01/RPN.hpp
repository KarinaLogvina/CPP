/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urosby <urosby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:46:14 by urosby            #+#    #+#             */
/*   Updated: 2024/02/17 16:35:37 by urosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>

class RPN {
    private:
        std::stack<int>_stack;
        int _result;
    public:
        RPN();
        ~RPN();
        RPN(RPN const & other);
        RPN & operator=(RPN const &rhs);
        void calc(int number1, int number2, char oper);
        void reversePolishNotation(std::string const & expr);
        bool isOperator(char c);
        int getResult() const;
};

std::ostream &	operator<<(std::ostream & os, RPN const & i);

#endif
