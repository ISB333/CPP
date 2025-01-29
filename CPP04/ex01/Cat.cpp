/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 08:30:17 by adesille          #+#    #+#             */
/*   Updated: 2025/01/28 10:04:22by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Poly.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain()) {
	std::cout << "Default Cat constructor called"  << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src) {
	_brain = new Brain(*src._brain);
	std::cout << "Copy Cat constructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& rhs) {
	if (this != &rhs) {
		Animal::operator=(rhs);
		delete _brain;
		_brain = new Brain(*rhs._brain);
	}
	std::cout << "Cat assignement operator called" << std::endl;
	return (*this);
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat destructor called for " << _type << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Miaou" << std::endl;
}
