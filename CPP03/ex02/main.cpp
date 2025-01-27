/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 08:52:14 by adesille          #+#    #+#             */
/*   Updated: 2025/01/27 12:06:41 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScavTrap.hpp"

int main() {
	std::cout << "### TESTING CLAPTRAP ###\n" << std::endl;
	{
		ScavTrap a;
		ScavTrap b("René");

		a.attack("Robert");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.guardGate();
		a.attack("Ginette");
		b.beRepaired(3);
		b.attack("la Mère Michelle");
		b.beRepaired(3);
		b.guardGate();
	}
	return (0);
}
