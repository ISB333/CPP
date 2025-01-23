/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:16:28 by adesille          #+#    #+#             */
/*   Updated: 2025/01/23 12:25:49 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string zombieName) {
	name = zombieName;
};

Zombie::Zombie() : name("Unknown"){};

Zombie::~Zombie() {
	std::cout << "Zombie " << name << " has been destroyed!" << std::endl;
};
