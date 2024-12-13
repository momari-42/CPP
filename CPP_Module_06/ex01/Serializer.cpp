/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:13:55 by momari            #+#    #+#             */
/*   Updated: 2024/11/08 19:46:43 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer ( void ) {
}

Serializer::~Serializer ( void ) {
    
}

Serializer::Serializer ( const Serializer& serializer ) {
    *this = serializer;
}

Serializer& Serializer::operator= ( const Serializer& serializer ) {
    (void)serializer;
    return (*this);
}

uintptr_t Serializer::serialize( Data* ptr ) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data *>(raw));
}