/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:37:55 by momari            #+#    #+#             */
/*   Updated: 2024/10/10 14:25:37 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice ( void ) : AMateria( "ice" ) {
}

Ice::Ice ( const Ice& other ) {
    (*this) = other;
}

Ice& Ice::operator=( const Ice& other ) {
    this->type = other.type;
    return (*this);
}

Ice::~Ice ( void ) {
}

Ice* Ice::clone ( void ) const {
    Ice* newIce = new Ice();
    return (newIce);
}

void Ice::use( ICharacter& target ) {
    std::cout << "* shoots an ice bolt at " << target.getName() <<  " *" << std::endl;
}