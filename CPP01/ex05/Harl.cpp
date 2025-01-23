/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:09:21 by adesille          #+#    #+#             */
/*   Updated: 2025/01/23 13:02:03 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level) {
	std::map<std::string, Action>::iterator it = actions.find(level);
	if (it != actions.end())
		(this->*(it->second))();
	else
		std::cerr << "Unknown complaint level: " << level << std::endl;
}

Harl::Harl() {
	actions["debug"] = &Harl::debug;
	actions["info"] = &Harl::info;
	actions["warning"] = &Harl::warning;
	actions["error"] = &Harl::error; 
}

void	Harl::debug( void ) {
	std::cout << DEBUG << std::endl;
}

void	Harl::info( void ) {
	std::cout << INFO << std::endl;
}

void	Harl::warning( void ) {
	std::cout << WARNING << std::endl;
}

void	Harl::error( void ) {
	std::cout << ERROR << std::endl;
}
