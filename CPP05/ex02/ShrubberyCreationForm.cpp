/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:26:15 by adesille          #+#    #+#             */
/*   Updated: 2025/03/26 09:20:19 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("ShrubberyCreationForm", 145, 137), target("default") {
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {
	std::cout << "ShrubberyCreationForm constructor called with target: " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
	: AForm(other), target(other.target) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	
	std::string filename = this->target + "_shrubbery";
	std::ofstream outfile(filename.c_str());
	
	if (!outfile.is_open()) {
		std::cerr << "Error: Could not create file " << filename << std::endl;
		return;
	}
	
	// ASCII tree art
	outfile << "       ###       " << std::endl;
	outfile << "      #####      " << std::endl;
	outfile << "     #######     " << std::endl;
	outfile << "    #########    " << std::endl;
	outfile << "   ###########   " << std::endl;
	outfile << "  #############  " << std::endl;
	outfile << " ############### " << std::endl;
	outfile << "#################" << std::endl;
	outfile << "       ###       " << std::endl;
	outfile << "       ###       " << std::endl;
	outfile << "       ###       " << std::endl;
	
	outfile.close();
	std::cout << "Created shrubbery in file " << filename << std::endl;
}
