/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:42:58 by adesille          #+#    #+#             */
/*   Updated: 2025/01/23 12:13:04 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class	Weapon;

class	HumanA {

public:
	HumanA(std::string HumanName);
	HumanA(std::string HumanName, Weapon &weapon);
	~HumanA();
	void attack();
	void setWeapon(Weapon &weapon);

private:
	std::string name;
	Weapon *weapon;

};

#endif