/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:56:27 by momari            #+#    #+#             */
/*   Updated: 2024/09/01 12:59:29 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA ( std::string name, Weapon &weapon ) : name(name), weapon(weapon){
}

void HumanA::attack () {
    std::cout << this->name;
    std::cout << " attacks with their ";
    std::cout << this->weapon.getType();
    std::cout << std::endl;
}