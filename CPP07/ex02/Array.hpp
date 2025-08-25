/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 07:48:31 by adesille          #+#    #+#             */
/*   Updated: 2025/08/25 12:31:12 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include <cstring>
# include <cstddef>
# include <cstdlib>
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"
# define HYEL 		"\e[0;93m"
# define RESET		"\033[0m"

template<typename T>
class Array {
    private:
        T*      _elements;
        size_t  _size;
    
    public:
        Array(unsigned n = 0);
        Array(const Array& other);
        Array& operator=(Array other);
        ~Array();
        
        T& operator[](size_t index);
        const T& operator[](size_t index) const;
        size_t size() const;
        
        void swap(Array& other);
};

# include "Array.tpp"