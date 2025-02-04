/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:52:59 by adesille          #+#    #+#             */
/*   Updated: 2025/02/04 11:55:55 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class	Brain {
	public:
		Brain();
		Brain(const Brain& src);
		Brain& 			operator=(const Brain& rhs);
		virtual ~Brain();

	private:
		std::string _ideas[100];
};
