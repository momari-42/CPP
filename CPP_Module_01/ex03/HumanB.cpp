/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:56:22 by momari            #+#    #+#             */
/*   Updated: 2024/09/01 13:18:48 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB ( std::string name ) : weapon(NULL) {
    this->name = name;
}

void HumanB::setWeapon ( Weapon &weapon ) {
    this->weapon = &weapon;
}

void HumanB::attack () {
    // <name> attacks with their <weapon type>
    std::cout << this->name;
    std::cout << " attacks with their ";
    std::cout << (*weapon).getType();
    std::cout << std::endl;
}