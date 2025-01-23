/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:59:26 by adesille          #+#    #+#             */
/*   Updated: 2025/01/23 12:17:12 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void	HumanA::attack(void) {
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " has no weapon to attack with!" << std::endl;
}

HumanA::HumanA(std::string HumanName) : name(HumanName), weapon(NULL) {}

HumanA::HumanA(std::string HumanName, Weapon &weapon) : name(HumanName), weapon(&weapon) {}

HumanA::~HumanA() {
    std::cout << "HumanA " << name << " has been destroyed!" << std::endl;
}

void HumanA::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}
