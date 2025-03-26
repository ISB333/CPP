/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 07:06:35 by adesille          #+#    #+#             */
/*   Updated: 2025/03/26 12:01:55 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {(void)other;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {return(*this);}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string value) {
	int type = typeDetector(value);	
	
	if (type == NANF)
		print_nan();
	else if (type == INF)
		print_inf(value);
	else if (type == ERROR)
		std::cout << "Invalid Input" << std::endl;
	else {
		converted data;
		data.intOverflow = false;
		data.floatOverflow = false;
		data.doubleOverflow = false;
		converter(data, value);
		printer(data.c);
		if (data.intOverflow)
			std::cout << "int: impossible" << std::endl;
		else
			printer(data.n);
		if (data.floatOverflow)
			std::cout << "float: impossible" << std::endl;
		else
			printer(data.f);
		if (data.doubleOverflow)
			std::cout << "double: impossible" << std::endl;
		else
			printer(data.d);
		std::cout << std::endl;
	}
}
