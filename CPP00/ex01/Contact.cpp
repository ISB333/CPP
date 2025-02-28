/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 07:04:59 by adesille          #+#    #+#             */
/*   Updated: 2025/02/28 07:27:12 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "utils.hpp"

Contact::Contact() {};

Contact::~Contact() {};

void Contact::setContact(int field, std::string value) {
	if (field >= 0 && field < 5)
		this->_data[field] = value;
}

std::string Contact::getContact(int field) const {
	if (field >= 0 && field < 5)
		return (this->_data[field]);
	return ("");
}

bool Contact::isEmpty(void) const {
	return (this->_data[FIRST_NAME].empty());
}
