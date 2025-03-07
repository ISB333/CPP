/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 07:27:52 by adesille          #+#    #+#             */
/*   Updated: 2025/03/07 08:57:38 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScalarConverter.hpp"

void	printer(char value) {
	if (!std::isalpha(value))
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

/*
void	printValue(void *data, int type) {
    if (type == CHAR)
        std::cout << "char: " << *(static_cast<char*>(data)) << std::endl;
    else if (type == INT)
        std::cout << "int: " << *(static_cast<int*>(data)) << std::endl;
    else if (type == FLOAT)
        std::cout << "float: " << *(static_cast<float*>(data)) << std::endl;
    else if (type == DOUBLE)
        std::cout << "double: " << *(static_cast<double*>(data)) << std::endl;
}
*/
