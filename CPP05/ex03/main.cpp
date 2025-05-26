/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:35:17 by adesille          #+#    #+#             */
/*   Updated: 2025/05/26 09:23:51 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	testInternFormCreation(){
	std::cout << BLUE << "\n---- Testing Intern Form Creation ----" << std::endl;

	AForm* form1 = NULL;
	AForm* form2 = NULL;
	AForm* form3 = NULL;

	try {
		Intern intern;

		std::cout << "\nCreating shrubbery creation form:" << std::endl;
		form1 = intern.makeForm("shrubbery creation", "home");
		if (form1) {
			std::cout << *form1 << std::endl;
			
			Bureaucrat gardener("Gardener", 140);
			gardener.signForm(*form1);
			gardener.executeForm(*form1);
			
			delete form1;
		}
		
		std::cout << "\nCreating robotomy request form:" << std::endl;
		form2 = intern.makeForm("robotomy request", "Bender");
		if (form2) {
			std::cout << *form2 << std::endl;
			
			Bureaucrat engineer("Engineer", 40);
			engineer.signForm(*form2);
			engineer.executeForm(*form2);
			
			delete form2;
		}
		
		std::cout << "\nCreating presidential pardon form:" << std::endl;
		form3 = intern.makeForm("presidential pardon", "Ford Prefect");
		if (form3) {
			std::cout << *form3 << std::endl;
			
			Bureaucrat president("President", 1);
			president.signForm(*form3);
			president.executeForm(*form3);
			
			delete form3;
		}
		
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << RESET << std::endl;
}

void testInternInvalidForm() {
	std::cout << MAGENTA << "\n---- Testing Intern Invalid Form ----" << std::endl;
	
	try {
		Intern intern;
		
		std::cout << "Trying to create invalid form:" << std::endl;
		AForm* invalidForm = intern.makeForm("tax evasion", "someone");
		
		if (invalidForm) {
			std::cout << *invalidForm << std::endl;
			delete invalidForm;
		}
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << RESET << std::endl;
}

void testInternCopyAndAssignment() {
	std::cout << WHITE << "\n---- Testing Intern Copy and Assignment ----" << std::endl;
	
	try {
		Intern intern1;
		
		std::cout << "Testing copy constructor:" << std::endl;
		Intern intern2(intern1);
		
		std::cout << "Testing assignment operator:" << std::endl;
		Intern intern3;
		intern3 = intern1;
		
		std::cout << "Testing functionality of copied intern:" << std::endl;
		AForm* form = intern2.makeForm("robotomy request", "Copy Test");
		if (form) {
			std::cout << *form << std::endl;
			delete form;
		}
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << RESET << std::endl;
}

int main() {
	testInternFormCreation();
	testInternInvalidForm();
	testInternCopyAndAssignment();
	return 0;
}	
