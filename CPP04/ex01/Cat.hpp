/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:46:49 by adesille          #+#    #+#             */
/*   Updated: 2025/04/25 09:05:30 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal {
	public:
		Cat();
		Cat(const Cat& src);
		Cat& operator=(const Cat& rhs);
		virtual ~Cat();
		
		virtual void	makeSound() const;

	private:
		Brain* _brain;
};
