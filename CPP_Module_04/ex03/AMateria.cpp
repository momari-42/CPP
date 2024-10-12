/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:09:03 by momari            #+#    #+#             */
/*   Updated: 2024/10/10 14:24:58 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria ( void ) {
}

AMateria::AMateria ( std::string const & type ) : type(type) {
}

AMateria::AMateria ( const AMateria& other ) {
    (*this) = other;
}

AMateria& AMateria::operator=(const AMateria& other) {
    type = other.type;
    return (*this);
}

AMateria::~AMateria( void ) {
}

std::string const & AMateria::getType ( void ) const {
    return (type);
}

void AMateria::setType( std::string type ) {
    this->type = type;
}

void AMateria::use( ICharacter& target ) {
    std::cout << target.getName() << " we are in parent" << std::endl;
}