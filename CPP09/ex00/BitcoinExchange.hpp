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
# include <vector>
# include <climits>
# include <cctype>

typedef std::vector<std::vector<std::string> > doubleVector;
typedef std::pair<int, int> DateIndexPair;

class BitcoinExchange {
	private:
		std::vector<DateIndexPair> sortedDates;
		doubleVector input;
		doubleVector data;

	public:
		BitcoinExchange();
		BitcoinExchange(const char *inputFile);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange& operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		doubleVector	readCSV(const std::string& filename, char separator);
		void			initializeSortedDates();
		size_t			findClosestDate(int targetDate);
		void			findClosestCorrespondingPrice(doubleVector data, std::vector<std::string> input_row);
		void			findCorrespondingPrice(doubleVector data, std::vector<std::string> input_row);
		void			analyzeAndProcessData();
};

int		dateToInt(const std::string& dateStr);
void	print(std::string str);
void	print(int n);
void	print(double n);
void	print(std::string str, double n);
void	printError(std::string str);
void	trim2dVector(doubleVector &data);
