/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 07:06:54 by adesille          #+#    #+#             */
/*   Updated: 2025/03/26 11:11:21 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once

# include <iostream>
# include <cstring>
# include <cstdlib>
# include <map>
# include <iomanip>
# include <sstream>
# include <cmath>
# include <string>
# include <algorithm>
# include <cctype>
# include <limits>
# include <cfloat>

# define ERROR -1
# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3
# define INF 4
# define NANF 5

# define STRINGSIZE(x) #x

class ScalarConverter {
	private :
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter& operator=(const ScalarConverter &other);
		~ScalarConverter();

	public :
		static void convert(const std::string value);
};

struct	converted {
	char	c;
	int		n;
	float	f;
	double	d;
	bool	intOverflow;
	bool	floatOverflow;
	bool	doubleOverflow;
	converted() : c(0), n(0), f(0.0f), d(0.0) {}
};

void	printer(char value);
void	printer(int value);
void	printer(float value);
void	printer(double value);
void	printer(std::string errorMsg);
void	print_nan(void);
void	print_inf(const std::string& value);
bool	isInfinity(const std::string& value);
bool	intOverflowCheck(const std::string& str);
bool	doubleOverflowCheck(const std::string& str);
bool	floatOverflowCheck(const std::string& str);

void	converter(converted &data, std::string value);
void	convert_single_value(converted &data, std::string value);
int		typeDetector(const std::string &value);
