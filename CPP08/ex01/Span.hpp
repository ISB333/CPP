/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 07:48:31 by adesille          #+#    #+#             */
/*   Updated: 2025/08/25 11:19:45 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include <cstring>
# include <cstddef>
# include <cstdlib>
# include <algorithm>
# include <ctime>
# include <vector>
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


class Span {
    private:
        int                 _maxSize;
        int                 _actualSize;
        std::vector<int>    _numbers;

    public:
        Span();
        Span(int maxSize);
        Span(const Span &other);
        Span& operator=(const Span &other);
        ~Span();

        void    addNumber(int n);
        template <typename Iterator>
        void addNumbers(Iterator begin, Iterator end) {
            while (begin != end) {
                addNumber(*begin);
                ++begin;
            }
        }

        int    shortestSpan() const;
        int    longestSpan() const;
};
