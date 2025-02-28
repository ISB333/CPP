/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:34:45 by isb               #+#    #+#             */
/*   Updated: 2025/02/28 07:02:38 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once

# include <iostream>
# include <cstring>
# include <sstream>
# include <cstdlib>
# include "PhoneBook.hpp"
# include "Contact.hpp"


# define NO_ERROR_CHECK 0
# define ERROR_CHECK	1
# define CMD 			2

# define FIRST_NAME		0
# define LAST_NAME		1
# define NICKNAME		2
# define PHONE_NBR		3
# define SECRET			4

std::string     prompt(std::string prompt, bool error_check, int type);
int             stoi(std::string& str);
std::string     to_string(int number);
std::string		join_contact(std::string str);
void            print_contact(PhoneBook p);
