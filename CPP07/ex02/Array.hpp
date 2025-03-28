/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 07:48:31 by adesille          #+#    #+#             */
/*   Updated: 2025/03/28 10:20:27 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
# include <iostream>
# include <cstring>
# include <cstddef>
# include <cstdlib>

template<typename T>
class Array {
    T*   _elements;
    size_t _size;
public:
    Array(unsigned n = 0) : _elements(new T[n]()), _size(n) {}
    Array(const Array& other) : _elements(new T[other._size]), _size(other._size) {
        std::copy(other._elements, other._elements + _size, _elements);
    }
    Array& operator=(Array other) {
        swap(*this, other);
        return *this;
    }
    ~Array() { delete[] _elements; }
    
    T& operator[](size_t index) {
        if (index >= _size) throw std::exception();
        return _elements[index];
    }
    const T& operator[](size_t index) const {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _elements[index];
    }
    
    size_t size() const { return _size; }
};
