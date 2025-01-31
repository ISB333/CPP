/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 08:52:14 by adesille          #+#    #+#             */
/*   Updated: 2025/01/31 12:30:29 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScavTrap.hpp"

int main() {
	std::cout << HYEL << "====== CLAPTRAP ======\n" << RESET << std::endl;
	{
		ClapTrap a("Bernadette");
		ClapTrap b("Germaine");

		std::cout << "\nDamage and Repair Test:" << std::endl;
		b.takeDamage(50);
		b.beRepaired(20);
		b.takeDamage(70);
		b.beRepaired(10);
		b.attack("Huguette");
	}

	std::cout << HYEL << "\n\n====== SCAVTRAP ======\n" << RESET << std::endl;
	{
		ScavTrap a("Marcel");
		ScavTrap b("Lucienne");

		std::cout << "\nComplex interaction test:" << std::endl;
		b.guardGate();
		b.attack("Henriette");
		b.takeDamage(30);
		b.guardGate();
		b.beRepaired(15);
		b.attack("Gaston");

		std::cout << "\nNear-death scenario test:" << std::endl;
		a.takeDamage(90);
		a.beRepaired(40);
		a.guardGate();
		a.takeDamage(50);
		a.guardGate();
		a.attack("Madeleine");
	}
	return (0);
}
