/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:41:10 by momari            #+#    #+#             */
/*   Updated: 2024/10/05 10:49:31 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap {
    public:
        FragTrap( void );
        FragTrap ( std::string name );
        ~FragTrap ( void );
        FragTrap ( const FragTrap& fragtrap );
        FragTrap& operator= ( const FragTrap& fragtrap );
        void attack( const std::string& target );
        void highFivesGuys(void);
};

#endif