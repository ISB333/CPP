/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 08:30:32 by adesille          #+#    #+#             */
/*   Updated: 2025/02/04 11:50:52 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain()) {
	std::cout << "Default Dog constructor called"  << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src) {
	_brain = new Brain(*src._brain);
	std::cout << "Copy Dog constructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& rhs) {
	if (this != &rhs) {
		Animal::operator=(rhs);
		delete _brain;
		_brain = new Brain(*rhs._brain);
	}
	std::cout << "Dog assignement operator called" << std::endl;
	return (*this);
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog destructor called for " << _type << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Ouaf" << std::endl;
}
