/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:27:04 by adesille          #+#    #+#             */
/*   Updated: 2025/02/04 11:45:17 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once

#include "Animal.hpp"

class	Cat : public Animal {
	public:
		Cat();
		Cat(const Cat& src);
		virtual ~Cat();
		
		Cat& 			operator=(const Cat& rhs);
		virtual void	makeSound() const;
};
