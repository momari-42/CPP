/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:53:51 by momari            #+#    #+#             */
/*   Updated: 2024/09/09 08:34:23 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    this->fixedPointNumber = 0;
    std::cout << "Default constructor called";
    std::cout << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called";
    std::cout << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called";
    std::cout << std::endl;
    this->fixedPointNumber = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called";
    std::cout << std::endl;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called";
    std::cout << std::endl;
    return (this->fixedPointNumber);
}

void Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called";
    std::cout << std::endl;
    this->fixedPointNumber = raw;
}