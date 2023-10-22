/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:49:08 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/10/21 17:43:43 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat() {
    std::cout << "Default Cat constructor called" << std::endl;
    this->type = "Cat";
};

Cat::Cat(Cat const & other) : Animal(other) {
	std::cout << "Copy Cat constructor called" << std::endl;
	*this = other;
};

Cat::~Cat() {
     std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "meow" << std::endl;
}

Cat & Cat::operator=(Cat const & rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
    }
	return *this;
}

