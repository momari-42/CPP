/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:55:25 by momari            #+#    #+#             */
/*   Updated: 2024/11/16 17:43:38 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream> // IWYU pragma: keep
#include <exception> // IWYU pragma: keep

template <typename T>
class Array {
    private:
        size_t  n;
        T       *array;
    public:
        class IndexOutOfRange : public std::exception {
            public:
                const char *what( void ) const throw();
        };
        Array ( void );
        ~Array ( void );
        Array ( unsigned int n );
        Array ( const Array& array );
        Array& operator= ( const Array& array );
        T& operator[] ( size_t index );
        const T& operator[] ( size_t index ) const ;
        size_t size() const;
};

#include "Array.tpp"