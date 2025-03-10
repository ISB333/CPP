/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb <isb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:16:25 by adesille          #+#    #+#             */
/*   Updated: 2025/03/10 07:55:00 by isb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	_rawValue = 0;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->_rawValue = value << this->_nFixed;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->_rawValue = static_cast<int>(roundf(value * (1 << this->_nFixed)));
}

Fixed::Fixed(const Fixed& value) {
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(value.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& value) {
	std::cout << "Copy Assignement operator called" << std::endl;
	if (this != &value)
		this->_rawValue = value.getRawBits();
	return (*this);
}

// Overload of the '<<' operator for outputting Fixed numbers
// It allows you to use: std::cout << fixedNumber;
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const {
	return (this->_rawValue);
}

void Fixed::setRawBits(int const raw) {
	this->_rawValue = raw;
}

float Fixed::toFloat() const {
	return (static_cast<float>(this->_rawValue) / (1 << this->_nFixed));
}

int Fixed::toInt() const {
	return (this->_rawValue >> this->_nFixed);
}

/*
** Fixed Point Number Example - Converting 3.14 to Fixed Point
** --------------------------------------------------------
** We use 8 bits for the fractional part, meaning:
** - Multiply by 2^8 (256) to shift decimal point right 8 positions
** - Store as integer
** - Divide by 2^8 (256) to get back to float
**
** Converting float to fixed-point:
** ------------------------------
** float: 3.14
** 1. 3.14 * 256 (2^8)           = 803.84    // Move decimal 8 places right
** 2. Round(803.84)              = 804       // Round to nearest integer
** 3. Store 804 as raw integer   = 804       // This is our fixed-point number
**
** Binary representation:
** --------------------
** 804 in binary = 0000 0011 0010 0100
**                 ^^^^ ^^^^ |||| ||||
**                 Integer   Fractional
**                 Part      Part (8 bits)
**
** Converting back to float:
** -----------------------
** 804 / 256 = 3.140625   // Divide by 2^8 to restore decimal position

=====================================================================

/// Bitshift example ///
1 << 0 = 1     = 2^0 = 1
    0000 0001 -> 0000 0001 = 1

1 << 1 = 2     = 2^1 = 2
    0000 0001 -> 0000 0010 = 2

1 << 2 = 4     = 2^2 = 4
    0000 0001 -> 0000 0100 = 4

1 << 3 = 8     = 2^3 = 8
    0000 0001 -> 0000 1000 = 8

1 << 4 = 16    = 2^4 = 16
    0000 0001 -> 0001 0000 = 16

1 << 8 = 256   = 2^8 = 256
    0000 0001 -> 0001 0000 0000 = 256

*/
