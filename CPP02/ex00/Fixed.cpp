/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb <isb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 07:10:14 by isb               #+#    #+#             */
/*   Updated: 2025/03/10 07:16:56 by isb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_nFixed = 8;

Fixed::Fixed() : _rawValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& value) {
    std::cout << "Copy constructor called" << std::endl;
    *this = value;
}

Fixed& Fixed::operator=(const Fixed& value) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &value)
        this->_rawValue = value.getRawBits();
    return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    return (this->_rawValue);
}

void Fixed::setRawBits(int const raw) {
    this->_rawValue = raw;
}
