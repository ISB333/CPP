/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 06:48:19 by adesille          #+#    #+#             */
/*   Updated: 2025/03/26 09:20:19 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
 
Bureaucrat::Bureaucrat() : name("Anonymous"), grade(150) {
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
	std::cout << "Constructor Called for " << name << ", grade: " << grade << std::endl;
	if (grade < 1)
		throw (GradeTooHighException());
	if (grade > 150)
		throw (GradeTooLowException());
	this->grade = grade;
}
 
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {
	std::cout << "Copy Constructor Called for " << name << ", grade: " << grade << std::endl;
}
 
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		grade = other.grade;
	}
	return (*this);
}
 
Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor Called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}

std::string Bureaucrat::getName() const {
	return (name);
}

int	Bureaucrat::getGrade() const {
	return (grade);
}

void Bureaucrat::incrementGrade() {
	if (grade <= 1)
		throw (Bureaucrat::GradeTooHighException());
	grade--;
	std::cout << "Grade incremented to " << grade << std::endl;
}

void Bureaucrat::decrementGrade() {
	if (grade >= 150)
		throw (Bureaucrat::GradeTooLowException());
	grade++;
	std::cout << "Grade decremented to " << grade << std::endl;
}

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << name << " couldn't sign " << form.getName() 
			<< " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << name << " couldn't execute " << form.getName() 
			<< " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high (max grade is 1)");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low (min grade is 150)");
}
