/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:09:55 by adesille          #+#    #+#             */
/*   Updated: 2025/04/09 13:14:10 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "RPN.hpp"

RPN::RPN() { }

// RPN::RPN() : stack { }

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN& RPN::operator=(const RPN &other) {
	if (this != &other) {
		this->stack = other.stack;
	}
	return *this;
}

RPN::~RPN() { }
