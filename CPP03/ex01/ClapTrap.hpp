/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 10:46:07 by adesille          #+#    #+#             */
/*   Updated: 2025/02/04 09:53:43 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once

# include <iostream>

# define BLACK	"\033[30m"
# define RED		"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN	"\033[36m"
# define WHITE	"\033[37m"
# define HYEL "\e[0;93m"
# define RESET	"\033[0m"

class	ClapTrap {
	public:
		void 		attack(const std::string& target);
		void 		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);

		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		ClapTrap& operator=(const ClapTrap &other);
	
		virtual ~ClapTrap();

	protected:
		std::string	_Name;
		int 		_hitPoints;
		int 		_energyPoints;
		int 		_attackDamage;
};
