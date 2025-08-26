/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:29:47 by adesille          #+#    #+#             */
/*   Updated: 2025/08/26 13:41:31 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string	trim(const std::string& s);
void		trim2dMap(DataMap &data);
bool		checkDateValidity(std::string original_date);
bool		checkValueValidity(std::string original_value);
int			dateToInt(const std::string& dateStr);

BitcoinExchange::BitcoinExchange() : _data(readCSV("data.csv", ',')) { }

BitcoinExchange::BitcoinExchange(const char *_inputFile) : _input(readCSV(_inputFile, '|')), _data(readCSV("data.csv", ',')) { }

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { *this = other; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		this->_data = other._data;
		this->_input = other._input;
		this->_sortedDates = other._sortedDates;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::analyzeAndProcessData() {
	initializeSortedDates();
	trim2dMap(_input);
	
	for (size_t i = 1; i < _input.size(); i++) {
		if (checkDateValidity(_input[i][0]))
			if (checkValueValidity(_input[i][1]))
				findCorrespondingPrice(_data, _input[i]);
	}
}

DataMap BitcoinExchange::readCSV(const std::string& filename, char separator) {
	DataMap data;
	std::ifstream file(filename.c_str());
	
	if (!file.is_open())
		return throw std::runtime_error("could not open file"), data;

	std::string line;
	size_t rowIndex = 0;
	
	while (std::getline(file, line)) {
		std::stringstream lineStream(line);
		std::string cell;
		size_t colIndex = 0;
		
		while (std::getline(lineStream, cell, separator)) {
			data[rowIndex][colIndex] = cell;
			colIndex++;
		}
		rowIndex++;
	}
	file.close();
	return data;
}

void BitcoinExchange::initializeSortedDates() {
	_sortedDates.clear();
	
	for (size_t i = 1; i < _data.size(); i++) {
		int dateValue = dateToInt(_data[i][0]);
		_sortedDates[dateValue] = i;
	}
}

size_t BitcoinExchange::findClosestDate(int targetDate) {
	if (_sortedDates.empty())
		throw "Empty database";

	std::map<int, size_t>::iterator it = _sortedDates.lower_bound(targetDate);
	
	if (it == _sortedDates.begin()) {
		if (it->first != targetDate)
			throw "No earlier date found";
		return it->second;
	}
	
	if (it == _sortedDates.end() || it->first != targetDate)
		--it;
	
	return it->second;
}

void	BitcoinExchange::findClosestCorrespondingPrice(DataMap data, std::map<size_t, std::string> _input_row) {
	int targetDate = dateToInt(_input_row[0]);
	try {
		size_t closestIndex = findClosestDate(targetDate);
		print(_input_row[0] + " => " + _input_row[1] + " = ", std::atof(_input_row[1].c_str()) * std::atof(data[closestIndex][1].c_str()));
	} catch (const char* error) {
		std::cerr << "Error: " << error << std::endl;
	}
}

void	BitcoinExchange::findCorrespondingPrice(DataMap data, std::map<size_t, std::string> _input_row) {
	for (DataMap::const_iterator it = data.begin(); it != data.end(); ++it) {
		const std::map<size_t, std::string>& data_row = it->second;
		if (!std::strncmp(_input_row[0].c_str(), data_row.find(0)->second.c_str(), 10)) {
			print(_input_row[0] + " => " + _input_row[1] + " = ", std::atof(_input_row[1].c_str()) * std::atof(data_row.find(1)->second.c_str()));
			return;
		}
	}
	findClosestCorrespondingPrice(data, _input_row);
}

bool overflowCheck(const std::string& s) {
	long long num = std::atol(s.c_str());
	return (num > INT_MAX);
}

bool	checkValueValidity(std::string original_value) {
	if (original_value.find_first_not_of("0123456789") != std::string::npos) {
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
		return printError("bad _input => " + original_date), false;

	std::string month = &date[4], day = &date[6];
	month.erase(2, 1), month.erase(2, 1);
	day.erase(2, 1), day.erase(2, 1);

	if (std::atoi(month.c_str()) > 12 || std::atoi(day.c_str()) > 31)
		return printError("bad _input => " + original_date), false;

	return true;
}

std::string trim(const std::string& s) {
	if (s.empty())
		return s;

	size_t start = 0;
	while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start])))
		start++;

	size_t end = s.size();
	while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1])))
		end--;

	return s.substr(start, end - start);
}

void	trim2dMap(DataMap &data) {
	for (DataMap::iterator outer = data.begin(); outer != data.end(); ++outer) {
		std::map<size_t, std::string>& innerMap = outer->second;
		for (std::map<size_t, std::string>::iterator inner = innerMap.begin(); inner != innerMap.end(); ++inner)
			inner->second = trim(inner->second);
	}
}

int	dateToInt(const std::string& dateStr) {
	int y, m, d;
	std::sscanf(dateStr.c_str(), "%d-%d-%d", &y, &m, &d);
	return y * 10000 + m * 100 + d;
}
