/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:22:12 by adesille          #+#    #+#             */
/*   Updated: 2025/08/26 14:16:51 by adesille         ###   ########.fr       */
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
# include <list>

class RPN {
	private:
		std::list<int>	_nbrs;
		std::list<char>	_operators;
		std::string		_formula;

	public:
		RPN();
		RPN(const RPN &other);
		RPN& operator=(const RPN &other);
		~RPN();

		void	parseFormula(std::string);
		int		processFormula();
};

void	printError(std::string str);
void	print(std::string str);
void	print(int n);
void	print(char c);
