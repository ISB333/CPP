/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:00:00 by adesille          #+#    #+#             */
/*   Updated: 2025/05/26 09:25:39 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &other) {
	std::cout << "Intern copy constructor called" << std::endl;
	(void)other;
}

Intern& Intern::operator=(const Intern &other) {
	std::cout << "Intern assignment operator called" << std::endl;
	if (this != &other) { }
	return (*this);
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::createShrubberyCreationForm(std::string target) {
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomyRequestForm(std::string target) {
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidentialPardonForm(std::string target) {
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string formName, std::string target) {
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request", 
		"presidential pardon"
	};
	
	AForm* (Intern::*formCreators[3])(std::string) = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};
	
	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return ((this->*formCreators[i])(target));
		}
	}
	
	std::cerr << "Error: Form name '" << formName << "' does not exist" << std::endl;
	throw (Intern::FormNotFoundException());
}

const char* Intern::FormNotFoundException::what() const throw() {
	return ("Form not found");
}
