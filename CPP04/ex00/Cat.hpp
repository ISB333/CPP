/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:27:04 by adesille          #+#    #+#             */
/*   Updated: 2025/04/25 08:48:35 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once

#include "Animal.hpp"

class	Cat : public Animal {
	public:
		Cat();
		Cat(const Cat& src);
		Cat& operator=(const Cat& rhs);
		virtual ~Cat();
		
		virtual void	makeSound() const;
};
