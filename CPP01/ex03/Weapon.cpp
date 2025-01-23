/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:42:38 by adesille          #+#    #+#             */
/*   Updated: 2025/01/23 12:16:47 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string	&Weapon::getType() {
	return (type);
}

void Weapon::setType(std::string newType) {
    type = newType;
}

Weapon::Weapon(std::string typeName) : type(typeName){};

Weapon::~Weapon(){
	std::cout << "Weapon " << type << " has been destroyed!" << std::endl;
}
