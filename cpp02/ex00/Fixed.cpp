/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:09:44 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/09/29 17:09:45 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
    std::cout << "Default constructor called" <<  std::endl;
    return;
};

Fixed::Fixed(Fixed const & other) {
    *this = other;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed & rhs) {
    if (this != & rhs)
    {
        std::cout << "Assignation operator called" << std::endl;
        this->setRawBits(rhs.getRawBits());
    }
    return *this;
};

int Fixed::getRawBits(void) const {
    return (this->_rawBits);
};

void Fixed::setRawBits (int const raw) {
    this->_rawBits = raw;
	return;
}
