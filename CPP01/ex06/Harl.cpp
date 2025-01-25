/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:09:21 by adesille          #+#    #+#             */
/*   Updated: 2025/01/25 13:48:43 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level) {
    int levelIndex = 4;

    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            levelIndex = i;
            break;
        }
    }

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

Harl::Harl() {
    actions["debug"] = &Harl::debug;
    actions["info"] = &Harl::info;
    actions["warning"] = &Harl::warning;
    actions["error"] = &Harl::error;
}

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
