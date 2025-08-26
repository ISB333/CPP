/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 07:48:31 by adesille          #+#    #+#             */
/*   Updated: 2025/04/09 10: by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
# include <iostream>
# include <iomanip>
# include <fstream>
# include <sstream>
# include <string>
# include <cstring>
# include <cstddef>
# include <cstdlib>
# include <algorithm>
# include <map>
# include <climits>
# include <cctype>

typedef std::map<size_t, std::map<size_t, std::string> > DataMap;

class BitcoinExchange {
	private:
		std::map<int, size_t>	_sortedDates;
		DataMap 				_input;
		DataMap					_data;

	public:
		BitcoinExchange();
		BitcoinExchange(const char *inputFile);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange& operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		DataMap	readCSV(const std::string& filename, char separator);
		void	initializeSortedDates();
		size_t	findClosestDate(int targetDate);
		void	findClosestCorrespondingPrice(DataMap data, std::map<size_t, std::string> input_row);
		void	findCorrespondingPrice(DataMap data, std::map<size_t, std::string> input_row);
		void	analyzeAndProcessData();
};

int		dateToInt(const std::string& dateStr);
void	print(std::string str);
void	print(int n);
void	print(double n);
void	print(std::string str, double n);
void	printError(std::string str);
void	trim2dMap(DataMap &data);
