/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:49:08 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/11/07 22:40:46 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat() {
    std::cout << "Default Cat constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
};

Cat::Cat(Cat const & other) : AAnimal(other) {
	std::cout << "Copy Cat constructor called" << std::endl;
    this->brain = new Brain(*(other.brain));
    this->type = other.getType();
	// *this = other;
};

Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "meow" << std::endl;
}

Brain * Cat::getBrain(void) const {
	return this->brain;
}

Cat & Cat::operator=(Cat const & rhs) {
	if (this != &rhs) {
        if (this->brain) {
            delete this->brain;
        }
        this->brain = new Brain();
        *this->brain = *rhs.brain;
		this->type = rhs.getType();
    }
	return *this;
}

