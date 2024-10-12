/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:03:03 by momari            #+#    #+#             */
/*   Updated: 2024/10/05 14:21:48 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap ( void ) : hitPoints (10), energyPoints (10), attackDamage (0) {
    std::cout << "Default constructor with parametre called" << std::endl;
}

ClapTrap::ClapTrap ( std::string name ) : name (name), hitPoints (10), energyPoints (10), attackDamage (0) {
    std::cout << "Default constructor with parametre called" << std::endl;
}

ClapTrap::ClapTrap ( const ClapTrap& clapTrap ) {
    std::cout << "Copy constructor called";
    std::cout << std::endl;
    (*this) = clapTrap;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& clapTrap ) {
    std::cout << "Copy assignment operator called";
    std::cout << std::endl;
    name = clapTrap.name;
    hitPoints = clapTrap.hitPoints;
    energyPoints = clapTrap.energyPoints;
    attackDamage = clapTrap.attackDamage;
    return (*this);
}

void ClapTrap::attack ( const std::string& target ) {
    if (!hitPoints || !energyPoints) {
        std::cout << "ClapTrap " << this->name << " can't attack " << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " attack " << target;
    std::cout << ", cusing " << attackDamage << " points of damage!" << std::endl;
    energyPoints--;
}

void ClapTrap::takeDamage ( unsigned int amount ) {
    if (!hitPoints || hitPoints < amount)
    {
        std::cout << "ClapTrap " << this->name << " can't takes damage!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!";
    hitPoints -= amount;
    std::cout << " Hit points left: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired( unsigned int amount ) {
    if (!energyPoints) {
        std::cout << "ClapTrap " << name << " can't repairs itself for " << amount << " hit points!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << name << " repairs itself for " << amount << " hit points!";
    hitPoints += amount;
    energyPoints--;
    std::cout << " Current health: " << hitPoints << std::endl;
}

std::string ClapTrap::getName ( void ) {
    return (name);
}


ClapTrap::~ClapTrap ( void ) {
    std::cout << "Destructor called";
    std::cout << std::endl;
}