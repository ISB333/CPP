/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:37:08 by adesille          #+#    #+#             */
/*   Updated: 2025/03/07 07:43:43 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
# include <iostream>
# include "HumanA.hpp"
# include "HumanB.hpp"

class Weapon {
	public:
		Weapon(std::string typeName);
		~Weapon();
		const std::string	&getType() const;
		void				setType(std::string);

	private:
		std::string type;
};
