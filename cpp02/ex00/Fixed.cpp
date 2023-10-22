/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:09:44 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/10/22 14:30:16 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
    std::cout << "Default constructor called" <<  std::endl;
    return;
};

Fixed::Fixed(Fixed const & other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed & rhs) {
    if (this != & rhs)
    {
        std::cout << "Copy assignment operator called" << std::endl;
        this->_rawBits = rhs.getRawBits();
    }
    return *this;
};

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_rawBits);
};

void Fixed::setRawBits (int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_rawBits = raw;
	return;
}
