/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 07:48:31 by adesille          #+#    #+#             */
/*   Updated: 2025/03/28 12:24:50 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
# include <iostream>
# include <cstring>
# include <cstddef>
# include <cstdlib>
# include <algorithm>
# include <vector>

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
        // void    shortestSpan();
        // void    longestSpan();
};
