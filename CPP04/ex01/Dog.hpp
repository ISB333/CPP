/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:46:46 by adesille          #+#    #+#             */
/*   Updated: 2025/02/04 11:49:17 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal {
	public:
		Dog();
		Dog(const Dog& src);
		Dog& 			operator=(const Dog& rhs);
		virtual ~Dog(); // Assure destruction of derived class and potential future inheritance of this Class
		
		virtual void	makeSound() const; // To call this derived Class Functions from the base Class

	private:
		Brain* _brain;
};
