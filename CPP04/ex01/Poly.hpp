/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Poly.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:55:00 by adesille          #+#    #+#             */
/*   Updated: 2025/01/29 09:29:16 by adesille         ###   ########.fr       */
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
		Animal(std::string type);
		Animal(const Animal& src);
		Animal&			operator=(const Animal& rhs);
		virtual ~Animal();
		
		std::string		getType() const;
		virtual void	makeSound() const;
		virtual	void	newBrain();

	protected:
		std::string _type;	
};

class	Brain {
	public:
		Brain();
		Brain(const Brain& src);
		Brain& 			operator=(const Brain& rhs);
		virtual ~Brain();

	private:
		std::string _ideas[100];
};

class	Dog : public Animal {
	public:
		Dog();
		Dog(const Dog& src);
		Dog& 			operator=(const Dog& rhs);
		virtual ~Dog(); // Assure destruction of derived class and potential future inheritance of this Class
		
		virtual void	makeSound() const; // To call this derived Class Functions from the base Class

	private:
		Brain* _brain;
};

class	Cat : public Animal {
	public:
		Cat();
		Cat(const Cat& src);
		Cat& 			operator=(const Cat& rhs);
		virtual ~Cat();
		
		virtual void	makeSound() const;

	private:
		Brain* _brain;
};
