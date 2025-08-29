/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:09:55 by adesille          #+#    #+#             */
/*   Updated: 2025/08/29 09:54:26 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <ostream>

RPN::RPN() { }

RPN::RPN(const RPN &other) { *this = other; }

RPN& RPN::operator=(const RPN &other) {
	if (this != &other) {}
	return *this;
}

RPN::~RPN() { }

int	RPN::processFormula(std::string formula) {
	std::stack<int> stack;
	std::istringstream iss(formula);
	std::string token;
	
	while (iss >> token) {
		if (std::isdigit(token[0]))
			stack.push(std::atoi(token.c_str()));
		else {
			if (stack.size() < 2)
				throw std::invalid_argument("Insufficient operands for operator");
			
			int b = stack.top(); stack.pop();
			int a = stack.top(); stack.pop();
			
			switch (token[0]) {
				case '+': stack.push(a + b); break;
				case '-': stack.push(a - b); break;
				case '*': stack.push(a * b); break;
				case '/': stack.push(a / b); break;
			}
		}
	}
	if (stack.size() != 1)
		throw std::invalid_argument("Invalid RPN expression");
	return stack.top();
}