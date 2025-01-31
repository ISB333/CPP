/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 08:52:14 by adesille          #+#    #+#             */
/*   Updated: 2025/01/31 12:21:11 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ClapTrap.hpp"

int main() {
	std::cout << "\n=== " << "CONSTRUCTOR TESTS" << " ===" << std::endl;
	{
		ClapTrap a;
		a.attack("Target");
		a.takeDamage(5);
		
		ClapTrap b("Terminator");
		b.attack("Target");
		
		ClapTrap c(b);
		b.takeDamage(10);
		c.attack("Target");
		
		ClapTrap d;
		d = a;
		d.takeDamage(4);
		d.beRepaired(2);
		a.attack("Target");
	}

	std::cout << "\n=== " << "BASIC COMBAT TESTS" << " ===" << std::endl;
	{
		ClapTrap warrior("Warrior");
		
		warrior.attack("Enemy");
		warrior.takeDamage(5);
		warrior.beRepaired(2);
		warrior.attack("Enemy");
	}

	std::cout << "\n=== " << "DEATH TESTS" << " ===" << std::endl;
	{
		ClapTrap victim("Victim");
		
		victim.takeDamage(5);
		victim.takeDamage(5);
		victim.takeDamage(5);
		victim.beRepaired(5);
		victim.attack("Someone");
	}

	std::cout << "\n=== " << "COMPLEX SEQUENCE TEST" << " ===" << std::endl;
	{
		ClapTrap hero("Hero");
		
		hero.attack("Villain");
		hero.takeDamage(5);
		hero.beRepaired(2);
		hero.takeDamage(4);
		hero.beRepaired(1);
		hero.attack("Villain");
		hero.attack("Villain");
		hero.takeDamage(4);
		hero.beRepaired(10);
		hero.attack("Villain");
	}

	return (0);
}
