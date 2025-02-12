/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb <isb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:52:55 by isb               #+#    #+#             */
/*   Updated: 2025/02/12 10:39:51 by isb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

std::string	prompt(std::string prompt, bool error_check, int type)
{
	std::string cmd;

	std::cout << prompt << std::endl;
	while (std::getline(std::cin, cmd))
	{
		if (cmd.empty() && error_check)
		{
			std::cout << "This field cannot be empty!" << std::endl;
			std::cout << prompt << std::endl;
		}
		else if (cmd.empty() && !error_check)
			return (" ");
		else
		{
			int start = cmd.find_first_not_of(" \t\n\r\f\v");
			int end = cmd.find_last_not_of(" \t\n\r\f\v") + 1;
			if (end)
			{
				cmd = cmd.substr(start, end);
				if (type != SECRET)
				{
					std::string formatted;
					int len = cmd.length();
					for (int i = 0; i < len; i++)
						if (cmd[i] != '\t' || cmd[i] != '\n' || cmd[i] != '\r'
							|| cmd[i] != '\f' || cmd[i] != '\v')
							formatted += cmd[i];
					return (formatted);
				}
				return (cmd);
			}
		}
	}
	return (exit(EXIT_SUCCESS), "");
}

int stoi(std::string& str)
{
	std::stringstream	ss(str);
	int					num;

	ss >> num;
	if (ss.fail() || !ss.eof())
		throw (std::invalid_argument("Invalid string for conversion to integer"));
	return (num);
}

std::string to_string(int number)
{
	std::stringstream ss;
	ss << number;
	return (ss.str());
}

std::string	join_contact(std::string str)
{
	std::string new_str;

	new_str += '|';
	if (str.length() > 10)
	{
		int len = str.length();
		new_str += str.erase(10, len - 10);
		new_str[10] = '.';
	}
	else
	{
		new_str += str;
		int i = 10 - str.length() + 1;
		while (--i)
			new_str += ' ';
	}
	return (new_str);
}

void	print_contact(PhoneBook p)
{
	int i = -1;
	std::string str;
	
	while (++i < 8)
	{
		if (p.c[i].first_name.empty())
			continue; ;
		str += join_contact(to_string(i + 1));
		str += join_contact(p.c[i].first_name);
		str += join_contact(p.c[i].last_name);
		str += join_contact(p.c[i].nickname);
		str += '|';
		std::cout << str << std::endl;
		str.clear();
	}
}
