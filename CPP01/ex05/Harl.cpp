/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:09:21 by adesille          #+#    #+#             */
/*   Updated: 2025/03/07 08:10:10 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Harl.hpp"

void Harl::complain(std::string level) {
	void	(Harl::*actions[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			(this->*actions[i])();
			return;
		}
	}
	std::cerr << "Unknown complaint level: " << level << std::endl;
}

Harl::Harl() {}

Harl::~Harl() {}

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
