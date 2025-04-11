/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:09:55 by adesille          #+#    #+#             */
/*   Updated: 2025/04/11 14:06:14 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "RPN.hpp"

RPN::RPN() { }

RPN::RPN(const RPN &other) { *this = other; }

RPN& RPN::operator=(const RPN &other) {
	if (this != &other) {
		this->nbrs = other.nbrs;
		this->operators = other.operators;
	}
	return *this;
}

RPN::~RPN() { }

void RPN::parseFormula(std::string formula) {
	std::istringstream iss(formula);
	std::string token;
	while (iss >> token) {
		if (std::isdigit(token[0])) {
			nbrs.push_front(std::atoi(token.c_str()));
		}
		else {
			operators.push_front(token[0]);
		}
	}
}

int	RPN::processFormula() {
	int result = 0;

	result += nbrs.back();
	nbrs.pop_back();
	while (!nbrs.empty())
	{
		switch (operators.back()) {
			case '*':
				result *= nbrs.back();
				break ;
			case '/':
				result /= nbrs.back();
				break ;
			case '+':
				result += nbrs.back();
				break ;
			case '-':
				result -= nbrs.back();
				break ;
		}
		nbrs.pop_back();
		operators.pop_back();
	}
	return (result);
}
