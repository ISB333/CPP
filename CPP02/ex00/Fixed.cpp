/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:16:25 by adesille          #+#    #+#             */
/*   Updated: 2025/01/26 10:09:54 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	_rawValue = 0;
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
