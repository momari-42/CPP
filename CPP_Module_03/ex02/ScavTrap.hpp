/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:06:43 by momari            #+#    #+#             */
/*   Updated: 2024/10/04 11:29:31 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap ( std::string name );
        ScavTrap ( void );
        ~ScavTrap ( void );
        ScavTrap ( const ScavTrap & scavTrap );
        ScavTrap& operator= ( const ScavTrap & scavTrap );
        void guardGate( void );
        void attack( const std::string& target );
};

#endif