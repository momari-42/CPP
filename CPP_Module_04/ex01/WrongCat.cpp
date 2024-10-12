/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 11:27:50 by momari            #+#    #+#             */
/*   Updated: 2024/10/06 14:11:32 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    std::cout << "WrongCat Default constructor called";
    type = "WrongCat";
    std::cout << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat Copy constructor called";
    std::cout << std::endl;
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "WrongCat Copy assignment operator called";
    std::cout << std::endl;
    WrongAnimal::operator=(other);
    this->type = other.type;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat Destructor called";
    std::cout << std::endl;
}

void WrongCat::makeSound( void ) const {
    std::cout << type << " says " << "moew." << std::endl;
}