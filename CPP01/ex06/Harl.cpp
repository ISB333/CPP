/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:09:21 by adesille          #+#    #+#             */
/*   Updated: 2025/01/23 13:25:39 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

enum Level { DEBUG_, INFO_, WARNING_, ERROR_ };

Level	levelIdentifier(std::string str) {
	if (str == "debug")
		return (DEBUG_);
	if (str == "info")
		return (INFO_);
	if (str == "warning")
		return (WARNING_);
	return (ERROR_);
}

void Harl::complain(std::string level) {
	std::map<std::string, Action> it;

	switch (levelIdentifier(level))
	{
		case DEBUG_
			(this->*(debug->second))();
			break;
		
		default:
			break;
	}
	// if (it != actions.end())
	// 	(this->*(it->second))();
	// else
	// 	std::cerr << "Unknown complaint level: " << level << std::endl;
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
