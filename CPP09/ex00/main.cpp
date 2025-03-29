/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:13:05 by adesille          #+#    #+#             */
/*   Updated: 2025/03/29 14:49:10 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitcoinExchange.hpp"

std::vector<std::vector<std::string> > readCSV(const std::string& filename) {
    std::vector<std::vector<std::string> > data;
    std::ifstream file(filename.c_str());
    
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return data;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream lineStream(line);
        std::string cell;

        while (std::getline(lineStream, cell, ',')) {
            row.push_back(cell);
        }

        data.push_back(row);
    }

    file.close();
    return data;
}

bool	check_date_validity(std::string date) {
	std::size_t pos1 = date.find_first_of('-', 0);
	std::size_t pos2 = date.find_last_of('-');
    if (pos1 != std::string::npos && pos2 != std::string::npos)
		date.erase(pos1, 1), date.erase(pos2 - 1, 1);

	if (date.size() != 8 || !date.find_first_not_of("0123456789"))
		return false;

	std::string month = &date[4], day = &date[6];
	month.erase(2, 1), month.erase(2, 1);
	day.erase(2, 1), day.erase(2, 1);

	if (std::atoi(month.c_str()) > 12 || std::atoi(day.c_str()) > 31)
		std::cout << "not a valid month or day" << std::endl;

	return true;
}

int main() {
    std::vector<std::vector<std::string> > data = readCSV("data.csv");

    // for (std::vector<std::vector<std::string> >::const_iterator it = data.begin(); it != data.end(); ++it) {
    //     const std::vector<std::string>& row = *it;
    //     for (std::vector<std::string>::const_iterator cellIt = row.begin(); cellIt != row.end(); ++cellIt) {
    //         std::cout << *cellIt << " | ";
    //     }
    //     std::cout << std::endl;
    // }
    for (std::vector<std::vector<std::string> >::const_iterator it = data.begin(); it != data.end(); ++it) {
        const std::vector<std::string>& row = *it;
		if (!check_date_validity(*row.begin()))
			std::cerr << "Error: bad input => " << *row.begin() << std::endl;
	}

    return 0;
}
