/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:21:20 by momari            #+#    #+#             */
/*   Updated: 2024/10/11 18:05:15 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
    private:
        std::string name;
        AMateria* materia[4];
        int trackingNumberGarbageCollector;
        AMateria* garbageCollector[1024];
    public:
        Character( void );
        Character( std::string name );
        Character( const Character& other );
        Character& operator=( const Character& other );
        ~Character();
        std::string const & getName() const;
        void equip( AMateria* m );
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif