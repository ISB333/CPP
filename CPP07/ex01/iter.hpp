/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 07:48:31 by adesille          #+#    #+#             */
/*   Updated: 2025/06/30 14:20:58 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include <cstring>
# include <cstddef>
# include <cstdlib>

template<typename T>
void    iter(T* array, size_t length, void (*func)(T &)) {
        for (size_t i = 0; i < length; ++i)
                func(array[i]);
}

template<typename T>
void    iter(T* array, size_t length, void (*func)(T const &)) {
        for (size_t i = 0; i < length; ++i)
                func(array[i]);
}