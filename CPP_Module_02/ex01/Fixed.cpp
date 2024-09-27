/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:53:51 by momari            #+#    #+#             */
/*   Updated: 2024/09/26 20:57:02 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    fixedPointNumber = 0;
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
    fixedPointNumber = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called";
    std::cout << std::endl;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called";
    std::cout << std::endl;
    return (fixedPointNumber);
}

void Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called";
    std::cout << std::endl;
    fixedPointNumber = raw;
}

// The new constructors and member functions

Fixed::Fixed( const int num ) {
    std::cout << "Int constructor called";
    std::cout << std::endl;
    fixedPointNumber = num << numberOfFructional;
}

Fixed::Fixed( const float num ) {
    std::cout << "Float constructor called";
    std::cout << std::endl;
    fixedPointNumber = roundf(num * (1 << numberOfFructional));
}

float Fixed::toFloat( void ) const {
    return (fixedPointNumber / (float)(1 << numberOfFructional));
}

int Fixed::toInt( void ) const {
    return (roundf(fixedPointNumber >> numberOfFructional));
}

std::ostream& operator<<( std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return (out);
}