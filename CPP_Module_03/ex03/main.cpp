/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:03:08 by momari            #+#    #+#             */
/*   Updated: 2024/10/05 15:20:12 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
    DiamondTrap d1("Diamond--1");
    DiamondTrap d2("Diamond--2");

    d1.attack("Diamond--2");
    d2.takeDamage(50);
    d1.attack("Diamond--2");
    d2.takeDamage(50);
    d2.attack("Diamond--1");
    d1.takeDamage(100);

    d1.whoAmI();
    return 0; 
}