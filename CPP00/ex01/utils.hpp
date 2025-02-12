/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb <isb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:34:45 by isb               #+#    #+#             */
/*   Updated: 2025/02/12 10:35:19 by isb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define SECRET			3

std::string     prompt(std::string prompt, bool error_check, int type);
int             stoi(std::string& str);
std::string     to_string(int number);
std::string		join_contact(std::string str);
void            print_contact(PhoneBook p);