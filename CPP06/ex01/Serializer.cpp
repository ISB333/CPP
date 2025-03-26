/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 07:06:35 by adesille          #+#    #+#             */
/*   Updated: 2025/03/26 11:55:12 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Serializer.hpp"

Serializer::Serializer() {};

Serializer::Serializer(const Serializer& other) {(void)other;}

Serializer& Serializer::operator=(const Serializer& other) {return (*this);}

Serializer::~Serializer() {};

uintptr_t	Serializer::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}
