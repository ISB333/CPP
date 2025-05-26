/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:52:22 by adesille          #+#    #+#             */
/*   Updated: 2025/04/25 09:07:48 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	testArrayCreation(void)
{
	std::cout << YELLOW << "\n\n\n===========================================" << RESET << std::endl;
	std::cout << YELLOW << "\n\n\n====== Testing Animal Array Creation ======" << RESET << std::endl;
	
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

void	previousTests() {
	std::cout << RED << "====== PREVIOUS Tests ======" << RED << std::endl;
	{
		std::cout << "=== Basic Tests ===" << std::endl;
		std::auto_ptr<Animal> meta(new Animal());
		std::auto_ptr<Animal> j(new Dog());
		std::auto_ptr<Animal> i(new Cat());
		
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();
	}
	{
		std::cout << GREEN << "\n=== Copy Constructor Tests ===" << std::endl;
		Dog originalDog;
		Dog copyDog(originalDog);
		Cat originalCat;
		Cat copyCat(originalCat);
		std::cout << RESET << std::endl;

		std::cout << BLUE << "\n=== Assignment Operator Tests ===" << std::endl;
		Dog assignDog;
		assignDog = originalDog;
		Cat assignCat;
		assignCat = originalCat;
		std::cout << RESET << std::endl;
	}
	{
		std::cout << HYEL << "\n=== Array of Animals Tests ===" << std::endl;
		Animal* animals[4];
		animals[0] = new Dog();
		animals[1] = new Cat();
		animals[2] = new Dog();
		animals[3] = new Cat();
		std::cout << RESET << std::endl;

		for (int k = 0; k < 4; k++) {
			std::cout << animals[k]->getType() << ": ";
			animals[k]->makeSound();
		}

		for (int k = 0; k < 4; k++) {
			delete animals[k];
		}
	}
	{
		std::cout << RED << "\n=== WrongAnimal Tests ===" << RESET << std::endl;
		WrongAnimal* wrongMeta = new WrongAnimal();
		WrongAnimal* wrongCat = new WrongCat();
		
		std::cout << wrongCat->getType() << " " << std::endl;
		wrongMeta->makeSound();
		
		wrongCat->makeSound();
		
		delete wrongMeta;
		delete wrongCat;
	}
}

int main()
{
	std::cout << GREEN << "Starting tests..." << RESET << std::endl;
	
	previousTests();

	testArrayCreation();
	testDeepCopy();
	
	std::cout << GREEN << "\nAll tests completed." << RESET << std::endl;
	
	return 0;
}
