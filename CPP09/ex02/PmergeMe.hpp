/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:22:12 by adesille          #+#    #+#             */
/*   Updated: 2025/08/27 11:06:24 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <stack>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <sstream>
# include <string>
# include <cstring>
# include <cstddef>
# include <cstdlib>
# include <algorithm>
# include <vector>
# include <climits>
# include <cctype>
# include <string_view>
# include <cerrno>
# include <ctime>
# include <sys/time.h>

typedef std::vector<std::vector<int> >	doubleVector;
typedef std::vector<int>				vector;
typedef std::deque<std::deque<int> >	doubleDeque;
typedef std::deque<int>					deque;

class PMergeMe {
	private:
		vector				_vec, _vecWinners;
		doubleVector		_vecLosers;
		deque				_deq, _deqWinners;
		doubleDeque			_deqLosers;

		bool				isPositiveInteger(const std::string &s) const;
		bool				isNotOverflow(const char *s) const;
		void				analyzeAndProcessData(char **argv);
		vector				init(char **argv);

		void				fordJohnsonSort();
		void				fordJohnsonSortVec();
		void				fordJohnsonSortDeq();

	public:
		PMergeMe();
		PMergeMe(char **argv);
		PMergeMe(const PMergeMe &other);
		PMergeMe& operator=(const PMergeMe &other);
		~PMergeMe();

		void				printData(std::string s) const;
};

void	printError(std::string str);
void	print(std::string str);
void	print(int n);
void	print(char c);