/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:06:45 by momari            #+#    #+#             */
/*   Updated: 2024/10/04 11:36:24 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap ( void ) : ClapTrap () {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap ( std::string name ) : ClapTrap (name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::~ScavTrap ( void ) {
    std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap ( const ScavTrap& scavTrap ) : ClapTrap (scavTrap) {
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator= ( const ScavTrap& scavTrap ) {
    ClapTrap::operator=(scavTrap);
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    return (*this);
}

void ScavTrap::guardGate() {
    if (!energyPoints || !hitPoints) {
        return ;   
    }
    std::cout << "ScavTrap is now in Gatekeeper mode" << std::endl;
}

void ScavTrap::attack ( const std::string& target ) {
    if (!hitPoints || !energyPoints) {
        std::cout << "ScavTrap " << this->name << " can't attack " << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->name << " attack " << target;
    std::cout << ", cusing " << attackDamage << " points of damage!" << std::endl;
    energyPoints--;
}