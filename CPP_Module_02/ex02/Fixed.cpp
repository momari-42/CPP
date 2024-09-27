/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:53:51 by momari            #+#    #+#             */
/*   Updated: 2024/09/26 20:39:18 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    fixedPointNumber = 0;
}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    fixedPointNumber = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits( void ) const {
    return (fixedPointNumber);
}

void Fixed::setRawBits( int const raw ) {
    fixedPointNumber = raw;
}

// The new constructors and member functions

Fixed::Fixed( const int num ) {
    fixedPointNumber = num << numberOfFructional;
}

Fixed::Fixed( const float num ) {
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

int Fixed::operator>( const Fixed& fixedTwo) {
    return (fixedPointNumber > fixedTwo.fixedPointNumber);
}

int Fixed::operator<( const Fixed& fixedTwo) const{
    return (fixedPointNumber < fixedTwo.fixedPointNumber);
}

int Fixed::operator>=( const Fixed& fixedTwo) {
    return (fixedPointNumber >= fixedTwo.fixedPointNumber);
}

int Fixed::operator<=( const Fixed& fixedTwo) {
    return (fixedPointNumber <= fixedTwo.fixedPointNumber);
}

int Fixed::operator==( const Fixed& fixedTwo) {
    return (fixedPointNumber == fixedTwo.fixedPointNumber);
}

int Fixed::operator!=( const Fixed& fixedTwo) {
    return (fixedPointNumber != fixedTwo.fixedPointNumber);
}

Fixed Fixed::operator+( const Fixed& fixedTwo) {
    Fixed result;

    result.setRawBits(this->getRawBits() + fixedTwo.getRawBits());
    return ( result );
}

Fixed Fixed::operator-( const Fixed& fixedTwo) {
    Fixed result;

    result.setRawBits(this->getRawBits() - fixedTwo.getRawBits());
    return ( result );
}

Fixed Fixed::operator*( const Fixed& fixedTwo) {
    Fixed result;

    result.setRawBits(this->toFloat() * fixedTwo.toFloat() * (1 << numberOfFructional));
    return ( result );
}

Fixed Fixed::operator/( const Fixed& fixedTwo ) {
    Fixed result;

    if (fixedTwo.getRawBits() != 0)
        result.setRawBits((this->toFloat() / fixedTwo.toFloat()) * (1 << numberOfFructional));
    return ( result );
}

Fixed& Fixed::operator++( void ) {
    ++fixedPointNumber ;
    return (*this);
}

Fixed& Fixed::operator--( void ) {
    --fixedPointNumber ;
    return (*this);
}

Fixed Fixed::operator++( int ) {
    Fixed temp (*this);
    ++(*this);
    return (temp);
}

Fixed Fixed::operator--( int ) {
    Fixed temp (*this);
    --(*this);
    return (temp);
}

Fixed& Fixed::max ( Fixed& fixedOne, Fixed& fixedTwo ) {
    return ( fixedOne > fixedTwo ? fixedOne : fixedTwo );
}

const Fixed& Fixed::max ( const Fixed& fixedOne, const Fixed& fixedTwo ) {
    return ( fixedOne.fixedPointNumber > fixedTwo.fixedPointNumber ? fixedOne : fixedTwo );
}
Fixed& Fixed::min ( Fixed& fixedOne, Fixed& fixedTwo ) {
    return ( fixedOne < fixedTwo ? fixedOne : fixedTwo );
}

const Fixed& Fixed::min ( const Fixed& fixedOne, const Fixed& fixedTwo ) {
    return ( fixedOne.fixedPointNumber < fixedTwo.fixedPointNumber ? fixedOne : fixedTwo );
}