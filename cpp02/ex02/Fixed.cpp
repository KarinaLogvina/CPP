/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:09:17 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/10/04 19:38:32 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _floatingPointNumber(0) {
    // std::cout << "Default constructor called" <<  std::endl;
    return;
};

Fixed::Fixed(const int num): _floatingPointNumber(num << _bits) {
    // std::cout << "Int constructor called" <<  std::endl;
    return;
};

Fixed::Fixed(const float num): _floatingPointNumber(std::roundf( num * ( 1 << _bits ))) {
    // std::cout << "Float constructor called" <<  std::endl;
    return;
};

Fixed::Fixed(Fixed const & other) {
    // std::cout << "Copy constructor called" <<  std::endl;
    *this = other;
};

Fixed & Fixed::operator=(const Fixed & rhs) {
    if (this != & rhs)
    {
        // std::cout << "Assignation operator called" << std::endl;
        this->_floatingPointNumber = rhs.getRawBits();
    }
    return *this;
};

float Fixed::toFloat() const {
    return ((float)_floatingPointNumber / (float)(1 << _bits));
}

int     Fixed::toInt() const {
    return (_floatingPointNumber >> _bits);
}

int Fixed::getRawBits(void) const {
    return _floatingPointNumber;
};

void Fixed::setRawBits (int const raw) {
    this->_floatingPointNumber = raw;
	return;
}

bool Fixed::operator>(Fixed const & rhs) const {
  return (_floatingPointNumber > rhs.getRawBits());
};

bool Fixed::operator<(Fixed const & rhs) const {
  return (_floatingPointNumber < rhs.getRawBits());
};

bool Fixed::operator>=(Fixed const & rhs) const {
  return (_floatingPointNumber >= rhs.getRawBits());
};

bool Fixed::operator<=(Fixed const & rhs) const {
  return (_floatingPointNumber <= rhs.getRawBits());
};

bool Fixed::operator==(Fixed const & rhs) const {
  return (_floatingPointNumber == rhs.getRawBits());
};

bool Fixed::operator!=(Fixed const & rhs) const {
  return (_floatingPointNumber != rhs.getRawBits());
};

Fixed & Fixed::operator+(Fixed const & rhs) {
    this->setRawBits(_floatingPointNumber + rhs.getRawBits());
    return *this;
}

Fixed & Fixed::operator-(Fixed const & rhs) {
    this->setRawBits(_floatingPointNumber - rhs.getRawBits());
    return *this;
}
Fixed & Fixed::operator*(Fixed const & rhs) {
    this->setRawBits(_floatingPointNumber * rhs.getRawBits() / (1 << _bits));
    return *this;
}
Fixed & Fixed::operator/(Fixed const & rhs) {
    this->setRawBits((_floatingPointNumber * (1 << _bits)) / rhs.getRawBits());
    return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return temp;
}


Fixed & Fixed::operator++(void) {
    _floatingPointNumber++;
    return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return temp;
}


Fixed & Fixed::operator--(void) {
    _floatingPointNumber--;
    return *this;
}

Fixed & Fixed::min(Fixed & left, Fixed & right)
{
	return (left > right ? right : left);
}

const Fixed & Fixed::min(Fixed const & left, Fixed const & right)
{
	return (left > right ? right : left);
}

Fixed & Fixed::max(Fixed & left, Fixed & right)
{
	return (left > right ? left : right);
}

const Fixed & Fixed::max(Fixed const & left, Fixed const & right)
{
	return (left > right ? left : right);
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}


std::ostream & operator<<( std::ostream & os, Fixed const & num ) {
    os << num.toFloat();
    return os;
}