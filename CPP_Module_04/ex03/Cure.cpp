/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:37:51 by momari            #+#    #+#             */
/*   Updated: 2024/10/10 14:25:22 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure ( void ) : AMateria( "cure" ) {
}

Cure::Cure ( const Cure& other ) {
    (*this) = other;
}

Cure& Cure::operator=( const Cure& other ) {
    this->type = other.type;
    return (*this);
}

Cure::~Cure ( void ) {
}

Cure* Cure::clone ( void ) const {
    Cure* newCure = new Cure();
    newCure->setType(type);
    return (newCure);
}

void Cure::use( ICharacter& target ) {
    std::cout << "* heals " << target.getName() <<  "'s wounds *" << std::endl;
}