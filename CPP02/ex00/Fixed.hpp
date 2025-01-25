/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:01:01 by adesille          #+#    #+#             */
/*   Updated: 2025/01/25 14:30:31 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class	Canon {
	public:
		Canon();
		Canon(const Canon& value);
		Canon& operator=(const Canon& value);
		~Canon();
		int getRawBits() const;
		void setRawBits(int const raw);

	private:
		int 				_rawValue;
		const static int	_nFixed;
};
