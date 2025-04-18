/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:01:01 by adesille          #+#    #+#             */
/*   Updated: 2025/01/26 08:53:32 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"

class	Fixed {
	public:
		Fixed();
		Fixed(const Fixed& value);
		Fixed& operator=(const Fixed& value);
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);

	private:
		int 				_rawValue;
		const static int	_nFixed;
};
