/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 08:52:14 by adesille          #+#    #+#             */
/*   Updated: 2025/01/31 12:40:55 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	std::cout << HYEL << "====== CLAPTRAP TESTS ======\n" << RESET << std::endl;
	{
		ClapTrap a("Jacqueline");
		ClapTrap b = a;
		ClapTrap c("Marcel");
		c = a;
		
		a.attack("Bernadette");
		b.attack("Raymond");
		c.attack("Henriette");
		
		a.takeDamage(5);
		a.beRepaired(2);
		a.takeDamage(8);
		
		b.takeDamage(3);
		b.beRepaired(1);
		b.attack("Simone");
		b.takeDamage(10);
		b.beRepaired(5);
		
		c.beRepaired(2);
		c.attack("Marguerite");
		c.takeDamage(15);
	}
	
	std::cout << HYEL << "\n\n====== SCAVTRAP TESTS ======\n" << RESET << std::endl;
	{
		ScavTrap a("Lucienne");
		ScavTrap b(a);
		ScavTrap c("Jean-Pierre");
		c = a;
		
		a.guardGate();
		b.guardGate();
		c.guardGate();
		
		std::cout << HYEL << "\n=== Testing original after copy ===\n" << RESET << std::endl;
		a.attack("Paulette");
		a.takeDamage(30);
		a.beRepaired(15);
		
		std::cout << HYEL << "\n=== Testing copy constructed ===\n" << RESET << std::endl;
		b.attack("Germaine");
		b.takeDamage(25);
		b.beRepaired(10);
		b.attack("André");
		
		std::cout << HYEL << "\n=== Testing assigned copy ===\n" << RESET << std::endl;
		c.attack("André");
		c.takeDamage(40);
		c.beRepaired(20);
		c.attack("Madeleine");
	}
	
	std::cout << HYEL << "\n\n====== FRAGTRAP TESTS ======\n" << RESET << std::endl;
	{
		FragTrap a("Fernand");
		FragTrap b(a);
		FragTrap c("Yvette");
		c = a;
		
		std::cout << HYEL << "\n=== Testing original ===\n" << RESET << std::endl;
		a.highFivesGuys();
		a.attack("Roger");
		
		std::cout << HYEL << "\n=== Testing copy constructed ===\n" << RESET << std::endl;
		b.highFivesGuys();
		b.attack("Georgette");
		
		std::cout << HYEL << "\n=== Testing assigned copy ===\n" << RESET << std::endl;
		c.highFivesGuys();
		c.attack("Raymond");
		
		std::cout << HYEL << "\n=== Testing independence of copies ===\n" << RESET << std::endl;
		a.takeDamage(50);
		b.takeDamage(35);
		c.takeDamage(45);
		a.beRepaired(25);
		b.beRepaired(15);
		c.beRepaired(30);
	}
	return (0);
}
