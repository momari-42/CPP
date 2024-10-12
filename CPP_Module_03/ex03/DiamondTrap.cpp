/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:09:05 by momari            #+#    #+#             */
/*   Updated: 2024/10/05 14:51:40 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap ( void ) : ClapTrap(), ScavTrap(), FragTrap() {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 30;
    std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap ( std::string name ) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), name(name) {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 30;
    std::cout << "DiamondTrap Default constructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "I am ClapTrap " << ClapTrap::name << ", and my name is " << name << "." << std::endl;
}

DiamondTrap::DiamondTrap ( const DiamondTrap& diamondTrap ) {
    std::cout << "DiamondTrap Copy constructor called";
    std::cout << std::endl;
    (*this) = diamondTrap;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& diamondTrap ) {
    std::cout << "DiamondTrap Copy assignment operator called";
    std::cout << std::endl;
    ScavTrap::operator=(diamondTrap);
    FragTrap::operator=(diamondTrap);
    return (*this);
}

DiamondTrap::~DiamondTrap ( void ) {
    std::cout << "DiamondTrap Destructor called";
    std::cout << std::endl;
}


void DiamondTrap::attack ( const std::string& target ) {
    ScavTrap::attack(target);
}