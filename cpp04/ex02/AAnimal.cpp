/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:25:12 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/10/22 13:49:00 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() {
    std::cout << "Default Animal constructor called" << std::endl;
};

AAnimal::AAnimal(AAnimal const & other) {
	std::cout << "Copy Animal constructor called" << std::endl;
	*this = other;
}

AAnimal::~AAnimal(void) {
	std::cout << "Animal destructor called" << std::endl;
}

std::string AAnimal::getType(void) const {
	return this->type;
}

AAnimal & AAnimal::operator=(AAnimal const & rhs) {
    if (this != & rhs) {
        // std::cout << "Assignation operator called" << std::endl;
        this->type = rhs.type;
    }
    return *this;
}

