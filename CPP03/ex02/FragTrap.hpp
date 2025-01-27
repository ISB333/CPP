/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:44:40 by adesille          #+#    #+#             */
/*   Updated: 2025/01/27 11:47:39 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once

# include "ScavTrap.hpp"

class FragTrap : public ScavTrap {
	public:
		FragTrap(std::string name);
		FragTrap();
		~FragTrap();

	private:
		std::string _Name;
};
