/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 11:27:55 by momari            #+#    #+#             */
/*   Updated: 2024/10/06 12:47:26 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
    std::cout << "Dog Default constructor called";
    std::cout << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog Copy constructor called";
    std::cout << std::endl;
    *this = other;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog Copy assignment operator called";
    std::cout << std::endl;
    Animal::operator=(other);
    this->type = other.type;
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog Destructor called";
    std::cout << std::endl;
}

void Dog::makeSound( void ) const {
    std::cout << type << " says " << "Woof." << std::endl;
}