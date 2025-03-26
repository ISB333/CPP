/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 07:54:59 by adesille          #+#    #+#             */
/*   Updated: 2025/03/26 09:20:19 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
# include <iostream>
# include <cstring>

class Bureaucrat;

class AForm {
	private:
		const std::string	name;
		bool				isSigned;
		const int			signGrade;
		const int			execGrade;

	public:
		AForm();
		AForm(std::string name, int signGrade, int execGrade);
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		virtual ~AForm();

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		void		beSigned(const Bureaucrat& bureaucrat);
		
		// New pure virtual method to make the class abstract
		virtual void execute(Bureaucrat const & executor) const = 0;
		
		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

# include "Bureaucrat.hpp"
