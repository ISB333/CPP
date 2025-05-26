/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:52:22 by adesille          #+#    #+#             */
/*   Updated: 2025/04/25 09:07:56 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void	testAbstractClass()
{
	std::cout << YELLOW << "\n\n\n====================================" << RESET << std::endl;
	std::cout << YELLOW << "\n====== Testing Abstract Class ======" << RESET << std::endl;
	
	// This won't compile:
	// Animal abstractAnimal;
	
	Dog* dog = new Dog();
	Cat* cat = new Cat();
	
	dog->makeSound();
	cat->makeSound();
	
	delete dog;
	delete cat;
}

void	testPolymorphism()
{
	std::cout << YELLOW << "\n=== Testing Polymorphism ===" << RESET << std::endl;
	
	Animal* dog = new Dog();
	Animal* cat = new Cat();
	
	dog->makeSound();
	cat->makeSound();
	
	delete dog;
	delete cat;
}

void	previousTests() {
	std::cout << RED << "====== PREVIOUS Tests ======" << RED << std::endl;
	{
		std::cout << YELLOW << "\n=== Testing Animal Array Creation ===" << RESET << std::endl;
		
		const int	count = 4;
		Animal*		animals[count];

		for (int i = 0; i < count; i++)
		{
			if (i < count / 2)
			{
				std::cout << "\nCreating Dog " << i << ":" << std::endl;
				animals[i] = new Dog();
			}
			else
			{
				std::cout << "\nCreating Cat " << i << ":" << std::endl;
				animals[i] = new Cat();
			}
		}

		std::cout << "\nDeleting all animals:" << std::endl;
		for (int i = 0; i < count; i++)
		{
			std::cout << "\nDeleting animal " << i << ":" << std::endl;
			delete animals[i];
		}
	}
	{
		std::cout << YELLOW << "\n=== Testing Deep Copy ===" << RESET << std::endl;
		
		std::cout << "\nTesting Dog deep copy:" << std::endl;
		Dog*	original = new Dog();
		Dog*	copy = new Dog(*original);
		
		delete original;
		std::cout << "\nOriginal dog deleted, copy should still be valid:" << std::endl;
		copy->makeSound();
		delete copy;
	}
}

int main()
{
	std::cout << GREEN << "Starting tests..." << RESET << std::endl;
	
	previousTests();

	testAbstractClass();
	testPolymorphism();
	
	return 0;
}
