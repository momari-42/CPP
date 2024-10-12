/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 11:23:58 by momari            #+#    #+#             */
/*   Updated: 2024/10/08 17:18:33 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal Default constructor called";
    std::cout << std::endl;
}

Animal::Animal(const Animal& other) {
    std::cout << "Animal Copy constructor called";
    std::cout << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal Copy assignment operator called";
    std::cout << std::endl;
    this->type = other.type;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal Destructor called";
    std::cout << std::endl;
}

std::string Animal::getType( void ) const {
    return (type);
}