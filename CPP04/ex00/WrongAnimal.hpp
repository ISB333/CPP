/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:00:00 by adesille          #+#    #+#             */
/*   Updated: 2025/04/25 08:46:51 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once

#include <iostream>

class	WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& src);
		virtual ~WrongAnimal();
		
		WrongAnimal&	operator=(const WrongAnimal& rhs);
		std::string		getType() const;
		void			makeSound() const; 

	protected:
		std::string _type;	
};
