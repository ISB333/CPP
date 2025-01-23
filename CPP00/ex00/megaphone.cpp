/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 11:34:51 by adesille          #+#    #+#             */
/*   Updated: 2025/01/23 10:02:50 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
	int i = 0;

	if (argc == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
	std::string lol;
	while (argv[++i])
	{
		int j = -1;
		while (argv[i][++j])
			lol += std::toupper(argv[i][j]);
	}
	std::cout << lol << std::endl;
}
