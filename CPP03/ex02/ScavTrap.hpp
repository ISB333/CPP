/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:56:42 by adesille          #+#    #+#             */
/*   Updated: 2025/01/27 12:19:05 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(std::string name);
		ScavTrap();
		~ScavTrap();

		void	guardGate();
	
};
