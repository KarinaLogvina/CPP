/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:56:36 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/10/07 17:57:46 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "Default WrongCat constructor called" << std::endl;    
}

WrongCat::WrongCat(WrongCat const & other) {
    std::cout << "Copy WrongCat constructor called" << std::endl;
	*this = other;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound(void) const {
	std::cout << "It's WrongCat sound!" << std::endl;
}

std::string WrongCat::getType(void) const{
	return this->type;
}

WrongCat & WrongCat::operator=(WrongCat const & rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
    }
	return *this;
};

