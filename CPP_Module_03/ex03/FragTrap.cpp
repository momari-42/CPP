/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:41:08 by momari            #+#    #+#             */
/*   Updated: 2024/10/05 10:23:38 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap ( void ) : ClapTrap () {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap ( std::string name ) : ClapTrap (name) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::~FragTrap ( void ) {
    std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap ( const FragTrap& fragtrap ) : ClapTrap (fragtrap) {
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator= ( const FragTrap& fragtrap ) {
    ClapTrap::operator=(fragtrap);
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    return (*this);
}

void FragTrap::attack ( const std::string& target ) {
    if (!hitPoints || !energyPoints) {
        std::cout << "FragTrap " << this->name << " can't attack " << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->name << " attack " << target;
    std::cout << ", cusing " << attackDamage << " points of damage!" << std::endl;
    energyPoints--;
}

void FragTrap::highFivesGuys( void ) {
    std::cout << "FragTrap requests a high five! ✋ Let's celebrate with some high energy!" << std::endl;
}
