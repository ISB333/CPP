/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:22:12 by adesille          #+#    #+#             */
/*   Updated: 2025/04/09 13:14:18 by adesille         ###   ########.fr       */
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

class RPN {
	private:
		std::stack<int> stack;

	public:
		RPN();
		// RPN(const char *formula);
		RPN(const RPN &other);
		RPN& operator=(const RPN &other);
		~RPN();
};
