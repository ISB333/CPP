/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:13:05 by adesille          #+#    #+#             */
/*   Updated: 2025/06/30 14:26:51 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void doubleInt(int& n) {
    n *= 2;
}

template <typename T>
void print(const T& x) {
    std::cout << x << " ";
}

void addToFloat(float& f) {
    f += 0.5f;
}

int main() {
    std::cout << "=== Testing int array ===" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    
    std::cout << "Original: ";
    iter(intArray, 5, print<int>);
    std::cout << std::endl;
    iter(intArray, 5, doubleInt);
    std::cout << "After doubling: ";
    iter(intArray, 5, print<int>);
    std::cout << std::endl;

    std::cout << "\n=== Testing float array ===" << std::endl;
    float floatArray[] = {1.1f, 2.2f, 3.3f};
    std::cout << "Original: ";
    iter(floatArray, 3, print<float>);
    std::cout << std::endl;
    iter(floatArray, 3, addToFloat);
    std::cout << "After adding 0.5: ";
    iter(floatArray, 3, print<float>);
    std::cout << std::endl;
    
    std::cout << "\n=== Testing const array ===" << std::endl;
    const char* words[] = {"Hello", "42", "School"};
    std::cout << "String array: ";
    iter(words, 3, print<const char*>);
    std::cout << std::endl;

    return 0;
}

// class Awesome {
//     public:
//         Awesome( void ) : _n( 42 ) { return; }
//         int get( void ) const { return this->_n; }
//     private:
//         int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

// template< typename T >
// void print( T const & x ) { std::cout << x << std::endl; return; }

// int main() {
//     int tab[] = { 0, 1, 2, 3, 4 }; 
//     Awesome tab2[5];
//     iter( tab, 5, print );
//     iter( tab2, 5, print );
//     return 0;
// }