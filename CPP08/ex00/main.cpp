/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:13:05 by adesille          #+#    #+#             */
/*   Updated: 2025/08/25 09:36:21 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <stdexcept>
#include "easyfind.hpp"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

void printer(const std::string& title) {
    std::cout << "\n" << YELLOW << "=== " << title << " ===" << RESET << "\n";
}

template <typename Container>
void test_find(Container& c, int value, bool should_find) {
    try {
        typename Container::iterator it = easyfind(c, value);
        
        if (!should_find) {
            std::cout << RED << "FAIL" << RESET << ": Found unexpected value " << *it << "\n";
            return;
        }
        
        if (*it == value)
            std::cout << GREEN << "PASS" << RESET << ": Correctly found " << value 
                     << " at position " << std::distance(c.begin(), it) << "\n";
        else
            std::cout << RED << "FAIL" << RESET << ": Found incorrect value " << *it << "\n";
    } 
    catch (const std::exception& e) {
        if (should_find)
            std::cout << RED << "FAIL" << RESET << ": Exception thrown for existing value\n";
        else
            std::cout << GREEN << "PASS" << RESET << ": Correct exception thrown\n";
    }
}

void test_vector() {
    printer("Testing std::vector");
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(20);
    
    test_find(v, 10, true);
    test_find(v, 30, true);
    test_find(v, 20, true);
    test_find(v, 666, false);
}

void test_list() {
    printer("Testing std::list");
    std::list<int> lst;
    lst.push_back(42);
    lst.push_front(100);
    lst.push_back(200);
    
    test_find(lst, 100, true);
    test_find(lst, 42, true);
    test_find(lst, 999, false);
}

void test_deque() {
    printer("Testing std::deque");
    std::deque<int> dq;
    dq.push_back(5);
    dq.push_front(15);
    dq.push_back(25);
    
    test_find(dq, 15, true);
    test_find(dq, 25, true);
    test_find(dq, -5, false);
}

void edge_cases() {
    printer("Edge Cases");
    {
        std::vector<int> empty;
        try {
            easyfind(empty, 0);
            std::cout << RED << "FAIL" << RESET << ": Empty test failed\n";
        } 
        catch (const std::exception&) {
            std::cout << GREEN << "PASS" << RESET << ": Empty handling correct\n";
        }
    }
    {
        std::list<int> single;
        single.push_back(99);
        test_find(single, 99, true);
        test_find(single, 0, false);
    }
}

int main() {
    test_vector();
    test_list();
    test_deque();
    edge_cases();
    
    return 0;
}
