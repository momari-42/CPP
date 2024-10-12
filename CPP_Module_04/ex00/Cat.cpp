/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 11:27:50 by momari            #+#    #+#             */
/*   Updated: 2024/10/10 08:42:25 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
    std::cout << "Cat Default constructor called";
    std::cout << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat Copy constructor called";
    std::cout << std::endl;
    *this = other;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat Copy assignment operator called";
    std::cout << std::endl;
    Animal::operator=(other);
    this->type = other.type;
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat Destructor called";
    std::cout << std::endl;
}

void Cat::makeSound( void ) const {
    std::cout << type << " says " << "moew." << std::endl;
}