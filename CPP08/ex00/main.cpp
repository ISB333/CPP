/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:13:05 by adesille          #+#    #+#             */
/*   Updated: 2025/03/28 11:41:38 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <stdexcept>
#include "easyfind.hpp"

// ANSI Color Codes for better visibility
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

void print_divider(const std::string& title) {
    std::cout << "\n" << YELLOW << "[ " << title << " ]" << RESET << "\n";
}

template <typename Container>
void test_find(Container& c, int value, bool should_find) {
    try {
        typename Container::iterator it = easyfind(c, value);
        
        if (!should_find) {
            std::cout << RED << "FAIL" << RESET << ": Found unexpected value " << *it << "\n";
            return;
        }
        
        if (*it == value) {
            std::cout << GREEN << "PASS" << RESET << ": Correctly found " << value 
                     << " at position " << std::distance(c.begin(), it) << "\n";
        } else {
            std::cout << RED << "FAIL" << RESET << ": Found incorrect value " << *it << "\n";
        }
    } 
    catch (const std::exception& e) {
        if (should_find) {
            std::cout << RED << "FAIL" << RESET << ": Exception thrown for existing value\n";
        } else {
            std::cout << GREEN << "PASS" << RESET << ": Correct exception thrown\n";
        }
    }
}

// ---------- Container Specific Tests ----------

void test_vector() {
    print_divider("Testing std::vector");
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(20);
    
    test_find(v, 10, true);   // First element
    test_find(v, 30, true);   // Last element
    test_find(v, 20, true);   // Multiple occurrences
    test_find(v, 666, false); // Non-existent
}

void test_list() {
    print_divider("Testing std::list");
    std::list<int> lst;
    lst.push_back(42);
    lst.push_front(100);
    lst.push_back(200);
    
    test_find(lst, 100, true); // Front insertion
    test_find(lst, 42, true);  // Middle
    test_find(lst, 999, false);
}

void test_deque() {
    print_divider("Testing std::deque");
    std::deque<int> dq;
    dq.push_back(5);
    dq.push_front(15);
    dq.push_back(25);
    
    test_find(dq, 15, true);  // Front-position
    test_find(dq, 25, true);  // Back-position
    test_find(dq, -5, false);
}

void edge_cases() {
    print_divider("Edge Cases");
    
    // Empty container
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

    // Single element container
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
