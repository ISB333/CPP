/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb <isb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 08:52:14 by adesille          #+#    #+#             */
/*   Updated: 2025/03/10 07:22:23 by isb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	std::cout << "a (before initialization) = " << a.getRawBits() << std::endl;
	a.setRawBits(5);
	Fixed b( a );
	std::cout << "a = " << a.getRawBits() << std::endl;
	std::cout << "b = " << b.getRawBits() << std::endl;
	b.setRawBits(21);
	Fixed c;
	std::cout << "c (before initialization) = " << c.getRawBits() << std::endl;
	c = b;
	std::cout << "b = " << b.getRawBits() << std::endl;
	std::cout << "c = " << c.getRawBits() << std::endl;
	return (0);
}
