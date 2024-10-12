/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:09:08 by momari            #+#    #+#             */
/*   Updated: 2024/10/05 15:20:19 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    private:
        std::string name;
    public:
        ~DiamondTrap ( void );
        DiamondTrap ( void );
        DiamondTrap ( std::string name );
        DiamondTrap ( const DiamondTrap& diamondTrap );
        DiamondTrap& operator=( const DiamondTrap& diamondTrap );
        void attack( const std::string& target );
        void whoAmI();
};


#endif