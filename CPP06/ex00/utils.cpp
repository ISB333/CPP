/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 07:27:52 by adesille          #+#    #+#             */
/*   Updated: 2025/03/14 12:24:18 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScalarConverter.hpp"

bool	isDisplayable(char c) {
	return (std::isprint(static_cast<unsigned char>(c)));
}

void	printer(char value) {
	if (!isDisplayable(value))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << value << std::endl;
}

void	printer(int value) {
	std::cout << "int: " << value << std::endl;
}

void	printer(float value) {
	std::cout << std::fixed << std::setprecision(1) << "float: " << value << "f" << std::endl;
}

void	printer(double value) {
	std::cout << std::fixed << std::setprecision(1) << "double: " << value << std::endl;
}

void	printer(std::string errorMsg) {
	std::cout << errorMsg << std::endl;
}

void	print_nan(void) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
	std::cout << std::endl;
}

void	print_inf(const std::string& value) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << static_cast<float>(std::atof(value.c_str())) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(std::atof(value.c_str())) <<  std::endl;
	std::cout << std::endl;
}

bool isInfinity(const std::string& value) {
	std::string lower = value;
	std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
	
	return (lower == "+inf" || lower == "-inf" || 
			lower == "inf" || lower == "+inff" || 
			lower == "-inff" || lower == "inff");
}
