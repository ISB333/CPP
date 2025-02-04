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

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Default Cat constructor called"  << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src) {
	std::cout << "Copy Cat constructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& rhs) {
	if (this != &rhs)
		Animal::operator=(rhs);
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called for " << _type << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Miaou" << std::endl;
}
