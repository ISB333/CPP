/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:08:18 by adesille          #+#    #+#             */
/*   Updated: 2025/03/17 08:12:00 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
# include <iostream>
# include <cstring>
// # include "Serializer.hpp"

class Data {
	private:
		void		*ptr;
		uintptr_t	raw;

	public:
		Data();
		~Data();
};
