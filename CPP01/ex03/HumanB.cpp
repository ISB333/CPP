/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:59:26 by adesille          #+#    #+#             */
/*   Updated: 2025/01/23 12:16:59 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack(void) {
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " has no weapon to attack with!" << std::endl;
}

HumanB::HumanB(std::string HumanName) : name(HumanName), weapon(NULL) {}

HumanB::HumanB(std::string HumanName, Weapon &weapon) : name(HumanName), weapon(&weapon) {}

HumanB::~HumanB() {
    std::cout << "HumanB " << name << " has been destroyed!" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}
