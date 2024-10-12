/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:03:08 by momari            #+#    #+#             */
/*   Updated: 2024/10/05 14:44:05 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap claptrap1("CLTP1");
    ClapTrap claptrap2("CLTP2");

    claptrap1.attack("CLTP2");
    claptrap2.takeDamage(0);

    claptrap1.attack("CLTP2");

    claptrap1.beRepaired(5);
    claptrap1.attack("CLTP2");

    claptrap2.beRepaired(90);
    claptrap2.takeDamage(80);

    claptrap2.attack("CLTP1");
    claptrap2.attack("CLTP1");
    claptrap2.attack("CLTP1");

    return 0;

}