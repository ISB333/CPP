/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:13:05 by adesille          #+#    #+#             */
/*   Updated: 2025/08/26 14:09:01 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	printError(std::string str)      { std::cerr << "Error: " << str << std::endl; }
void	print(std::string str)           {       std::cout << str << std::endl;        }
void	print(int n)                     {        std::cout << n << std::endl;         }
void	print(char c)                    {        std::cout << c << std::endl;         }
bool	isSpace(char c)                  {              return c == ' ';               }

void	checkArgsValidity(std::string str) {
    if (str.find_first_not_of("0123456789 +-/*") != std::string::npos)
        throw std::invalid_argument("Wrong characters in the args, only digits 0-9 and +-*/ allowed");
    
    std::string formula;
    std::remove_copy_if(str.begin(), str.end(), std::back_inserter(formula), isSpace);

    const std::string OPERATORS = "+-/*";
    int digitsCount = 0, operatorsCount = 0;

    for (size_t i = 0; i < formula.length(); i++) {
        if (std::isdigit(formula[i]))
            digitsCount++;
        else if (OPERATORS.find(formula[i]) != std::string::npos)
            operatorsCount++;
    }
    
	// print(digitsCount), print(operatorsCount);
    if (digitsCount != operatorsCount + 1) 
        throw std::invalid_argument("Invalid RPN expression: incorrect operator/operand ratio");
    if (str.find(" 0 /") != std::string::npos)
        throw std::invalid_argument("Division by zero not allowed");
}

int main (int argc, char *argv[]) {
	if (argc == 2) {
		try {
			checkArgsValidity(argv[1]);
			RPN rpn;
			rpn.parseFormula(argv[1]);
			print(rpn.processFormula());
			return 0;
		} catch (const std::exception& error) {
			return printError(error.what()), 1;
		}
	}
	return printError("wrong number of arguments"), 1;
}
