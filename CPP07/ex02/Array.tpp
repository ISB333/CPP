/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 00:00:00 by adesille          #+#    #+#             */
/*   Updated: 2025/08/25 12:31:50 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
Array<T>::Array(unsigned n) : _elements(new T[n]()), _size(n) {}

template<typename T>
Array<T>::Array(const Array& other) : _elements(new T[other._size]), _size(other._size) {
    std::copy(other._elements, other._elements + _size, _elements);
}

template<typename T>
Array<T>& Array<T>::operator=(Array other) {
    this->swap(other);
    return *this;
}

template<typename T>
Array<T>::~Array() { 
    delete[] _elements; 
}

template<typename T>
T& Array<T>::operator[](size_t index) {
    if (index >= _size) 
        throw std::exception();
    return _elements[index];
}

template<typename T>
const T& Array<T>::operator[](size_t index) const {
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return _elements[index];
}

template<typename T>
size_t Array<T>::size() const { 
    return _size; 
}

template<typename T>
void swap(Array<T>& first, Array<T>& second) {
    std::swap(first._elements, second._elements);
    std::swap(first._size, second._size);
}
