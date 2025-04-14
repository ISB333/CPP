/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:27:20 by adesille          #+#    #+#             */
/*   Updated: 2025/04/14 11:59:36 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _Name("Gérard"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _Name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _Name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) { *this = other; }

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other)	{
		_Name = other._Name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _Name << " has been destroyed!" << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (_energyPoints && _hitPoints)
		_energyPoints--;
	else {
		std::cout << RED << "no more energy left L00SER" << RESET << std::endl;
		return ;
	}
	std::cout << RED << "ClapTrap " << _Name << " attacks " << target << ", causing " 
		<< _attackDamage << " points of damage!" << RESET << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints > 0)
		_hitPoints -= amount;
	else {
		std::cout << BLUE << "Bro is already dead, CALM DOWN YOU FUCKING SOCIOPATH" << RESET << std::endl;
		return ;
	}
	std::cout << BLUE << "ClapTrap " << _Name << " was attacked and lost " << amount << " hit points, points left: " << _hitPoints << RESET << std::endl;
}

void 	ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints > 0)
		_hitPoints += amount;
	else {
		std::cout << GREEN << "ClapTrap " << _Name << " is dead LOL, too late to repair da shit Bruh" << RESET << std::endl;
	}
	std::cout << GREEN << "ClapTrap " << _Name << " repaired itself with " << amount << " hit points, points left: " << _hitPoints << RESET << std::endl;
}
