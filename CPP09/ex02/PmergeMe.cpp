/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:38:06 by adesille          #+#    #+#             */
/*   Updated: 2025/04/21 09:53:59 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PmergeMe.hpp"

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

// void	printVec(vector _vecWinners, vector _vecLosers)  {
// 	std::cout << "Winners Vectors: ";
// 	for (size_t i = 0; i < _vecWinners.size(); ++i)
// 		std::cout << _vecWinners[i] << " ";
// 	std::cout << std::endl;
// 	std::cout << "Losers Vectors: ";
// 	for (size_t i = 0; i < _vecLosers.size(); ++i)
// 		std::cout << _vecLosers[i] << " ";
// 	std::cout << std::endl;
// }
// template<typename Seq>
// void	printDoubleVec(Seq& Losers)  {
// 	std::cout << "\nAll Losers" << std::endl;
// 	for (unsigned long i = 0; i < Losers.size(); ++i) {
// 		for (unsigned long j = 0; j < Losers[i].size(); ++j) {
// 			std::cout << Losers[i][j] << " ";
// 		}
// 		std::cout << std::endl;
// 	}
// }

void	PMergeMe::printData(std::string s) const {
	std::ostringstream oss;
	s += ": ";
	for (size_t i = 0; i < _vec.size() && i < 6; ++i) {
	 	oss << _vec[i];
		s += oss.str() + " ";
		oss.str("");
		if (i == 5 && i < _vec.size() - 1)
			s += "[...]";
	}
	std::cout << s << std::endl;
}


template<typename Seq>
void	pairUp(const Seq& data, Seq& winners, Seq& losers) {
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
	if (n & 1) {
		winners.push_back(data.back());
	}
}
void	PMergeMe::fordJohnsonSortVec() {
	while (_vec.size() > 1) {
		vector currentLosers;
		pairUp(_vec, _vecWinners, currentLosers);
		_vecLosers.push_back(currentLosers);
		_vec = _vecWinners;
	}
	while (_vecLosers.size() > 0) {
		int i = _vecLosers.size() - 1;
		while (_vecLosers[i].size()) {
			std::vector<int>::iterator it = std::upper_bound(_vec.begin(), _vec.end(), _vecLosers[i][0]);
			_vec.insert(it, _vecLosers[i][0]);
			_vecLosers[i].erase(_vecLosers[i].begin());
		}
		_vecLosers.pop_back();
	}
}

void	PMergeMe::fordJohnsonSortDeq() {
	while (_deq.size() > 1) {
		deque currentLosers;
		pairUp(_deq, _deqWinners, currentLosers);
		_deqLosers.push_back(currentLosers);
		_deq = _deqWinners;
	}
	while (_deqLosers.size() > 0) {
		int i = _deqLosers.size() - 1;
		while (_deqLosers[i].size()) {
			std::deque<int>::iterator it = std::upper_bound(_deq.begin(), _deq.end(), _deqLosers[i][0]);
			_deq.insert(it, _deqLosers[i][0]);
			_deqLosers[i].erase(_deqLosers[i].begin());
		}
		_deqLosers.pop_back();
	}
}

void PMergeMe::fordJohnsonSort() {
    printData("Before");

    struct timeval t0, t1, t2;
    ::gettimeofday(&t0, NULL);
    fordJohnsonSortVec();
    ::gettimeofday(&t1, NULL);
    fordJohnsonSortDeq();
    ::gettimeofday(&t2, NULL);

    printData("After");

    double vec_sec = double(t1.tv_sec  - t0.tv_sec )
                   + double(t1.tv_usec - t0.tv_usec) / 1e6;
    double deq_sec = double(t2.tv_sec  - t1.tv_sec )
                   + double(t2.tv_usec - t1.tv_usec) / 1e6;

    std::cout << "Vector time: " << std::fixed << std::setprecision(5) << vec_sec << " s\n"
        << "Deque time:  " << std::fixed << std::setprecision(5) << deq_sec << " s\n";
}
