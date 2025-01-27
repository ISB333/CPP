/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:57:28 by adesille          #+#    #+#             */
/*   Updated: 2025/01/27 12:22:38 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScavTrap.hpp"

void ScavTrap::guardGate() {
	std::cout << _Name << " is now in Gatekeeper mode!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap constructor called for " << "Gérard" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called for " << _Name << std::endl;
}
