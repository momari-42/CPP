/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:03:08 by momari            #+#    #+#             */
/*   Updated: 2024/10/05 14:47:13 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {

    ScavTrap scavtrap1 ("SCTP1");
    ScavTrap scavtrap2 ("SCTP2");

    scavtrap1.attack("SCTP2");
    scavtrap2.takeDamage(20);

    scavtrap2.attack("SCTP1");
    scavtrap1.takeDamage(10);

    scavtrap2.beRepaired(50);
    scavtrap2.takeDamage(130);
    
    scavtrap2.attack("SCTP1");
    scavtrap2.takeDamage(10);
    
    return 0;
}