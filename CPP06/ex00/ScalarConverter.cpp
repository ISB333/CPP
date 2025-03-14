/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 07:06:35 by adesille          #+#    #+#             */
/*   Updated: 2025/03/14 12:23:32 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScalarConverter.hpp"

/* TODO : 
	- For CHAR :
		-> check if input is valid, convertible and displayable 
	- If a conversion to char is not displayable, print an informative message.	
*/


ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string value) {
	int type = typeDetector(value);	
	
	if (type == NANF)
		print_nan();
	else if (type == INF)
		print_inf(value);
	else {
		converted data;
		converter(data, value);
		printer(data.c);
		printer(data.n);
		printer(data.f);
		printer(data.d);
		std::cout << std::endl;
	}
}
