/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 07:48:31 by adesille          #+#    #+#             */
/*   Updated: 2025/03/17 08:11:38 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
# include <iostream>
# include <cstring>
# include "Data.hpp"

class Serializer {
	private:
		Serializer();
		~Serializer();

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
