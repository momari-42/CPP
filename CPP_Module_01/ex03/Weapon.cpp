/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:56:15 by momari            #+#    #+#             */
/*   Updated: 2024/09/01 13:00:49 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon () {
}

Weapon::Weapon ( std::string type ) {
    this->type = type;
}

std::string Weapon::getType() const {
    return (this->type);
}

void Weapon::setType( std::string type ) {
    this->type = type;
}