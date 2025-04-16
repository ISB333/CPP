/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:38:06 by adesille          #+#    #+#             */
/*   Updated: 2025/04/16 12:54:17 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PMergeMe.hpp"

PMergeMe::PMergeMe() { }

PMergeMe::PMergeMe(char **argv) : _vec(init(argv)), _deq(_vec.begin(), _vec.end()) { }


PMergeMe::PMergeMe(const PMergeMe &other) {	*this = other; }

PMergeMe& PMergeMe::operator=(const PMergeMe &other) {
	if (this != &other) {
		// Copy members here
	}
	return *this;
}

PMergeMe::~PMergeMe() { }

bool PMergeMe::isPositiveInteger(const std::string &s) const {
	for (size_t i = 0; i < s.length(); ++i) {
		if (!std::isdigit(s[i]))
			return false;
	}
	return !s.empty();
}

void	PMergeMe::analyzeAndProcessData(char **argv) {
	for (int i = 1; argv[i]; ++i) {
		if (!isPositiveInteger(argv[i]))
			printError("only positive integer allowed");
	}
}

vector PMergeMe::init(char **argv) {
	vector result;
	for (int i = 1; argv[i] != NULL; ++i) {
		int num = std::atoi(argv[i]);
		result.push_back(num);
	}
	return result;
}

void	PMergeMe::printData() const {
	std::cout << "Vector: ";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << _vec[i] << " ";
	std::cout << "\nDeque: ";
	for (std::deque<int>::const_iterator it = _deq.begin(); it != _deq.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}
