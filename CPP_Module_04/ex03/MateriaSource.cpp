/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:52:33 by momari            #+#    #+#             */
/*   Updated: 2024/10/11 18:10:03 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource ( void ) {
    trackingNumber = 0;
    trackingNumberGarbageCollector = 0;
    for (size_t i = 0; i < 4; i++) {
        materia[i] = NULL;
    }
}

MateriaSource::MateriaSource ( const MateriaSource& other ) {
    *this = other;
}

MateriaSource& MateriaSource::operator=( const MateriaSource& other ) {
    trackingNumber = other.trackingNumber;
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

MateriaSource::~MateriaSource ( void ) {
    for (size_t i = 0; i < 4; i++) {
        if ( materia[i] ) {
            delete materia[i];
            materia[i] = NULL;
        }
    }
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


void MateriaSource::manageGarbageCollector ( AMateria* materia ) {
    for (int i = 0; i < trackingNumberGarbageCollector; i++) {
        if (garbageCollector[i] == materia) {
            return ;
        }
    }
    garbageCollector[trackingNumberGarbageCollector] = materia;
    if (++trackingNumberGarbageCollector  == 1024) {
        cleanGarbageCollector(garbageCollector, trackingNumberGarbageCollector);
        trackingNumberGarbageCollector = 0;
    }
}

void MateriaSource::learnMateria( AMateria* materia ) {
    manageGarbageCollector(materia);
    if ( trackingNumber > 3 ) {
        return ;
    }
    AMateria* newMateria = new Cure();
    newMateria->setType(materia->getType());
    this->materia[trackingNumber] = newMateria;
    trackingNumber++;
}

AMateria* MateriaSource::createMateria( std::string const & type ) {
    AMateria* newMateria;
    for (size_t i = 0; i < 4; i++) {
        if (materia[i] && materia[i]->getType() == type) {
            if (materia[i]->getType() == "cure") {
                newMateria = new Cure();
            }
            else {
                newMateria = new Ice();
            }
            newMateria->setType(type);
            return (newMateria);
        }
    }
    return (0);
}