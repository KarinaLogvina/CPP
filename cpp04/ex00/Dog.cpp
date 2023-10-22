/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:59:08 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/10/07 17:00:34 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Default Dog constructor called" << std::endl;
    this->type = "Dog";
};

Dog::Dog(Dog const & other) : Animal(other) {
	std::cout << "Copy Dog constructor called" << std::endl;
	*this = other;
};

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
};

void Dog::makeSound() const {
    std::cout << "bark" << std::endl;
};

Dog & Dog::operator=(Dog const & rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
    }
	return *this;
};

