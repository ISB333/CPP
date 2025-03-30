/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:13:05 by adesille          #+#    #+#             */
/*   Updated: 2025/03/30 11:35:28 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitcoinExchange.hpp"

void	error(std::string str) { std::cerr << "Error: " << str << std::endl; }
void	print(std::string str) {       std::cout << str << std::endl;        }
void	print(int n)           {        std::cout << n << std::endl;         }

void	printFile(std::vector<std::vector<std::string> > data) {
		for (std::vector<std::vector<std::string> >::const_iterator it = data.begin(); it != data.end(); ++it) {
		    const std::vector<std::string>& row = *it;
		    for (std::vector<std::string>::const_iterator cellIt = row.begin(); cellIt != row.end(); ++cellIt)
		        std::cout << *cellIt << " | ";
		    std::cout << std::endl;
		}
}

std::vector<std::vector<std::string> > readCSV(const std::string& filename) {
    std::vector<std::vector<std::string> > data;
    std::ifstream file(filename.c_str());
    
    if (!file.is_open())
        return error("could not open file"), data;

    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream lineStream(line);
        std::string cell;

        while (std::getline(lineStream, cell, '|'))
            row.push_back(cell);
        data.push_back(row);
    }
    file.close();
    return data;
}

bool	check_date_validity(std::string original_date) {
	std::string date = original_date;
	std::size_t pos1 = date.find_first_of('-');
	std::size_t pos2 = date.find_last_of('-');
    if (pos1 != std::string::npos && pos2 != std::string::npos)
		date.erase(pos1, 1), date.erase(pos2 - 1, 1);
	if (date.find_first_of(' ') != std::string::npos)
		date.erase(date.find_first_of(' '), 1);

	if (date.size() != 8 || !date.find_first_not_of("0123456789"))
		return false;

	std::string month = &date[4], day = &date[6];
	month.erase(2, 1), month.erase(2, 1);
	day.erase(2, 1), day.erase(2, 1);

	if (std::atoi(month.c_str()) > 12 || std::atoi(day.c_str()) > 31)
		return error("bad input => " + original_date), false;

	return true;
}

bool overflowCheck(const std::string& s) {
    long long num = std::atol(s.c_str());
    return (num > INT_MAX);
}

bool	check_value_validity(std::string original_value) {
	if (original_value.find_first_not_of("0123456789"))
		return error("not a number"), false;
	if (std::atof(original_value.c_str()) < 0)
		return error("not a positive number"), false;
	else if (overflowCheck(original_value))
		return error("too large number"), false;
	return true;
}


int main(int argc, char *argv[]) {
	if (argc == 2)
	{
		std::vector<std::vector<std::string> > data = readCSV(argv[1]);
		// printFile(data);

		for (std::vector<std::vector<std::string> >::const_iterator it = data.begin() + 1; it != data.end(); ++it) {
			const std::vector<std::string>& row = *it;
			if (check_date_validity(*row.begin()))
				check_value_validity(row[1]);
		}
	    return 0;
	}
	else if (argc > 2)
		return error("only 1 file allowed."), 1;
	return error("could not open file."), 1;
}
