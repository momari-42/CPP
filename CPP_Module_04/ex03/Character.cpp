/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:27:31 by momari            #+#    #+#             */
/*   Updated: 2024/10/11 18:16:08 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character ( void ) {
    trackingNumberGarbageCollector = 0;
    for (size_t i = 0; i < 4; i++) {
        materia[i] = NULL;
    }
}

Character::Character ( std::string name ) : name(name) {
    trackingNumberGarbageCollector = 0;
    for (size_t i = 0; i < 4; i++) {
        materia[i] = NULL;
    }
}

Character::Character ( const Character& other ) {
    (*this) = other;
}

Character& Character::operator=( const Character& other ) {
    name = other.name;
    for (size_t i = 0; i < 4; i++) {
        if (materia[i]) {
            delete materia[i];
            materia[i] = NULL;
        }
    }
    for (size_t i = 0; i < 4; i++) {
        if (other.materia[i]) {
            materia[i] = other.materia[i]->clone();
        }
        else
            materia[i] = NULL;
    }
    return (*this);
}

Character::~Character ( void ) {
    for (int i = 0; i < trackingNumberGarbageCollector; i++) {
        delete garbageCollector[i];
        garbageCollector[i] = NULL;
    }
}

static void cleanGarbageCollector ( AMateria** m, int trackingNumberGarbageCollector ) {
    for (int i = 0; i < trackingNumberGarbageCollector; i++) {
            delete m[i];
            m[i] = NULL;
    }
}

void Character::equip ( AMateria* m ) {
    if (m) {
        for (int i = 0; i < trackingNumberGarbageCollector; i++) {
            if (garbageCollector[i] == m) {
                return ;
            }
        }
        garbageCollector[trackingNumberGarbageCollector] = m;
        if (++trackingNumberGarbageCollector  == 1024) {
            cleanGarbageCollector(garbageCollector, trackingNumberGarbageCollector);
            trackingNumberGarbageCollector = 0;
        }
    }
    for (int i = 0; i < 4; i++) {
        if ( !materia[i] ) {
            materia[i] = m;
            break;
        }
    }
}

void Character::unequip ( int idx ) {
    if ( idx < 0 || idx > 3 ) {
        return ;
    }
    materia[idx] = NULL;
}

std::string const & Character::getName( void ) const {
    return (this->name);
}

void Character::use ( int idx, ICharacter& target ) {
    if ( idx < 0 || idx > 3 ) {
        return ;
    }
    if ( materia[idx] ) {
        materia[idx]->use( target );
    }
}