/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:00:00 by adesille          #+#    #+#             */
/*   Updated: 2025/04/25 08:46:57 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(const WrongCat& src);
		~WrongCat();
		
		WrongCat&	operator=(const WrongCat& rhs);
		void		makeSound() const;
};
