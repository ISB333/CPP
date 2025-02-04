/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:53:55 by adesille          #+#    #+#             */
/*   Updated: 2025/02/04 11:54:54 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& src) {
	*this = src;
	std::cout << "Copy Brain constructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain& rhs) {
	if (this != &rhs)
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	std::cout << "Brain assignement operator called" << std::endl;
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}
