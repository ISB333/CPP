/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:16:25 by adesille          #+#    #+#             */
/*   Updated: 2025/01/28 09:07:00 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Fixed.hpp"

Fixed::Fixed() {
	_rawValue = 0;
}

Fixed::Fixed(const int value) {
	this->_rawValue = value << this->_nFixed;
}

Fixed::Fixed(const float value) {
	this->_rawValue = static_cast<int>(roundf(value * (1 << this->_nFixed)));
}

Fixed::Fixed(const Fixed& value) {
	this->setRawBits(value.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& value) {
	if (this != &value)
		this->_rawValue = value.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}

Fixed::~Fixed() {}

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

bool Fixed::operator>(const Fixed& other) const {
	return (this->_rawValue > other._rawValue);
}

bool Fixed::operator<(const Fixed& other) const {
	return (this->_rawValue < other._rawValue);
}

bool Fixed::operator>=(const Fixed& other) const {
	return (this->_rawValue >= other._rawValue);
}

bool Fixed::operator<=(const Fixed& other) const {
	return (this->_rawValue <= other._rawValue);
}

bool Fixed::operator==(const Fixed& other) const {
	return (this->_rawValue == other._rawValue);
}

bool Fixed::operator!=(const Fixed& other) const {
	return (this->_rawValue != other._rawValue);
}

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->_rawValue + other._rawValue);
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->_rawValue - other._rawValue);
	return (result);
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;
	result.setRawBits((this->_rawValue * other._rawValue) >> this->_nFixed);
	return (result);
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed result;
	result.setRawBits((this->_rawValue << this->_nFixed) / other._rawValue);
	return (result);
}

Fixed& Fixed::operator++() {
	++this->_rawValue;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++this->_rawValue;
	return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return ((a < b) ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return ((a < b) ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return ((a > b) ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return ((a > b) ? a : b);
}
