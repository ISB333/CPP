/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:13:05 by adesille          #+#    #+#             */
/*   Updated: 2025/03/29 11:01:02 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"

std::vector<int> generateUniqueRand(size_t count) {
    std::vector<int> result;
    srand(time(0));
    
    while (result.size() < count) {
        int num = rand() % 1000000;
        if (std::find(result.begin(), result.end(), num) == result.end()) {
            result.push_back(num);
        }
    }
    return result;
}

int main()
{
	try {
		{
			Span sp = Span(5);
			std::cout << "=== TEST 1 ===" << std::endl;
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		{
			Span sp = Span(1000);
			std::cout << "=== TEST 2 ===" << std::endl;
			std::vector<int> big = generateUniqueRand(1000);
			sp.addNumbers(big.begin(), big.end());
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		{
			Span sp = Span(100);
			std::cout << "=== TEST 3 (out of bounds) ===" << std::endl;
			std::vector<int> big = generateUniqueRand(1000);
			sp.addNumbers(big.begin(), big.end());
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
	}
    catch (const std::exception& error) {
		std::cout << error.what() << std::endl;
	}
	return 0;
}
