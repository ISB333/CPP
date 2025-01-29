/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Poly.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:55:00 by adesille          #+#    #+#             */
/*   Updated: 2025/01/28 08:58:25 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once

#include <iostream>
#include <memory>

# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"
# define HYEL 		"\e[0;93m"
# define RESET		"\033[0m"


class	Animal {
	public:
		Animal();
		Animal(const Animal& src);
		Animal(std::string type);
		virtual ~Animal();
		
		Animal&			operator=(const Animal& rhs);
		std::string		getType() const;
		virtual void	makeSound() const;

	protected:
		std::string _type;	
};

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog& src);
		virtual ~Dog(); // Assure destruction of derived class and potential future inheritance of this Class
		
		Dog& 			operator=(const Dog& rhs);
		virtual void	makeSound() const; // To call this derived Class Functions from the base Class
};

class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat& src);
		virtual ~Cat();
		
		Cat& 			operator=(const Cat& rhs);
		virtual void	makeSound() const;
};
