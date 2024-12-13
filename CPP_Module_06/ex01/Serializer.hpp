/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:13:53 by momari            #+#    #+#             */
/*   Updated: 2024/11/07 17:32:44 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

typedef struct t_data {
    std::string content;
    int         inumber;
    float       fNumber;
    double      dNumber;
    long        lNumber;
} Data;


class Serializer {
    private:
        Serializer ( void );

    public:
        ~Serializer ( void );
        Serializer ( const Serializer& serializer );
        Serializer& operator= ( const Serializer& serializer );
        static void convert ( const std::string input );
        // this is the static methodes
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};
