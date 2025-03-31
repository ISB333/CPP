/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:13:05 by adesille          #+#    #+#             */
/*   Updated: 2025/03/31 15:15:58 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitcoinExchange.hpp"

void	print_error(std::string str)     { std::cerr << "Error: " << str << std::endl; }
void	print(std::string str)           {       std::cout << str << std::endl;        }
void	print(int n)                     {        std::cout << n << std::endl;         }
void	print(double n)                  {        std::cout << n << std::endl;         }
void	print(std::string str, double n) { 
    std::cout << str << std::fixed << std::setprecision(2) << n << std::endl;
}

void	printFile(std::vector<std::vector<std::string> > data) {
		for (std::vector<std::vector<std::string> >::const_iterator it = data.begin(); it != data.end(); ++it) {
		    const std::vector<std::string>& row = *it;
		    for (std::vector<std::string>::const_iterator cellIt = row.begin(); cellIt != row.end(); ++cellIt)
		        std::cout << *cellIt << std::endl;
		}
}

std::vector<std::vector<std::string> > readCSV(const std::string& filename, char separator) {
    std::vector<std::vector<std::string> > data;
    std::ifstream file(filename.c_str());
    
    if (!file.is_open())
        return throw std::runtime_error("could not open file"), data;

    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream lineStream(line);
        std::string cell;

        while (std::getline(lineStream, cell, separator))
            row.push_back(cell);
        data.push_back(row);
    }
    file.close();
    return data;
}
std::string trim(const std::string& s) {
    if (s.empty()) return s;

    size_t start = 0;
    while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start])))
        start++;

    size_t end = s.size();
    while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1])))
        end--;

    return s.substr(start, end - start);
}

void trim_2d_vector(std::vector<std::vector<std::string> >& data) {
    for (std::vector<std::vector<std::string> >::iterator outer = data.begin(); 
         outer != data.end(); ++outer) {
        for (std::vector<std::string>::iterator inner = outer->begin(); inner != outer->end(); ++inner)
            *inner = trim(*inner);
    }
}

bool	check_date_validity(std::string original_date) {
	std::string date = original_date;
	std::size_t pos1 = date.find_first_of('-');
	std::size_t pos2 = date.find_last_of('-');
    if (pos1 != std::string::npos && pos2 != std::string::npos)
		date.erase(pos1, 1), date.erase(pos2 - 1, 1);

	if (date.size() != 8 || !date.find_first_not_of("0123456789"))
		return print_error("bad input => " + original_date), false;

	std::string month = &date[4], day = &date[6];
	month.erase(2, 1), month.erase(2, 1);
	day.erase(2, 1), day.erase(2, 1);

	if (std::atoi(month.c_str()) > 12 || std::atoi(day.c_str()) > 31)
		return print_error("bad input => " + original_date), false;

	return true;
}

bool overflowCheck(const std::string& s) {
    long long num = std::atol(s.c_str());
    return (num > INT_MAX);
}

bool	check_value_validity(std::string original_value) {
	if (original_value.find_first_not_of("0123456789") != std::string::npos)
	{
		int i = original_value.find_first_not_of("0123456789");
		if (original_value.find_first_not_of("0123456789", i + 1) != std::string::npos)
			return print_error("not a number"), false;
	}
	if (std::atof(original_value.c_str()) < 0)
		return print_error("not a positive number"), false;
	else if (overflowCheck(original_value))
		return print_error("too large number"), false;
	return true;
}

typedef std::pair<int, int> DateIndexPair;
std::vector<DateIndexPair> sortedDates;

int dateToInt(const std::string& dateStr) {
    int y, m, d;
    std::sscanf(dateStr.c_str(), "%d-%d-%d", &y, &m, &d);
    return y * 10000 + m * 100 + d;
}

size_t findClosestDate(int targetDate) {
    if (sortedDates.empty()) throw "Empty database";

    // Find first date >= target
    std::vector<DateIndexPair>::iterator it = std::lower_bound(
        sortedDates.begin(),
        sortedDates.end(),
        std::make_pair(targetDate, 0)
    );

    if (it == sortedDates.begin()) {
        if (it->first != targetDate) throw "No earlier date found";
        return it->second; // Use first entry if exact match
    }
    
    if (it == sortedDates.end() || it->first != targetDate) {
        --it; // Move to closest previous date
    }

    return it->second; // Index in original database
}

void	find_closest_corresponding_price(std::vector<std::vector<std::string> > data, std::vector<std::string> input_row) {
	int targetDate = dateToInt(input_row[0]);
	try {
        size_t closestIndex = findClosestDate(targetDate);
        // double rate = std::atof(data[closestIndex][1].c_str());
		print(input_row[0] + " => " + input_row[1] + " = ", std::atof(input_row[1].c_str()) * std::atof(data[closestIndex][1].c_str()));
    } catch (const char* error) {
        std::cerr << "Error: " << error << std::endl;
    }
}

void	find_corresponding_price(std::vector<std::vector<std::string> > data, std::vector<std::string> input_row) {
	for (std::vector<std::vector<std::string> >::const_iterator it = data.begin() + 1; it != data.end(); ++it) {
		const std::vector<std::string>& data_row = *it;
		if (!std::strncmp((*input_row.begin()).c_str(), (*data_row.begin()).c_str(), 10)) {
			print(input_row[0] + " => " + input_row[1] + " = ", std::atof(input_row[1].c_str()) * std::atof(data_row[1].c_str()));
			return ;
		}
	}
	find_closest_corresponding_price(data, input_row);
}

void initializeSortedDates(const std::vector<std::vector<std::string> >& data) {
    sortedDates.clear(); // Clear any previous data
    
    // Skip the header row by starting from index 1
    for (size_t i = 1; i < data.size(); i++) {
        int dateValue = dateToInt(data[i][0]);
        sortedDates.push_back(std::make_pair(dateValue, i));
    }
    
    // Sort by date (first element of the pair)
    std::sort(sortedDates.begin(), sortedDates.end());
}

int main(int argc, char *argv[]) {
	if (argc == 2)
	{
		try {
			std::vector<std::vector<std::string> > input = readCSV(argv[1], '|');
			std::vector<std::vector<std::string> > data = readCSV("data.csv", ',');
			
			initializeSortedDates(data);
			trim_2d_vector(input);
			for (std::vector<std::vector<std::string> >::const_iterator it = input.begin() + 1; it != input.end(); ++it) {
				const std::vector<std::string>& row = *it;
				if (check_date_validity(*row.begin()))
					if (check_value_validity(row[1]))
						find_corresponding_price(data, row);
			}
			return 0;
		}
		catch (const std::exception& error) {
			print_error(error.what());
		}
	}
	else if (argc > 2)
		return print_error("only 1 file allowed."), 1;
	return 1;
}
