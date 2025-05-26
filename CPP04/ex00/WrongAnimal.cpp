/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:00:00 by adesille          #+#    #+#             */
/*   Updated: 2025/04/25 08:46:25 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << "WrongAnimal constructor called for " << _type << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "WrongAnimal constructor called for " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) : _type(src._type) {
	std::cout << "WrongAnimal copy constructor called for " << _type << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& rhs) {
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called for " << _type << std::endl;
}

std::string		WrongAnimal::getType() const {
	return (_type);
}

void	WrongAnimal::makeSound() const {
	std::cout << "* Generic wrong animal sound *" << std::endl;
}
