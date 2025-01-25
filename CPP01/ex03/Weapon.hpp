/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:37:08 by adesille          #+#    #+#             */
/*   Updated: 2025/01/25 13:50:19 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"

class HumanA;
class HumanB;

class Weapon {
	public:
		const std::string	&getType();
		void				setType(std::string);
		Weapon(std::string typeName);
		~Weapon();
		friend class HumanA;
		friend class HumanB;

	private:
		std::string type;
};

#endif
