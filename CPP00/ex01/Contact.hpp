/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:50:07 by isb               #+#    #+#             */
/*   Updated: 2025/02/05 14:05:28 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once

# include "PhoneBook.hpp"

# include <iostream>
# include <cstring>
# include <sstream>
# include <cstdlib>


# define NO_ERROR_CHECK 0
# define ERROR_CHECK	1
# define CMD 			2
# define SECRET			3

class Contact
{
	public:
 	   std::string	first_name;
 	   std::string	last_name;
 	   std::string	nickname;
 	   std::string	phone_nbr;
 	   std::string	darkest_secret;
};


std::string     prompt(std::string prompt, bool error_check, int type);
int             stoi(std::string& str);
std::string     to_string(int number);
std::string		join_contact(std::string str);
void            print_contact(PhoneBook p);
