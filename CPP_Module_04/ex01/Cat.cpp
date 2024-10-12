/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 11:27:50 by momari            #+#    #+#             */
/*   Updated: 2024/10/10 17:28:21 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) {
    std::cout << "Cat Default constructor called" << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat Copy constructor called";
    std::cout << std::endl;
    this->brain = NULL;
    *this = other;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat Copy assignment operator called";
    std::cout << std::endl;
    Animal::operator=(other);
    if ( this->brain )
        delete brain;
    this->brain = new Brain(*(other.brain));
    return *this;
}

Cat::~Cat( void ) {
    std::cout << "Cat Destructor called";
    std::cout << std::endl;
    delete brain;
}

void Cat::makeSound( void ) const {
    std::cout << type << " says " << "moew." << std::endl;
}