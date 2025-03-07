/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 07:06:54 by adesille          #+#    #+#             */
/*   Updated: 2025/03/06 09:50:26 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once

# include <iostream>
# include <cstring>
# include <cstdlib>
# include <map>
# include <iomanip>
# include <sstream>

# define ERROR -1
# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3
# define NAN 4

# define STRINGSIZE(x) #x

class ScalarConverter {
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter& operator=(const ScalarConverter &other);
		~ScalarConverter();

		static void convert(std::string value);
};

struct	converted {
	char	c;
	int		n;
	float	f;
	double	d;
	converted() : c(0), n(0), f(0.0f), d(0.0) {}
};

void	printer(char value);
void	printer(int value);
void	printer(float value);
void	printer(double value);
void	printer(std::string errorMsg);
