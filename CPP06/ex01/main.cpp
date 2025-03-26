/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:13:05 by adesille          #+#    #+#             */
/*   Updated: 2025/03/26 10:52:38 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Serializer.hpp"

int main() {
	Data data;

	data.raw = 18;
	uintptr_t value = Serializer::serialize(&data);
	std::cout << "After deserialization:  " << Serializer::deserialize(value) << std::endl;

	std::cout << "Original address:       " << &data << std::endl;
}
