/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:07:43 by adesille          #+#    #+#             */
/*   Updated: 2025/01/23 12:28:23 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {

public:

	void		announce( void );
	Zombie(std::string zombieName);
	~Zombie();

private:

	std::string	name;

};

Zombie*		newZombie( std::string name );
void		randomChump( std::string name );

#endif