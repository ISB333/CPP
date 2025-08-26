/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 07:48:31 by adesille          #+#    #+#             */
/*   Updated: 2025/08/25 13:44:04 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include <ostream>
# include <vector>
# include <cstring>
# include <cstddef>
# include <cstdlib>
# include <algorithm>
# include <list>
# include <deque>
# include <stdexcept>
# define GREEN "\033[32m"
# define RED "\033[31m"
# define YELLOW "\033[33m"
# define RESET "\033[0m"

class NotFoundException : public std::exception {
    public: const char* what() const throw() {
        return "Value not found in container";
    }
};

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::out_of_range("Value not found in container");
    return it;
}
