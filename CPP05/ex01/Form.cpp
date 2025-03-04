/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:06:10 by adesille          #+#    #+#             */
/*   Updated: 2025/03/04 08:33:22 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Form.hpp"

Form::Form() : name("Default Form"), isSigned(false), signGrade(150), execGrade(150) {
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade) 
	: name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {
	std::cout << "Form constructor called for " << name << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw (Form::GradeTooHighException());
	if (signGrade > 150 || execGrade > 150)
		throw (Form::GradeTooLowException());
}

Form::Form(const Form &other) 
	: name(other.name), isSigned(other.isSigned), 
	signGrade(other.signGrade), execGrade(other.execGrade) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form &other) {
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
	return (*this);
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const {
	return (this->name);
}

bool Form::getIsSigned() const {
	return ((this->isSigned));
}

int Form::getSignGrade() const {
	return (this->signGrade);
}

int Form::getExecGrade() const {
	return (this->execGrade);
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->signGrade)
		this->isSigned = true;
	else
		throw (Form::GradeTooLowException());
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Form grade is too high");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Form grade is too low");
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form: " << form.getName() 
	   << ", sign grade: " << form.getSignGrade() 
	   << ", exec grade: " << form.getExecGrade() 
	   << ", signed status: " << (form.getIsSigned() ? "signed" : "not signed");
	return (os);
}
