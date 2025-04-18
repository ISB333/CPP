/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:22:12 by adesille          #+#    #+#             */
/*   Updated: 2025/04/18 13:26:29 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

typedef std::vector<std::vector<int> >	doubleVector;
typedef std::vector<int>				vector;
typedef std::deque<std::deque<int> >	doubleDeque;
typedef std::deque<int>					deque;

class PMergeMe {
	private:
		vector	_vec, _vecSorted, _vecWinners;
		doubleVector _vecLosers;
		deque	_deq, _deqSorted, _deqWinners;
		doubleDeque _deqLosers;

		// std::vector<int>	_vecSorted;
		// std::deque<int>		_deqSorted;

		// double				_vecSortTime;
		// double				_deqSortTime;

		bool				isPositiveInteger(const std::string &s) const;
		bool				isNotOverflow(const char *s) const;
		void				analyzeAndProcessData(char **argv);
		vector				init(char **argv);

		// template<typename Container>
		void				fordJohnsonSort();

	public:
		PMergeMe();
		PMergeMe(char **argv);
		PMergeMe(const PMergeMe &other);
		PMergeMe& operator=(const PMergeMe &other);
		~PMergeMe();

		void				printData() const;
};

void	printError(std::string str);
void	print(std::string str);
void	print(int n);
void	print(char c);
