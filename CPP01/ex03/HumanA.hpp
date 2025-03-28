/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:42:58 by adesille          #+#    #+#             */
/*   Updated: 2025/03/07 07:52:55 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
# include <string>
# include "Weapon.hpp"

class	Weapon;

class	HumanA {
	public:
		HumanA(std::string HumanName, Weapon &weapon);
		~HumanA();
		void attack();

	private:
		std::string name;
		Weapon &weapon;
};
