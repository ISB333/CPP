/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:28:08 by adesille          #+#    #+#             */
/*   Updated: 2025/02/04 11:45:14 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once

#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog& src);
		virtual ~Dog(); // Assure destruction of derived class and potential future inheritance of this Class
		
		Dog& 			operator=(const Dog& rhs);
		virtual void	makeSound() const; // To call this derived Class Functions from the base Class
};
