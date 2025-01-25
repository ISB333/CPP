/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:16:25 by adesille          #+#    #+#             */
/*   Updated: 2025/01/25 14:31:39 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Canon::Canon() {
	_rawValue = 0;
}

Canon::Canon(const Canon& value) {
	*this = value;
}

Canon& Canon::operator=(const Canon& value) {
	if (this != &value)
		this->_rawValue = *value.getRawBits;
	return (*this);
}
