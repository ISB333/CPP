/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 07:06:35 by adesille          #+#    #+#             */
/*   Updated: 2025/03/13 12:18:35 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScalarConverter.hpp"

/* TODO : 
	- For CHAR :
		-> check if input is valid, convertible and displayable 
	- If a conversion to char is not displayable, print an informative message.	
*/


ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {*this = other;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
	if (this != &other) {
		// There are no member variables to copy
	}
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

int	typeDetector(std::string &value) {
	if (!value.compare("nan"))
		return (NAN);

	bool isdouble = false;
	int i = -1;

	while (value[++i]) {
		if (!std::isdigit(value[i]))
		{
			if (value[i] == '.') {
				isdouble = true; continue; }
			else if (value[i] == 'f' && !value[i + 1])
				return (FLOAT);
			else if (std::isalpha(value[i]) && !value[i + 1])
				return (CHAR);
			break ;
		}
		else if (!value[i + 1] && isdouble)
			return (DOUBLE);
		else if (!value[i + 1])
			return (INT);
	}
	return (ERROR);
}

std::map<int, std::string> createTypeMap() {
	std::map<int, std::string> m;
	m[ERROR] = "ERROR";
	m[INT] = "INT";
	m[FLOAT] = "FLOAT";
	m[DOUBLE] = "DOUBLE";
	m[CHAR] = "CHAR";
	m[NAN] = "NAN";
	return (m);
}

void	converter(converted &data, std::string value) {
	data.c = static_cast<char>(std::atoi(value.c_str()));
	data.n = static_cast<int>(std::atoi(value.c_str()));
	data.f = static_cast<float>(std::atof(value.c_str()));
	data.d = static_cast<double>(std::atof(value.c_str()));
}

void ScalarConverter::convert(std::string value) {
	int type = typeDetector(value);	

	(void)type;
	converted data;
	converter(data, value);
	printer(data.c);
	printer(data.n);
	printer(data.f);
	printer(data.d);

	std::cout << std::endl;
}

// void ScalarConverter::convert(std::string value) {
// 	int type = typeDetector(value);	
// 	// static const std::map<int, std::string> typeMap = createTypeMap();
// 	// std::cout << typeMap.at(type) << std::endl;

// 	(void)type;
// 	std::istringstream iss(value);
// 	char c;
// 	iss >> c;
// 	std::cout << "char: " << c << std::endl;
// 	int n;
// 	if (!(iss >> n))
// 		std::cout << "int: impossible" << std::endl;
// 	else
// 		std::cout << "int: " << n << std::endl;

// 	// float f = static_cast<float>(std::atof(value.c_str()));
// 	float f;
// 	if (!(iss >> f))
// 		std::cout << "float: impossible" << std::endl;
// 	else
// 		std::cout << "float: " << f << std::endl;

// 	double d;
// 	iss >> d;
// 	std::cout << "double: " << d << std::endl;
// 	std::cout << std::endl;
// }
