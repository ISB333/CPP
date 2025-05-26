/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:00:00 by adesille          #+#    #+#             */
/*   Updated: 2025/04/25 08:46:29 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src) {
	std::cout << "Copy WrongCat constructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& rhs) {
	if (this != &rhs)
		WrongAnimal::operator=(rhs);
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called for " << _type << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "Wrong Miaou" << std::endl;
}
