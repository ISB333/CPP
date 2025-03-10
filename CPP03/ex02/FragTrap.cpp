/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:16:40 by adesille          #+#    #+#             */
/*   Updated: 2025/01/27 13:42:213 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap constructor called for " << "Gérard" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap constructor called for " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) {
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap &other) {
	if (this != &other)	{
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called for " << _Name << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "Let's do a High Five " << _Name << "!" << std::endl;
	std::cout << "👋🙏👋🙏👋🙏👋🙏👋🙏👋🙏👋🙏👋🙏👋🙏👋🙏👋🙏👋🙏👋🙏👋🙏" << std::endl;
}
