/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:39:13 by adesille          #+#    #+#             */
/*   Updated: 2025/08/27 10:09:21 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	printError(std::string str)      { std::cerr << "Error: " << str << std::endl; }
void	print(std::string str)           {       std::cout << str << std::endl;        }
void	print(int n)                     {        std::cout << n << std::endl;         }
void	print(double n)                  {        std::cout << n << std::endl;         }

int	main(int argc, char *argv[]) {
	if (argc > 1) {
		try {
			PMergeMe pmerge(argv);
			return 0;
		} catch (const std::exception &error) {
			return printError(error.what()), 1;
		}
	}
	return printError("the program needs arguments"), 1;
}
