/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:13:05 by adesille          #+#    #+#             */
/*   Updated: 2025/04/09 13:34:31 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "RPN.hpp"

void	error(std::string msg){
	std::cerr << msg << std::endl;
}

bool	checkArgsValidity(std::string str){
	if (str.find_first_not_of("0123456789 +-/*") != std::string::npos)
		return (false);
	
	return (true);
}

int main (int argc, char *argv[]) {
	if (argc == 2) {
		if (checkArgsValidity(argv[1])) {
			// RPN rpn(argv[1]);
			return (0);
		}
		return (error("Wrong character in the argument"), 1);
	}
	return (error("wrong number of arguments"), 1);
}
