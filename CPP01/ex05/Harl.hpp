/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:52:31 by adesille          #+#    #+#             */
/*   Updated: 2025/01/31 11:54:54 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once

#include <cstring>
#include <iostream>

#define DEBUG                           \
	"I love having extra bacon for my " \
	"7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
#define INFO                                                                  \
	"I cannot believe adding extra bacon costs more money. You didn’t put " \
	"enough bacon in my burger! If you did, I wouldn’t be asking for more!"
#define WARNING                                                                \
	"I think I deserve to have some extra bacon for free. I’ve been coming " \
	"for years whereas you started working here since last month."
#define ERROR "This is unacceptable! I want to speak to the manager now."

class Harl
{
  public:
	void complain(std::string level);
	Harl();

  private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};
