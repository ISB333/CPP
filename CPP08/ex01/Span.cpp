/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:45:27 by adesille          #+#    #+#             */
/*   Updated: 2025/03/28 12:25:56 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"

Span::Span() : _maxSize(0), _actualSize(0) {}

Span::Span(int maxSize) : _maxSize(maxSize), _actualSize(0) {}

Span::Span(const Span &other) {
	*this = other;
}

Span& Span::operator=(const Span &other) {
	if (this != &other) {
		this->_maxSize = other._maxSize;
		this->_actualSize = other._actualSize;
		this->_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int n){
	if (_actualSize >= _maxSize)
		throw std::out_of_range("Span is full");
	_numbers.push_back(n);
	_actualSize++;
	std::cout << "number: " << n << " added" << std::endl;
}

// void	Span::shortestSpan() {
// 	return _numbers.
// }

// void	longestSpan() {

// }
