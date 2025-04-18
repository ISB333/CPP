/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:38:06 by adesille          #+#    #+#             */
/*   Updated: 2025/04/18 13:27:57 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PMergeMe.hpp"

PMergeMe::PMergeMe() { }

PMergeMe::PMergeMe(char **argv) : _vec(init(argv)), _deq(_vec.begin(), _vec.end()) { fordJohnsonSort(); }


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

bool PMergeMe::isNotOverflow(const char *s) const {
	errno = 0;
	char *end;
	long val = strtol(s, &end, 10);
	return (end != s && *end == '\0' && errno != ERANGE && val <= INT_MAX);
}

void	PMergeMe::analyzeAndProcessData(char **argv) {
	for (int i = 1; argv[i]; ++i) {
		if (!isPositiveInteger(argv[i]))
			throw std::invalid_argument("only positive integer allowed");
		else if (!isNotOverflow(argv[i]))
			throw std::invalid_argument("only integer from 0-2147483647 allowed");
	}
}

vector PMergeMe::init(char **argv) {
	analyzeAndProcessData(argv);
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
void	printVec(vector _vecWinners, vector _vecLosers)  {
	std::cout << "Winners Vectors: ";
	for (size_t i = 0; i < _vecWinners.size(); ++i)
		std::cout << _vecWinners[i] << " ";
	std::cout << std::endl;
	std::cout << "Losers Vectors: ";
	for (size_t i = 0; i < _vecLosers.size(); ++i)
		std::cout << _vecLosers[i] << " ";
	std::cout << std::endl;
}


template<typename T>
void	pairUp(const std::vector <T> &data, std::vector<T> &winners, std::vector<T> &losers) {
	winners.clear();
	losers.clear();

	size_t n = data.size();
	for (size_t i = 0; i + 1 < n; i += 2) {
		if (data[i] < data[i + 1]) {
			winners.push_back(data[i]);
			losers.push_back(data[i + 1]);
		}
		else {
			winners.push_back(data[i + 1]);
			losers.push_back(data[i]);
		}
	}
	if (n % 2 == 1) {
		winners.push_back(data.back());
	}
}

void	PMergeMe::fordJohnsonSort() {
	for (int i = 0; _vec.size() != 1; i++) {
		pairUp(_vec, _vecWinners, _vecLosers[i]);
		printVec(_vecWinners, _vecLosers[i]);
		_vec = _vecWinners;
	}
	// pairUp(_vec, _vecWinners, _vecLosers);
	// printVec(_vecWinners, _vecLosers);
}


/*
	while (_vec.size() != 1)
		pairUp();
		storeLoosers();
	while (_vecSorted.size() != originalSize)
		insertLosers();

*/
