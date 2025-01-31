/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:09:21 by adesille          #+#    #+#             */
/*   Updated: 2025/01/31 12:03:57 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Harl.hpp"

int	findLevelIndex(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			return (i);
		}
	}
	return (4);
}

void Harl::complain(std::string level) {
	int levelIndex = findLevelIndex(level);

	switch (levelIndex) {
	case 0:
		std::cout << "[ DEBUG ]" << std::endl;
		debug();
	case 1:
		std::cout << "[ INFO ]" << std::endl;
		info();
	case 2:
		std::cout << "[ WARNING ]" << std::endl;
		warning();
	case 3:
		std::cout << "[ ERROR ]" << std::endl;
		error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]"
				  << std::endl;
	}
}

Harl::Harl() {}

void Harl::debug(void) { 
	std::cout << DEBUG << std::endl;
}

void Harl::info(void) {
	std::cout << INFO << std::endl;
}

void Harl::warning(void) {
	std::cout << WARNING << std::endl;
}

void Harl::error(void) {
	std::cout << ERROR << std::endl;
}
