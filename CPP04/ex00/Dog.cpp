/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 08:30:32 by adesille          #+#    #+#             */
/*   Updated: 2025/02/04 11:38:21 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Default Dog constructor called"  << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src) {
	std::cout << "Copy Dog constructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& rhs) {
	if (this != &rhs)
		Animal::operator=(rhs);
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called for " << _type << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Ouaf" << std::endl;
}
