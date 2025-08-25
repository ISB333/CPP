/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:13:05 by adesille          #+#    #+#             */
/*   Updated: 2025/08/25 12:30:29 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void print(const T& x) {
    std::cout << x << " " << std::endl;
}

void printString(const std::string& str) {
    std::cout << "\"" << str << "\" " << std::endl;
}

int main() {
    std::cout << BLUE "=== Testing int array ===" RESET << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    iter(intArray, 5, print<int>);
    std::cout << std::endl;

    std::cout << MAGENTA "=== Testing double array ===" RESET << std::endl;
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    iter(doubleArray, 4, print<double>);
    std::cout << std::endl;

    std::cout << YELLOW "=== Testing char array ===" RESET << std::endl;
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    iter(charArray, 5, print<char>);
    std::cout << std::endl;

    std::cout << GREEN "=== Testing string array ===" RESET << std::endl;
    std::string stringArray[] = {"Hello", "World", "42", "School"};
    iter(stringArray, 4, printString);
    std::cout << std::endl;

    std::cout << CYAN "=== Testing bool array ===" RESET << std::endl;
    bool boolArray[] = {true, false, true, false};
    iter(boolArray, 4, print<bool>);
    std::cout << std::endl;

    std::cout << RED "=== Testing long array ===" RESET << std::endl;
    long longArray[] = {100L, 200L, 300L};
    iter(longArray, 3, print<long>);
    std::cout << std::endl;

    std::cout << WHITE "=== Testing const char* array ===" RESET << std::endl;
    const char* cStringArray[] = {"First", "Second", "Third"};
    iter(cStringArray, 3, print<const char*>);
    std::cout << std::endl;

    return 0;
}
