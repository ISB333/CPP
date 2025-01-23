/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:54:27 by adesille          #+#    #+#             */
/*   Updated: 2025/01/23 12:13:20 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class	Weapon;

class	HumanB {

public:
	HumanB(std::string HumanName);
	HumanB(std::string HumanName, Weapon &weapon);
	~HumanB();
	void attack();
	void setWeapon(Weapon &weapon);

private:
	std::string name;
	Weapon *weapon;

};

#endif