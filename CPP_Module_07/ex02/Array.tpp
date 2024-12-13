/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:10:10 by momari            #+#    #+#             */
/*   Updated: 2024/11/17 14:45:14 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <exception>
#include <stdexcept>

template <typename T>
Array<T>::Array ( void ) {
    this->n = 1;
    array = new T[0];
    array[0] = 0;
}

template <typename T>
Array<T>::~Array ( void ) {
    delete [] array;
}

template <typename T>
Array<T>::Array ( unsigned int n ) {
    this->n = n;
    array = new T[n];
}

template <typename T>
Array<T>::Array ( const Array& array ) {
    this->n = array.n;
    this->array = new T[array.n];
    for (size_t i = 0; i < array.n; i++) {
        this->array[i] = array.array[i];
    }
}


template <typename T>
Array<T>& Array<T>::operator=( const Array& array ) {
    if (&array != this) {
        delete [] this->array;
        array = new T[array.n];
        for (size_t i = 0; i < array.n; i++) {
            this->array[i] = array.array[i];
        }
    }
    return (*this);
}

template <typename T>
T& Array<T>::operator[](  size_t index ) {
    if ( index >= n )
        throw  Array<T>::IndexOutOfRange();
    return ( array[index] );
}

template <typename T>
const T& Array<T>::operator[]( size_t index ) const {
    if ( index >= n )
        throw Array<T>::IndexOutOfRange();
    return ( array[index] );
}

template <typename T>
size_t Array<T>::size( void ) const {
    return (this->n);
}

template <typename T>
const char *Array<T>::IndexOutOfRange::what( void ) const throw() {
    return ("Index is out of range");
}