/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:01:43 by adesille          #+#    #+#             */
/*   Updated: 2025/04/25 08:48:14 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << "Animal constructor called for " << _type << std::endl;
}

Animal::Animal(const Animal& src) : _type(src._type) {
	std::cout << "Animal copy constructor called for " << _type << std::endl;
}

Animal&			Animal::operator=(const Animal& rhs) {
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal constructor called for " << type << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called for " << _type << std::endl;
}

std::string		Animal::getType() const {
	return (_type);
}

void	Animal::makeSound() const {
	std::cout << "* Generic animal sound *" << std::endl;
}
