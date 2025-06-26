/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 07:27:52 by adesille          #+#    #+#             */
/*   Updated: 2025/03/24 10:04:39 by adesille         ###   ########.fr       */
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
	for (size_t i = 0; i < lower.length(); ++i)
		lower[i] = std::tolower(static_cast<unsigned char>(lower[i]));
	
	return (lower == "+inf" || lower == "-inf" || 
			lower == "inf" || lower == "+inff" || 
			lower == "-inff" || lower == "inff");
}

bool intOverflowCheck(const std::string& str) {
    if (str.empty())
        return (false);
    
    try {
        if (str.length() > 11) 
        	return (false);
        if (str.length() == 10 && str[0] != '-' && str > "2147483647")
        	return (false);
        if (str.length() == 11 && str[0] == '-' && str < "-2147483648")
        	return (false);
        return (true);
    } catch (const std::invalid_argument&){
        return (false);
    } 
	catch (const std::out_of_range&) {
        return (false);
    }
}

bool doubleOverflowCheck(const std::string& str) {
    char* endPtr;
    strtod(str.c_str(), &endPtr);
    
    return (*endPtr == '\0');
}


bool floatOverflowCheck(const std::string& str) {
    try {
        double temp = std::strtod(str.c_str(), NULL);
        
        if (temp > FLT_MAX || temp < -FLT_MAX)
            return (false);
        
        return (true);
    } catch (...) {
        return (false);
    }
}
