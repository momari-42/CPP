/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:44:38 by momari            #+#    #+#             */
/*   Updated: 2024/10/10 18:01:46 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "Character.hpp"

class MateriaSource : public IMateriaSource, public Character {
    private:
        int trackingNumber;
        AMateria* materia[4];
        int trackingNumberGarbageCollector;
        AMateria* garbageCollector[1024];

    public:
        MateriaSource( void );
        MateriaSource( const MateriaSource& other );
        MateriaSource& operator=( const MateriaSource& other );
        ~MateriaSource();
        virtual void learnMateria( AMateria* );
        virtual AMateria* createMateria( std::string const & type );
        void manageGarbageCollector ( AMateria* materia);
};

#endif