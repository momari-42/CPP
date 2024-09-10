/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:53:51 by momari            #+#    #+#             */
/*   Updated: 2024/09/10 10:40:10 by momari           ###   ########.fr       */
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

// The new constructors and member functions

Fixed::Fixed( const int num ) {
    std::cout << "Int constructor called";
    std::cout << std::endl;
    this->fixedPointNumber = num * 256;
}

Fixed::Fixed( const float num ) {
    std::cout << "Float constructor called";
    std::cout << std::endl;
    this->fixedPointNumber = num * 256;
}

float Fixed::toFloat( void ) const {
    return (this->fixedPointNumber / 265.0);
}

int Fixed::toInt( void ) const {
    return (this->fixedPointNumber / 256);
}

Fixed Fixed::operator+( const Fixed& f1 ) {
    return (this->getRawBits() + f1.getRawBits());
}