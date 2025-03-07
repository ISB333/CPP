/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:59:26 by adesille          #+#    #+#             */
/*   Updated: 2025/03/07 07:54:44 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "HumanA.hpp"

void	HumanA::attack(void) {
	std::cout << name << " attacks with his " << (&weapon)->getType() << std::endl;
}

HumanA::HumanA(std::string HumanName, Weapon &weapon) : name(HumanName), weapon(weapon) {}

HumanA::~HumanA() {
    std::cout << "HumanA " << name << " has been destroyed!" << std::endl;
}
