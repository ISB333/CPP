/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:06:10 by adesille          #+#    #+#             */
/*   Updated: 2025/03/26 09:20:19 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "AForm.hpp"

AForm::AForm() : name("Default Form"), isSigned(false), signGrade(150), execGrade(150) {
	std::cout << "Default Form constructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade) 
	: name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {
	std::cout << "Form constructor called for " << name << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw (AForm::GradeTooHighException());
	if (signGrade > 150 || execGrade > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(const AForm &other) 
	: name(other.name), isSigned(other.isSigned), 
	signGrade(other.signGrade), execGrade(other.execGrade) {
	std::cout << "Form copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm &other) {
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
	return (*this);
}

AForm::~AForm() {
	std::cout << "Form destructor called" << std::endl;
}

std::string AForm::getName() const {
	return (this->name);
}

bool AForm::getIsSigned() const {
	return ((this->isSigned));
}

int AForm::getSignGrade() const {
	return (this->signGrade);
}

int AForm::getExecGrade() const {
	return (this->execGrade);
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->signGrade)
		this->isSigned = true;
	else
		throw (AForm::GradeTooLowException());
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Form grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Form grade is too low");
}

const char* AForm::FormNotSignedException::what() const throw() {
	return ("Form is not signed");
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "Form: " << form.getName() 
	   << ", sign grade: " << form.getSignGrade() 
	   << ", exec grade: " << form.getExecGrade() 
	   << ", signed status: " << (form.getIsSigned() ? "signed" : "not signed");
	return (os);
}
