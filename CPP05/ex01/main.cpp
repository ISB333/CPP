/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:35:17 by adesille          #+#    #+#             */
/*   Updated: 2025/05/26 09:39:04 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void testForms() {
	std::cout << BLUE << "\n---- Testing Forms ----" << std::endl;
	
	try {
		std::cout << "Creating form with invalid grades (too high):" << std::endl;
		Form invalidForm("Invalid Form", 0, 50);
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nCreating form with invalid grades (too low):" << std::endl;
		Form invalidForm("Invalid Form", 50, 151);
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nCreating valid form:" << std::endl;
		Form validForm("Tax Form", 100, 50);
		std::cout << validForm << std::endl;
		
		std::cout << "\nBureaucrat with insufficient grade trying to sign form:" << std::endl;
		Bureaucrat lowGradeBureaucrat("Junior Clerk", 120);
		std::cout << lowGradeBureaucrat << std::endl;
		lowGradeBureaucrat.signForm(validForm);
		
		std::cout << "\nForm status after failed signing attempt:" << std::endl;
		std::cout << validForm << std::endl;
		
		std::cout << "\nBureaucrat with sufficient grade signing form:" << std::endl;
		Bureaucrat highGradeBureaucrat("Senior Clerk", 80);
		std::cout << highGradeBureaucrat << std::endl;
		highGradeBureaucrat.signForm(validForm);
		
		std::cout << "\nForm status after successful signing:" << std::endl;
		std::cout << validForm << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << RESET << std::endl;
}

void testFormAssignment() {
	std::cout << CYAN << "\n---- Testing Form Copy/Assignment ----" << std::endl;
	
	try {
		Form f1("Form A", 75, 50);
		std::cout << "Original form: " << f1 << std::endl;
		
		Form f2(f1);
		std::cout << "Copied form: " << f2 << std::endl;
		
		Form f3;
		f3 = f1;
		std::cout << "Assigned form: " << f3 << std::endl;
		
		Bureaucrat boss("Boss", 1);
		boss.signForm(f1);
		
		std::cout << "After signing original form:" << std::endl;
		std::cout << "Original: " << f1 << std::endl;
		std::cout << "Copy: " << f2 << std::endl;
		std::cout << "Assignment: " << f3 << std::endl;
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
	testForms();
	testFormAssignment();
	return 0;
}
