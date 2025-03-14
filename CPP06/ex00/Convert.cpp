/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:23:59 by adesille          #+#    #+#             */
/*   Updated: 2025/03/14 12:31:39 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScalarConverter.hpp"

int	typeDetector(const std::string &value) {
	if (!value.compare("nan") || !value.compare("nanf"))
		return (NANF);
	if (isInfinity(value))
		return (INF);

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

	if (value.length() == 1)
		convert_single_value(data, value);
	else {
		data.n = static_cast<int>(std::atoi(value.c_str()));
		data.f = static_cast<float>(std::atof(value.c_str()));
		data.d = static_cast<double>(std::atof(value.c_str()));
	}
	if (digits_only)	
		data.c = static_cast<char>(std::atoi(value.c_str()));
}
