/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Poly.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:55:00 by adesille          #+#    #+#             */
/*   Updated: 2025/01/27 14:27:06 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once

#include <iostream>

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


class	Animal {
	public:
		Animal();
		Animal();
		Animal(std::string animalType);
		virtual ~Animal() = 0;
		
		void		getType();

	private:
		std::string type;	
};

class Dog : public Animal {
	public:
		void		makeSound();	
};

class Cat : public Animal {
	public:
		void		makeSound();	
};
