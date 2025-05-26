/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:35:17 by adesille          #+#    #+#             */
/*   Updated: 2025/05/26 08:51:04 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testShrubberyCreationForm() {
	std::cout << BLUE << "\n---- Testing ShrubberyCreationForm ----" << std::endl;
	
	try {
		ShrubberyCreationForm form("garden");
		std::cout << form << std::endl;
		
		Bureaucrat bob("Bob", 140);
		Bureaucrat jim("Jim", 130);
		
		bob.signForm(form);
		bob.executeForm(form);
		
		jim.executeForm(form);
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << RESET << std::endl;
}

void testRobotomyRequestForm() {
	std::cout << GREEN << "\n---- Testing RobotomyRequestForm ----" << std::endl;
	
	try {
		RobotomyRequestForm form("Marvin");
		std::cout << form << std::endl;
		
		Bureaucrat alice("Alice", 70);
		Bureaucrat dave("Dave", 40);
		
		alice.signForm(form);
		alice.executeForm(form);
		
		dave.executeForm(form);
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << RESET << std::endl;
}

void testPresidentialPardonForm() {
	std::cout << YELLOW << "\n---- Testing PresidentialPardonForm ----" << std::endl;
	
	try {
		PresidentialPardonForm form("Arthur Dent");
		std::cout << form << std::endl;
		
		Bureaucrat charlie("Charlie", 20);
		Bureaucrat president("President", 1);
		
		charlie.signForm(form);
		charlie.executeForm(form);
		
		president.executeForm(form);
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << RESET << std::endl;
}

void testUnsignedFormExecution() {
	std::cout << RED << "\n---- Testing Unsigned Form Execution ----" << std::endl;
	
	try {
		ShrubberyCreationForm form("test");
		std::cout << form << std::endl;
		
		Bureaucrat john("John", 1);
		john.executeForm(form);
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << RESET << std::endl;
}

int main() {
	testShrubberyCreationForm();
	testRobotomyRequestForm();
	testPresidentialPardonForm();
	testUnsignedFormExecution();
	return 0;
}
