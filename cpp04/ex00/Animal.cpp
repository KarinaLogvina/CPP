/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:25:12 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/10/22 13:48:55 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Default Animal constructor called" << std::endl;
};

Animal::Animal(Animal const & other) {
	std::cout << "Copy Animal constructor called" << std::endl;
	*this = other;
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound(void) const {
	std::cout << "Animal makes sound!" << std::endl;
}

std::string Animal::getType(void) const {
	return this->type;
}


Animal & Animal::operator=(Animal const & rhs) {
    if (this != & rhs) {
        std::cout << "Assignation operator called" << std::endl;
        this->type = rhs.type;
    }
    return *this;
}

