/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:57:28 by adesille          #+#    #+#             */
/*   Updated: 2025/04/14 12:42:35 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap constructor called for " << "Gérard" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) { }

ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other)	{
		ClapTrap::operator=(other);
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called for " << _Name << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << MAGENTA << _Name << " is now in Gatekeeper mode!" << RESET << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (_energyPoints && _hitPoints)
		_energyPoints--;
	else {
		std::cout << RED << "no more energy left L00SER" << RESET << std::endl;
		return ;
	}
	std::cout << RED << "ScavTrap " << _Name << " attacks " << target << ", causing " 
		<< _attackDamage << " points of damage!" << RESET << std::endl;
}
