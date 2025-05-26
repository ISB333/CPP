/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:54:08 by adesille          #+#    #+#             */
/*   Updated: 2025/04/25 09:04:33 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal {
	public:
		Dog();
		Dog(const Dog& src);
		Dog& operator=(const Dog& rhs);
		virtual ~Dog();
		
		virtual void	makeSound() const;

	private:
		Brain* _brain;
};
