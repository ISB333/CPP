/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:52:22 by adesille          #+#    #+#             */
/*   Updated: 2025/01/28 12:56:24 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Poly.hpp"

void	testArrayCreation(void)
{
	std::cout << YELLOW << "\n=== Testing Animal Array Creation ===" << RESET << std::endl;
	
	const int	count = 4;
	Animal*		animals[count];

	// Create half dogs and half cats
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

	// Delete all animals
	std::cout << "\nDeleting all animals:" << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << "\nDeleting animal " << i << ":" << std::endl;
		delete animals[i];
	}
}

void	testDeepCopy(void)
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

int main()
{
	std::cout << GREEN << "Starting tests..." << RESET << std::endl;
	
	testArrayCreation();
	testDeepCopy();
	
	std::cout << GREEN << "\nAll tests completed." << RESET << std::endl;
	std::cout << YELLOW << "Don't forget to check with valgrind!" << RESET << std::endl;
	
	return 0;
}
