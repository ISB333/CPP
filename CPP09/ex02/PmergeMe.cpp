/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:38:06 by adesille          #+#    #+#             */
/*   Updated: 2025/08/27 15:51:27 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstddef>
#include <pthread.h>
#include <vector>

PMergeMe::PMergeMe() {}

PMergeMe::PMergeMe(char **argv) : _vec(init(argv)), _deq(_vec.begin(), _vec.end()) { fordJohnsonSort(); }


PMergeMe::PMergeMe(const PMergeMe &other) {	*this = other; }

PMergeMe& PMergeMe::operator=(const PMergeMe &other) {
	if (this != &other) {}
	return *this;
}

PMergeMe::~PMergeMe() {}

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

template<typename Container>
void	pairUp(const Container& data, Container& winners, Container& losers) {
	winners.clear();
	losers.clear();

	size_t n = data.size();
	for (size_t i = 0; i + 1 < n; i += 2) {
		if (data[i] < data[i + 1]) {
			winners.push_back(data[i]);
			losers.push_back(data[i + 1]);
		} else {
			winners.push_back(data[i + 1]);
			losers.push_back(data[i]);
		}
	}
	if (n & 1)
		winners.push_back(data.back());
}


/*
	[0, 1]
	step 1: 1 + 2*0 = 1

	[0, 1, 1]
	step 2: 1 + 2*1 = 3

	[0, 1, 1, 3]
	step 2: 3 + 2*1 = 5
*/
std::vector<size_t> generateJacosthalSequence(size_t length) {
	std::vector<size_t> jacobsthal;
	jacobsthal.push_back(0);
	if (length == 0)
		return jacobsthal;
	jacobsthal.push_back(1);
	size_t n = 2;
	while (true) {
		size_t next = jacobsthal[n - 1] + 2 * jacobsthal[n - 2];
		if (next > length)
			break;
		jacobsthal.push_back(next);
		++n;
	}
	return jacobsthal;
}

std::vector<size_t> getInsertionOrder(size_t n, const std::vector<size_t>& jac) {
	std::vector<size_t> order;
	std::vector<bool> used(n, false);
	size_t i = 1;
	while (i < jac.size() && jac[i] < n) {
		size_t start = jac[i - 1];
		size_t end = jac[i];
		for (size_t j = end; j > start; --j) {
			size_t k = j - 1;
			if (k < n && !used[k]) {
				order.push_back(k);
				used[k] = true;
			}
		}
		i++;
	}
	for (size_t j = 0; j < n; ++j)
		if (!used[j])
			order.push_back(j);
	return order;
};

template <typename Container, typename DoubleContainer>
Container algorithm(Container& data, Container& winners, DoubleContainer& losers) {
	if(data.size() == 1)
		return data;
	while (data.size() > 1) {
		Container currentLosers;
		pairUp(data, winners, currentLosers);
		losers.push_back(currentLosers);
		data = winners;
	}
	while (!losers.empty()) {
		Container current_losers = losers.back();
		size_t n = current_losers.size();
		std::vector<size_t> jacobsthal = generateJacosthalSequence(n);
		std::vector<size_t> order = getInsertionOrder(n, jacobsthal);
		for (size_t i = 0; i < order.size(); ++i) {
			size_t idx = order[i];
			typename Container::iterator it = std::upper_bound(winners.begin(), winners.end(), current_losers[idx]);
			winners.insert(it, current_losers[idx]);
		}
		losers.pop_back();
	}
	return winners;
}

void PMergeMe::fordJohnsonSort() {
	printData("Before");

	struct timeval t0, t1, t2;
	::gettimeofday(&t0, NULL);
	_vec = algorithm(_vec, _vecWinners, _vecLosers);
	::gettimeofday(&t1, NULL);
	_deq = algorithm(_deq, _deqWinners, _deqLosers);
	::gettimeofday(&t2, NULL);

	printData("After");

	long long vec_usec = (t1.tv_sec - t0.tv_sec) * 1000000LL + (t1.tv_usec - t0.tv_usec);
	long long deq_usec = (t2.tv_sec - t1.tv_sec) * 1000000LL + (t2.tv_usec - t1.tv_usec);

	std::cout << "Vector time: " << vec_usec << " us\n"
		<< "Deque time:  " << deq_usec << " us\n" << std::endl;
}
