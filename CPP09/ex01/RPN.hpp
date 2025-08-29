/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:22:12 by adesille          #+#    #+#             */
/*   Updated: 2025/08/29 09:54:17 by adesille         ###   ########.fr       */
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
	public:
		RPN();
		RPN(const RPN &other);
		RPN& operator=(const RPN &other);
		~RPN();

		int		processFormula(std::string formula);
};

void	printError(std::string str);
void	print(std::string str);
void	print(int n);
void	print(char c);
