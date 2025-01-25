/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:51:37 by adesille          #+#    #+#             */
/*   Updated: 2025/01/25 11:01:11 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[]) {
  Harl harl;

  if (argc == 2)
    return (harl.complain(argv[1]), 0);
  std::cout << "Wrong number of arguments" << std::endl;
  return (1);
}
