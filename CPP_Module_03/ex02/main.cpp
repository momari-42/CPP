/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:03:08 by momari            #+#    #+#             */
/*   Updated: 2024/10/05 15:22:58 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {

    FragTrap fragTrap1 ("FCTP1");
    FragTrap fragTrap2 ("FCTP2");

    fragTrap2.attack("FCTP1");
    fragTrap1.takeDamage(10);

    fragTrap2.beRepaired(50);
    fragTrap2.takeDamage(130);
    
    fragTrap2.attack("FCTP1");
    fragTrap2.takeDamage(10);
    
    return 0;
}