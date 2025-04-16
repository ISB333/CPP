/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:09:55 by adesille          #+#    #+#             */
/*   Updated: 2025/04/16 12:22:21 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "RPN.hpp"

RPN::RPN() { }

RPN::RPN(const RPN &other) { *this = other; }

RPN& RPN::operator=(const RPN &other) {
	if (this != &other) {
		this->_nbrs = other._nbrs;
		this->_operators = other._operators;
	}
	return *this;
}

RPN::~RPN() { }

void RPN::parseFormula(std::string formula) {
	std::istringstream iss(formula);
	std::string token;
	while (iss >> token) {
		if (std::isdigit(token[0])) {
			_nbrs.push_front(std::atoi(token.c_str()));
		}
		else {
			_operators.push_front(token[0]);
		}
	}
}

int	RPN::processFormula() {
	int result = 0;

	result += _nbrs.back();
	_nbrs.pop_back();
	while (!_nbrs.empty())
	{
		switch (_operators.back()) {
			case '*':
				result *= _nbrs.back();
				break ;
			case '/':
				result /= _nbrs.back();
				break ;
			case '+':
				result += _nbrs.back();
				break ;
			case '-':
				result -= _nbrs.back();
				break ;
		}
		_nbrs.pop_back();
		_operators.pop_back();
	}
	return (result);
}
