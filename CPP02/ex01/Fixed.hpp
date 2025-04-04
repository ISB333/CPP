/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:01:01 by adesille          #+#    #+#             */
/*   Updated: 2025/04/04 10:51:44 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once

#include <iostream>
#include <cmath>

class	Fixed {
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& value);
		Fixed& operator=(const Fixed& value);
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;

	private:
		int 				_rawValue;
		const static int	_nFixed = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
