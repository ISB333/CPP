/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:50:07 by isb               #+#    #+#             */
/*   Updated: 2025/01/23 10:21:28 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <cstring>
# include <sstream>
# include <cstdlib>

# define NO_ERROR_CHECK 0
# define ERROR_CHECK 1

class Contact
{
	public:
 	   std::string	first_name;
 	   std::string	last_name;
 	   std::string	nickname;
 	   std::string	phone_nbr;
 	   std::string	darkest_secret;
};

class PhoneBook
{
	public:
		Contact c[8];
		int 	i;
};

std::string     prompt(std::string prompt, bool error_check);
int             stoi(std::string& str);
std::string     to_string(int number);
std::string		join_contact(std::string str);
void            print_contact(PhoneBook p);

#endif