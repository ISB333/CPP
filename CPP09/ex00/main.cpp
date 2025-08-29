/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:13:05 by adesille          #+#    #+#             */
/*   Updated: 2025/04/11:08:07 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitcoinExchange.hpp"

void	printError(std::string str)      { std::cerr << "Error: " << str << std::endl; }
void	print(std::string str)           {       std::cout << str << std::endl;        }
void	print(int n)                     {        std::cout << n << std::endl;         }
void	print(double n)                  {        std::cout << n << std::endl;         }
void	print(std::string str, double n) { 
    std::cout << str << std::fixed << std::setprecision(2) << n << std::endl;
}

int main(int argc, char *argv[]) {
	if (argc == 2) {
		try {
			BitcoinExchange btc(argv[1]);
			
			btc.analyzeAndProcessData();
			return 0;
		}
		catch (const std::exception& error) {
			return printError(error.what()), 1;
		}
	}
	else if (argc > 2)
		return printError("only 1 file allowed."), 1;
	return printError("could not open file."), 1;
}
