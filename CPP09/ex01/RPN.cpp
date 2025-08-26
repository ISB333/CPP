/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:09:55 by adesille          #+#    #+#             */
/*   Updated: 2025/08/26 14:21:11 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <ostream>

RPN::RPN() { }

RPN::RPN(const RPN &other) { *this = other; }

RPN& RPN::operator=(const RPN &other) {
	if (this != &other) {
		this->_formula = other._formula;
		this->_nbrs = other._nbrs;
		this->_operators = other._operators;
	}
	return *this;
}

RPN::~RPN() { }

void RPN::parseFormula(std::string formula) {
	_formula = formula;
	std::istringstream iss(formula);
	std::string token;
	while (iss >> token) {
		if (std::isdigit(token[0]))
			_nbrs.push_front(std::atoi(token.c_str()));
		else
			_operators.push_front(token[0]);
	}
}

int	RPN::processFormula() {
    std::stack<int> stack;
    std::istringstream iss(_formula);
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
                case '/': 
                    if (b == 0) throw std::invalid_argument("Division by zero");
                    stack.push(a / b); 
                    break;
            }
        }
    }
    if (stack.size() != 1)
        throw std::invalid_argument("Invalid RPN expression");
    return stack.top();
}