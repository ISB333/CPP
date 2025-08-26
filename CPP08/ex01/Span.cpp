/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:45:27 by adesille          #+#    #+#             */
/*   Updated: 2025/08/26 10:13:45 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0), _actualSize(0) {}

Span::Span(int maxSize) : _maxSize(maxSize), _actualSize(0) {}

Span::Span(const Span &other) { *this = other; }

Span& Span::operator=(const Span &other) {
	if (this != &other) {
		this->_maxSize = other._maxSize;
		this->_actualSize = other._actualSize;
		this->_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(int n){
	if (_actualSize >= _maxSize)
		throw std::out_of_range("Span is full");
	_numbers.push_back(n);
	_actualSize++;
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2) 
        throw std::runtime_error("Need at least 2 numbers");

    std::vector<int> temp(_numbers);
    std::sort(temp.begin(), temp.end());
    
    const int* data = &temp[0];
    int min_diff = data[1] - data[0];
    for (size_t i = 2; i < temp.size(); ++i) {
        int diff = data[i] - data[i - 1];
        if (diff < min_diff)
            min_diff = diff;
    }
    
    return (min_diff);
}

int Span::longestSpan() const {
    if (_numbers.size() < 2) 
        throw std::runtime_error("Need at least 2 numbers");

    std::vector<int> temp(_numbers);
    std::sort(temp.begin(), temp.end());
    
	return (temp[temp.size() - 1] - temp[0]);
}
