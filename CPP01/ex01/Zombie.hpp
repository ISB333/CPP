/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:07:43 by adesille          #+#    #+#             */
/*   Updated: 2025/03/07 07:40:59 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
# include <iostream>

class Zombie {
	public:
		Zombie();
		~Zombie();
		void	announce( void );
		void	setName(std::string zombieName);

	private:
		std::string	name;
};

Zombie*		zombieHorde( int N, std::string name );
