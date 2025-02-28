/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 11:34:51 by adesille          #+#    #+#             */
/*   Updated: 2025/02/28 12:49:40 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "utils.hpp"

//TODO: ADD Fake Segfault

void	find_contact(PhoneBook *p)
{
	std::string index;
	int			i;

	print_contact(*p);
	index = prompt("Enter the index of the contact you want to display: ", NO_ERROR_CHECK, CMD);
	if (!index[1] && std::isdigit(index[0]))
	{
		i = stoi(index) - 1;
		if (i >= 0 && i < 8 && !p->c[i].isEmpty())
		{
			std::cout << p->c[i].getContact(FIRST_NAME) << "\n"
					<< p->c[i].getContact(LAST_NAME) << "\n"
					<< p->c[i].getContact(NICKNAME) << "\n"
					<< p->c[i].getContact(PHONE_NBR) << "\n"
					<< p->c[i].getContact(SECRET) << std::endl;
		}
		else
			std::cout << "Invalid index" << std::endl;
	}
	else
		std::cout << "Index is not valid" << std::endl;
}

void	add_contact(PhoneBook *p)
{
	if ((*p).i == 7)
		(*p).i = -1;
	(*p).i++;
	(*p).c[(*p).i].setContact(FIRST_NAME, prompt("First name: ", ERROR_CHECK, CMD));
	(*p).c[(*p).i].setContact(LAST_NAME, prompt("Last name: ", ERROR_CHECK, CMD));
	(*p).c[(*p).i].setContact(NICKNAME, prompt("Nickname: ", ERROR_CHECK, CMD));
	(*p).c[(*p).i].setContact(PHONE_NBR, prompt("Phone number: ", ERROR_CHECK, CMD));
	(*p).c[(*p).i].setContact(SECRET, prompt("Darkest secret: ", ERROR_CHECK, SECRET));
}

int main()
{
	std::string	cmd;
	PhoneBook 	p;

	p.i = -1;
	cmd = prompt("Enter your command:", NO_ERROR_CHECK, CMD);
	while (cmd != "EXIT" && !cmd.empty())
	{
		if (cmd == "ADD")
			add_contact(&p);
		else if (cmd == "SEARCH")
			find_contact(&p);
		else if (cmd == "EXIT")
			exit(EXIT_SUCCESS);
		cmd = prompt("Enter your command: ", NO_ERROR_CHECK, CMD);
	}
}
