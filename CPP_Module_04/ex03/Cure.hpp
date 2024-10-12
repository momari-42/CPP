/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:37:53 by momari            #+#    #+#             */
/*   Updated: 2024/10/09 13:15:48 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
    public:
        Cure ( void );
        Cure ( const Cure& other );
        Cure& operator=( const Cure& other );
        ~Cure ( void );
        virtual Cure* clone() const;
        void use( ICharacter& target );
        
};

#endif