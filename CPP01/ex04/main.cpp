/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:48:46 by adesille          #+#    #+#             */
/*   Updated: 2025/01/25 13:49:27 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <fstream>
#include <iostream>

int	main(int argc, char *argv[]) {
	size_t	pos;

	if (argc != 4)
		return (std::cout << "Wrong Numbers of Arguments" << std::endl, 1);
	std::ifstream inFile(argv[1]);
	if (!inFile.is_open())
		return (std::cerr << "Error while opening file", 1);
	std::ofstream outFile((std::string(argv[1]) + ".replace").c_str());
	if (!outFile.is_open())
		return (std::cerr << "Error while opening file", 1);
	std::string line;
	while (std::getline(inFile, line)) {
		pos = 0;
		while ((pos = line.find(argv[2], pos)) != std::string::npos)
		{
			line.erase(pos, strlen(argv[2]));
			line.insert(pos, argv[3]);
			pos += strlen(argv[3]);
		}
		outFile << line << std::endl;
	}
}
