/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 22:23:15 by momari            #+#    #+#             */
/*   Updated: 2024/09/01 10:17:44 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
    std::cout << "newZombie";
    std::cout << " is created.";
    std::cout << std::endl;
}

Zombie::~Zombie() {
    std::cout << name;
    std::cout << " is destroyed.";
    std::cout << std::endl;
}

void Zombie::announce( void ) {
    std::cout << this->name;
    std::cout << ": BraiiiiiiinnnzzzZ...";
    std::cout << std::endl;
}

void Zombie::setName ( std::string name ) {
    this->name = name;
}