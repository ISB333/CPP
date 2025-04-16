/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:22:12 by adesille          #+#    #+#             */
/*   Updated: 2025/04/16 12:46:39 by adesille         ###   ########.fr       */
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

typedef std::vector<int> vector;

class PMergeMe {
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;

		std::vector<int>	_vecSorted;
		std::deque<int>		_deqSorted;

		double				_vecSortTime;
		double				_deqSortTime;

		bool				isPositiveInteger(const std::string &s) const;
		static vector		init(char **argv);

		template<typename Container>
		void				fordJohnsonSort(Container &data);

	public:
		PMergeMe();
		PMergeMe(char **argv);
		PMergeMe(const PMergeMe &other);
		PMergeMe& operator=(const PMergeMe &other);
		~PMergeMe();

		void				analyzeAndProcessData(char **argv);
		void				printData() const;
};

void	printError(std::string str);
void	print(std::string str);
void	print(int n);
void	print(char c);
