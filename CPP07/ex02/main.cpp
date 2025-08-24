/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:13:05 by adesille          #+#    #+#             */
/*   Updated: 2025/08/24 00:00:00 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Array.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX_VAL 750

void testDefaultConstructor() {
    std::cout << BLUE "=== Testing Default Constructor ===" RESET << std::endl;
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl << std::endl;
}

Array<int> testSizedConstructor() {
    std::cout << MAGENTA "=== Testing Sized Constructor & Random Values ===" RESET << std::endl;
    Array<int> numbers(MAX_VAL);
    
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }
    std::cout << "Created array with size: " << numbers.size() << std::endl;
    std::cout << "Filled array with random values" << std::endl << std::endl;
    
    return numbers;
}

void testArrayIntegrity(const Array<int>& numbers) {
    std::cout << MAGENTA "=== Testing Array Integrity ===" RESET << std::endl;
    
    int* mirror = new int[MAX_VAL];
    for (int i = 0; i < MAX_VAL; i++)
        mirror[i] = numbers[i];
    
    Array<int> copy = numbers;
    copy[0] = 9999;
    
    bool integrity = true;
    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << RED "ERROR: Arrays don't match at index " << i << "!" RESET << std::endl;
            integrity = false;
            break;
        }
    }
    
    if (integrity)
        std::cout << GREEN "Array integrity verified: All values match ✓" RESET << std::endl;
    delete[] mirror;
    std::cout << std::endl;
}

void testExceptionHandling(Array<int>& numbers) {
    std::cout << BLUE "=== Testing Exception Handling ===" RESET << std::endl;
    try {
        numbers[-2] = 0;
    } catch(const std::exception& e) {
        std::cout << RED "Exception caught for negative index: " << e.what() << RESET << std::endl;
    }
    try {
        numbers[MAX_VAL] = 0;
    } catch(const std::exception& e) {
        std::cout << RED "Exception caught for out of bounds: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;
}

void testStringType() {
    std::cout << MAGENTA "=== Testing With String Type ===" RESET << std::endl;
    
    Array<std::string> strings(3);
    strings[0] = "Hello";
    strings[1] = "42";
    strings[2] = "School";
    
    std::cout << "String array contents:" << std::endl;
    for (unsigned int i = 0; i < strings.size(); i++)
        std::cout << BLUE "[" << i << "] " RESET << strings[i] << std::endl;
    
    std::cout << std::endl;
}

int main(void)
{
    testDefaultConstructor();
    Array<int> numbers = testSizedConstructor();
    testArrayIntegrity(numbers);
    testExceptionHandling(numbers);
    testStringType();
    
    std::cout << GREEN "=== All Tests Completed ===" RESET << std::endl;
    return 0;
}
