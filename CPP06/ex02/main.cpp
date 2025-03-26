/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:13:05 by adesille          #+#    #+#             */
/*   Updated: 2025/03/26 14:12:45 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
	int r = rand();

	if (!(r % 3))
		return (new A);
	else if (r % 3 == 1)
		return (new B);
	else if (r % 3 == 2)
		return (new C);
	return (nullptr);
}

void	identify(Base* p) {
    if (dynamic_cast<A*>(p) != nullptr)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != nullptr)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != nullptr)
        std::cout << "C" << std::endl;
}

void	identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    } catch (...) {}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    } catch (...) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    } catch (...) {}
    std::cout << "Unknown type" << std::endl;
}

int main() {
    for (int i = 0; i < 5; i++) {
        Base* ptr = generate();
        
        std::cout << "Identify using pointer: ";
        identify(ptr);
        std::cout << "Identify using reference: ";
        identify(*ptr);
  
        std::cout << "------------------------" << std::endl;
        delete (ptr);
    }
    return 0;

}
