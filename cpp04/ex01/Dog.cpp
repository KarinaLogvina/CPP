/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:59:08 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/11/08 18:56:05 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Default Dog constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
};

Dog::Dog(Dog const & other) : Animal(other) {
	std::cout << "Copy Dog constructor called" << std::endl;
    this->brain = new Brain(*(other.brain));
    this->type = other.getType();
	// *this = other;
};

Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
};

void Dog::makeSound() const {
    std::cout << "bark" << std::endl;
};

Brain * Dog::getBrain(void) const {
	return this->brain;
}

Dog & Dog::operator=(Dog const & rhs) {
	if (this != &rhs) {
        if (this->brain) {
            delete this->brain;
        }
        this->brain = new Brain();
        *this->brain = *rhs.brain;
		this->type = rhs.getType();
    }
	return *this;
};

