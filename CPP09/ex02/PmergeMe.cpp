/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:38:06 by adesille          #+#    #+#             */
/*   Updated: 2025/08/29 10:11:39 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PMergeMe::PMergeMe() {}

PMergeMe::PMergeMe(char **argv) : _vec(init(argv)), _deq(_vec.begin(), _vec.end()) { fordJohnsonSort(); }


PMergeMe::PMergeMe(const PMergeMe &other) {	*this = other; }

PMergeMe& PMergeMe::operator=(const PMergeMe &other) {
	if (this != &other) {}
	return *this;
}

PMergeMe::~PMergeMe() {}

bool PMergeMe::isPositiveInteger(const std::string &s) const {
	for (size_t i = 0; i < s.length(); ++i)
		if (!std::isdigit(s[i]))
			return false;

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

template <typename Container>
void	checkSorting(Container& data, std::string type) {
	bool sorted = true;
	for (size_t i = 1; i < data.size(); ++i) {
		if (data[i - 1] > data[i]) {
			sorted = false;
			break;
		}
	}
	std::cout << type << " is " << (sorted ? GREEN "" : RED "not ") << "sorted" RESET << std::endl;
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
std::vector<size_t> generateJacobsthalSequence(size_t length) {
	std::vector<size_t> jacSeq;

	jacSeq.push_back(0);
	if (length == 0)
		return jacSeq;
	jacSeq.push_back(1);

	size_t n = 2;
	while (true) {
		size_t next = jacSeq[n - 1] + 2 * jacSeq[n - 2];
		if (next > length)
			break;
		jacSeq.push_back(next);
		++n;
	}

	return jacSeq;
}

/*
	Example: n = 8, jacSeq = [0, 1, 1, 3, 5]

	Step 1: Process Jacobsthal ranges
	Range [0, 1]: Add 0 → order = [0]
	Range [1, 1]: Empty → order = [0]
	Range [1, 3]: Add 2, 1 → order = [0, 2, 1]
	Range [3, 5]: Add 4, 3 → order = [0, 2, 1, 4, 3]

	Step 2: Add remaining indices
	Add 5, 6, 7 → order = [0, 2, 1, 4, 3, 5,
*/
std::vector<size_t> getInsertionOrder(size_t n, const std::vector<size_t>& jacSeq) {
	std::vector<size_t> order;
	std::vector<bool> used(n, false);
	
	for (size_t i = 1; i < jacSeq.size() && jacSeq[i] < n; ++i) {
		size_t start = jacSeq[i - 1];
		size_t end = jacSeq[i];
		
		for (size_t k = end - 1; k > start; --k) {
			if (k < n && !used[k]) {
				order.push_back(k);
				used[k] = true;
			}
		}
		if (start < n && !used[start]) {
			order.push_back(start);
			used[start] = true;
		}
	}

	for (size_t j = 0; j < n; ++j)
		if (!used[j])
			order.push_back(j);

	return order;
}

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

		std::vector<size_t> jacSeq = generateJacobsthalSequence(n);
		std::vector<size_t> order = getInsertionOrder(n, jacSeq);

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
	print("");

	long long vec_usec = (t1.tv_sec - t0.tv_sec) * 1000000LL + (t1.tv_usec - t0.tv_usec);
	long long deq_usec = (t2.tv_sec - t1.tv_sec) * 1000000LL + (t2.tv_usec - t1.tv_usec);
	std::cout << "Vector time: " << vec_usec << " us\n"
		<< "Deque time:  " << deq_usec << " us" << std::endl;

	// print("");
	// checkSorting(_vec, "Vector");
	// checkSorting(_deq, "Deque");
}
