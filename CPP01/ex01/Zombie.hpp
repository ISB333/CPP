/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:07:43 by adesille          #+#    #+#             */
/*   Updated: 2025/01/25 13:50:31 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
	public:
		void	announce( void );
		void	setName(std::string zombieName);
		Zombie();
		~Zombie();

	private:
		std::string	name;
};

Zombie*		zombieHorde( int N, std::string name );

#endif
