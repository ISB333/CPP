/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:35:17 by adesille          #+#    #+#             */
/*   Updated: 2025/05/26 08:39:34 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"

void testConstructor() {
	std::cout << YELLOW << "\n---- Testing Constructor Exceptions ----" << std::endl;

	try {
		std::cout << "Creating bureaucrat with grade 151:" << std::endl;
		Bureaucrat a("Gerard", 151);
		std::cout << a << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nCreating bureaucrat with grade 0:" << std::endl;
		Bureaucrat b("Sophie", 0);
		std::cout << b << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nCreating bureaucrat with valid grade 75:" << std::endl;
		Bureaucrat c("Michel", 75);
		std::cout << c << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << RESET << std::endl;
}

void testIncrement() {
	std::cout << GREEN << "\n---- Testing Increment ----" << std::endl;

	try {
		std::cout << "Creating bureaucrat with grade 2:" << std::endl;
		Bureaucrat a("Pierre", 2);
		std::cout << a << std::endl;
		
		std::cout << "Incrementing grade:" << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		
		std::cout << "Incrementing grade again (should throw):" << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << RESET << std::endl;
}

void testDecrement() {
	std::cout << RED << "\n---- Testing Decrement ----" << std::endl;

	try {
		std::cout << "Creating bureaucrat with grade 149:" << std::endl;
		Bureaucrat a("Marie", 149);
		std::cout << a << std::endl;
		
		std::cout << "Decrementing grade:" << std::endl;
		a.decrementGrade();
		std::cout << a << std::endl;
		
		std::cout << "Decrementing grade again (should throw):" << std::endl;
		a.decrementGrade();
		std::cout << a << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << RESET << std::endl;
}

void testCopyConstructorAndAssignment() {
	std::cout << WHITE << "\n---- Testing Copy Constructor and Assignment ----" << std::endl;

	try {
		Bureaucrat a("Dupont", 10);
		std::cout << "Original: " << a << std::endl;
		
		Bureaucrat b(a);
		std::cout << "Copy constructed: " << b << std::endl;
		
		Bureaucrat c;
		std::cout << "Before assignment: " << c << std::endl;
		c = a;
		std::cout << "After assignment: " << c << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << RESET << std::endl;
}

int main() {
	testConstructor();
	testIncrement();
	testDecrement();
	testCopyConstructorAndAssignment();
	return 0;
}
