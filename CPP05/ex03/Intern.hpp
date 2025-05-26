/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:00:00 by adesille          #+#    #+#             */
/*   Updated: 2025/05/26 09:14:07 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern &other);
		Intern& operator=(const Intern &other);
		~Intern();

		AForm* makeForm(std::string formName, std::string target);

	private:
		AForm* createShrubberyCreationForm(std::string target);
		AForm* createRobotomyRequestForm(std::string target);
		AForm* createPresidentialPardonForm(std::string target);
		
		class FormNotFoundException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};
