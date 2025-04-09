/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:29:47 by adesille          #+#    #+#             */
/*   Updated: 2025/04/09 13:06:02 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitcoinExchange.hpp"

std::string	trim(const std::string& s);
void		trim2dVector(doubleVector &data);
bool		checkDateValidity(std::string original_date);
bool		checkValueValidity(std::string original_value);
int			dateToInt(const std::string& dateStr);

BitcoinExchange::BitcoinExchange() : data(readCSV("data.csv", ',')) { }

BitcoinExchange::BitcoinExchange(const char *inputFile) : input(readCSV(inputFile, '|')), data(readCSV("data.csv", ',')) { }

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { *this = other; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		this->data = other.data;
		this->input = other.input;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() { }

void	BitcoinExchange::analyzeAndProcessData() {
	initializeSortedDates();
	trim2dVector(input);
	for (doubleVector::const_iterator it = input.begin() + 1; it != input.end(); ++it) {
		const std::vector<std::string>& row = *it;
		if (checkDateValidity(*row.begin()))
			if (checkValueValidity(row[1]))
				findCorrespondingPrice(data, row);
	}
}

doubleVector BitcoinExchange::readCSV(const std::string& filename, char separator) {
    doubleVector data;
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

void BitcoinExchange::initializeSortedDates() {
    sortedDates.clear();
    
    for (size_t i = 1; i < data.size(); i++) {
        int dateValue = dateToInt(data[i][0]);
        sortedDates.push_back(std::make_pair(dateValue, i));
    }
    
    std::sort(sortedDates.begin(), sortedDates.end());
}

size_t BitcoinExchange::findClosestDate(int targetDate) {
    if (sortedDates.empty()) throw "Empty database";

    std::vector<DateIndexPair>::iterator it = std::lower_bound(
        sortedDates.begin(),
        sortedDates.end(),
        std::make_pair(targetDate, 0)
    );

    if (it == sortedDates.begin()) {
        if (it->first != targetDate) throw "No earlier date found";
        return it->second;
    }
    
    if (it == sortedDates.end() || it->first != targetDate) {
        --it;
    }

    return it->second;
}

void	BitcoinExchange::findClosestCorrespondingPrice(doubleVector data, std::vector<std::string> input_row) {
	int targetDate = dateToInt(input_row[0]);
	try {
        size_t closestIndex = findClosestDate(targetDate);
		print(input_row[0] + " => " + input_row[1] + " = ", std::atof(input_row[1].c_str()) * std::atof(data[closestIndex][1].c_str()));
    } catch (const char* error) {
        std::cerr << "Error: " << error << std::endl;
    }
}

void	BitcoinExchange::findCorrespondingPrice(doubleVector data, std::vector<std::string> input_row) {
	for (doubleVector::const_iterator it = data.begin() + 1; it != data.end(); ++it) {
		const std::vector<std::string>& data_row = *it;
		if (!std::strncmp((*input_row.begin()).c_str(), (*data_row.begin()).c_str(), 10)) {
			print(input_row[0] + " => " + input_row[1] + " = ", std::atof(input_row[1].c_str()) * std::atof(data_row[1].c_str()));
			return ;
		}
	}
	findClosestCorrespondingPrice(data, input_row);
}

bool overflowCheck(const std::string& s) {
    long long num = std::atol(s.c_str());
    return (num > INT_MAX);
}

bool	checkValueValidity(std::string original_value) {
	if (original_value.find_first_not_of("0123456789") != std::string::npos)
	{
		int i = original_value.find_first_not_of("0123456789");
		if (original_value.find_first_not_of("0123456789", i + 1) != std::string::npos)
			return printError("not a number"), false;
	}
	if (std::atof(original_value.c_str()) < 0)
		return printError("not a positive number"), false;
	else if (overflowCheck(original_value))
		return printError("too large number"), false;
	return true;
}

bool	checkDateValidity(std::string original_date) {
	std::string date = original_date;
	std::size_t pos1 = date.find_first_of('-');
	std::size_t pos2 = date.find_last_of('-');
    if (pos1 != std::string::npos && pos2 != std::string::npos)
		date.erase(pos1, 1), date.erase(pos2 - 1, 1);

	if (date.size() != 8 || !date.find_first_not_of("0123456789"))
		return printError("bad input => " + original_date), false;

	std::string month = &date[4], day = &date[6];
	month.erase(2, 1), month.erase(2, 1);
	day.erase(2, 1), day.erase(2, 1);

	if (std::atoi(month.c_str()) > 12 || std::atoi(day.c_str()) > 31)
		return printError("bad input => " + original_date), false;

	return true;
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

void	trim2dVector(doubleVector &data) {
    for (doubleVector::iterator outer = data.begin(); 
         outer != data.end(); ++outer) {
        for (std::vector<std::string>::iterator inner = outer->begin(); inner != outer->end(); ++inner)
            *inner = trim(*inner);
    }
}

int	dateToInt(const std::string& dateStr) {
    int y, m, d;
    std::sscanf(dateStr.c_str(), "%d-%d-%d", &y, &m, &d);
    return y * 10000 + m * 100 + d;
}
