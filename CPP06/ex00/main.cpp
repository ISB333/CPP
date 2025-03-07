/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:35:17 by adesille          #+#    #+#             */
/*   Updated: 2025/03/06 07:13:41 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
	if (argc > 1) {
		ScalarConverter a;
		a.convert(argv[1]);
	}

	return (0);
}
