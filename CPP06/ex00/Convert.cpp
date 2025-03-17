/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:23:59 by adesille          #+#    #+#             */
/*   Updated: 2025/03/17 11:58:59 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScalarConverter.hpp"

/*
	TODO: Overflow
*/

int	typeDetector(const std::string &value) {
	if (!value.compare("nan") || !value.compare("nanf"))
		return (NANF);
	if (isInfinity(value))
		return (INF);

	bool decimal = false;
	bool digit = false;
	bool sign = false;
	int i = -1;
	while (value[++i]) {
		if (!std::isdigit(value[i]))
		{
			if (value[i] == '.' && std::isdigit(value[i + 1]) && decimal)
				return (ERROR);
			else if (value[i] == '.' && std::isdigit(value[i + 1])) {
				decimal = true; continue; }
			else if (std::isalpha(value[i]) && !digit && !value[i + 1])
				return (CHAR);
			else if (value[i] == 'f' && decimal && !value[i + 1])
				return (FLOAT);
			else if (value[i] == 'f' && !decimal)
				return (ERROR);
			else if ((value[i] == '+' || value [i] == '-') && sign == true)
				return (ERROR);
			else if ((value[i] == '+' || value [i] == '-') && sign == false) {
				sign = true; continue; }
			break ;
		}
		if (std::isdigit(value[i]))
			digit = true;
		if (!value[i + 1] && decimal)
			return (DOUBLE);
		else if (!value[i + 1])
			return (INT);
	}
	return (ERROR);
}

void	convert_single_value(converted &data, std::string value) {
	data.c = static_cast<char>(value[0]);
	data.n = static_cast<int>(value[0]);
	data.f = static_cast<float>(static_cast<int>(value[0]));
	data.d = static_cast<float>(static_cast<int>(value[0]));
}

void	converter(converted &data, std::string value) {
	bool digits_only = true;
	for (int i = 0; value[i]; i++)
		if (!std::isdigit(value[i]))
			digits_only = false;

	if (value.length() == 1 && std::isalpha(value[0]))
		convert_single_value(data, value);
	else {
		if (std::atoi(value.c_str()) < 128)
			data.c = static_cast<char>(std::strtod(value.c_str(), NULL));
		else 
			data.c = '\0';
		if (intOverflowCheck(value))
			data.n = static_cast<int>(std::atoi(value.c_str()));
		else
			data.intOverflow = true;
		if (floatOverflowCheck(value))
			data.f = static_cast<float>(std::atof(value.c_str()));
		else
			data.floatOverflow = true;
		if (doubleOverflowCheck(value))
			data.d = static_cast<double>(std::atof(value.c_str()));
		else
			data.doubleOverflow = true;
	}
}
