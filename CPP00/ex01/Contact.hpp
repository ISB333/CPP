/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:50:07 by isb               #+#    #+#             */
/*   Updated: 2025/02/28 07:22:17 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once

# include "utils.hpp"

class Contact
{
	private:
		std::string	_data[5];

	public:
		Contact();
		~Contact();

		void		setContact(int field, std::string value);
		std::string	getContact(int field) const;
		bool		isEmpty(void) const;
};
