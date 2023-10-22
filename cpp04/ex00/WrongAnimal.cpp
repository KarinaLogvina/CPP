/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:47:01 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/10/07 17:56:19 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "Default WrongAnimal constructor called" << std::endl;    
}

WrongAnimal::WrongAnimal(WrongAnimal const & other) {
    std::cout << "Copy WrongAnimal constructor called" << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "It's WrongAnimal sound!" << std::endl;
}

std::string WrongAnimal::getType(void) const{
	return this->type;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
    }
	return *this;
};

