/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:18:44 by adesille          #+#    #+#             */
/*   Updated: 2025/01/20 12:33:00 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *ptr = &brain;
	std::string	&ref = brain;

	std::cout << "Brain = " << &brain << std::endl << "Pointer = " << &ptr[0]
		<< std::endl << "Reference = " << &ref << std::endl;
}
