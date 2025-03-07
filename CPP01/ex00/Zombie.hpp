/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:07:43 by adesille          #+#    #+#             */
/*   Updated: 2025/03/07 07:41:09 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
# include <iostream>

class Zombie {
	public:
		Zombie(std::string zombieName);
		~Zombie();
		void		announce( void );
	
	private:
		std::string	name;
};

Zombie*		newZombie( std::string name );
void		randomChump( std::string name );
