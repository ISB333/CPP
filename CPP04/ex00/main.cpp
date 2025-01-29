/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:52:22 by adesille          #+#    #+#             */
/*   Updated: 2025/01/28 10:34:38 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Poly.hpp"

int main()
{
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

	return 0;
}
