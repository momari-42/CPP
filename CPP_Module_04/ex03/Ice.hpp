/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:37:57 by momari            #+#    #+#             */
/*   Updated: 2024/10/09 13:16:34 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
    public:
        Ice ( void );
        Ice ( const Ice& other );
        Ice& operator=( const Ice& other );
        ~Ice ( void );
        virtual Ice* clone() const;
        void use( ICharacter& target );
};

#endif