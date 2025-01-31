/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:16:25 by adesille          #+#    #+#             */
/*   Updated: 2025/01/27 14:23:55 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

////   Example   ////
void example(){
	// Converting 3.14 with 8 fractional bits
	float value = 3.14;
	int bits = 8;

	// Step 1: Scale factor = 256 (1 << 8)
	// Step 2: 3.14 * 256 = 803.84
	// Step 3: 803.84 + 0.5 = 804.34
	// Step 4: static_cast<int>(804.34) = 804

	// To convert back:
	float result = 804.0f / 256.0f; // ≈ 3.140625
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

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
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
