/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:36:50 by momari            #+#    #+#             */
/*   Updated: 2024/08/31 22:13:43 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ){
    this->name = name;
}

Zombie::~Zombie(){
    std::cout << name;
    std::cout << " is destroyed.";
    std::cout << std::endl;
}

void Zombie::announce( void ){
    std::cout << this->name;
    std::cout << ": BraiiiiiiinnnzzzZ...";
    std::cout << std::endl;
}