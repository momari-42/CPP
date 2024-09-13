/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:53:51 by momari            #+#    #+#             */
/*   Updated: 2024/09/13 11:43:44 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "1" << std::endl;
    this->fixedPointNumber = 0;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "2" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "3" << std::endl;
    this->fixedPointNumber = ((other.fixedPointNumber / 256.0) * 256);
    return *this;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits( void ) const {
    std::cout << "4" << std::endl;
    return (this->fixedPointNumber / 256);
}

void Fixed::setRawBits( int const raw ) {
    std::cout << "5" << std::endl;
    this->fixedPointNumber = raw;
}

// The new constructors and member functions

Fixed::Fixed( const int num ) {
    std::cout << "6" <<  std::endl;
    this->fixedPointNumber = (num * 256);
}

Fixed::Fixed( const float num ) {
    std::cout << "7" << std::endl;
    this->fixedPointNumber = roundf(num * 256);
}

float Fixed::toFloat( void ) const {
    std::cout << "8" << std::endl;
    return (this->fixedPointNumber / 256.0);
}

int Fixed::toInt( void ) const {
    std::cout << "9" << std::endl;
    return (roundf(this->fixedPointNumber / 256) );
}

std::ostream& operator<<( std::ostream& out, const Fixed& fixed) {
    std::cout << "10" << std::endl;
    out << fixed.toFloat();
    return (out);
}

int Fixed::operator>( const Fixed& fixedTwo) {
    std::cout << "11" << std::endl;
    return this->fixedPointNumber > fixedTwo.fixedPointNumber;
}

int Fixed::operator<( const Fixed& fixedTwo) {
    std::cout << "12" << std::endl;
    return this->fixedPointNumber < fixedTwo.fixedPointNumber;
}

int Fixed::operator>=( const Fixed& fixedTwo) {
    std::cout << "13" << std::endl;
    return this->fixedPointNumber >= fixedTwo.fixedPointNumber;
}

int Fixed::operator<=( const Fixed& fixedTwo) {
    std::cout << "14" << std::endl;
    return this->fixedPointNumber <= fixedTwo.fixedPointNumber;
}

int Fixed::operator==( const Fixed& fixedTwo) {
    std::cout << "15" << std::endl;
    return this->fixedPointNumber == fixedTwo.fixedPointNumber;
}

int Fixed::operator!=( const Fixed& fixedTwo) {
    std::cout << "16" << std::endl;
    return this->fixedPointNumber != fixedTwo.fixedPointNumber;
}

Fixed Fixed::operator+( const Fixed& fixedTwo) {
    std::cout << "17" << std::endl;
    return ( float((this->fixedPointNumber + fixedTwo.fixedPointNumber) / 256.0) );
}

Fixed Fixed::operator-( const Fixed& fixedTwo) {
    std::cout << "18" << std::endl;
    return ( float((this->fixedPointNumber - fixedTwo.fixedPointNumber) / 256.0) );
}

Fixed Fixed::operator*( const Fixed& fixedTwo) {
    std::cout << "19" << std::endl;
    return ( float((this->fixedPointNumber / 256.0) * (fixedTwo.fixedPointNumber / 256.0)) );
}

Fixed Fixed::operator/( const Fixed& fixedTwo ) {
    std::cout << "20" << std::endl;
    if ((fixedTwo.fixedPointNumber / 256.0) != 0)
        return ( float((this->fixedPointNumber / 256.0) / (fixedTwo.fixedPointNumber / 256.0)) );
    return (0);
}

Fixed& Fixed::operator++( void ) {
    std::cout << "21 " << std::endl;
    ++fixedPointNumber ;
    return (*this);
}

Fixed& Fixed::operator--( void ) {
    std::cout << "22 " << std::endl;
    --fixedPointNumber ;
    return (*this);
}

Fixed Fixed::operator++( int ) {
    std::cout << "23 " << std::endl;
    Fixed temp (*this);
    ++(*this);
    return (temp);
}

Fixed Fixed::operator--( int ) {
    std::cout << "24 " << std::endl;
    Fixed temp (*this);
    --(*this);
    return (temp);
}

Fixed& Fixed::max ( Fixed& fixedOne, Fixed& fixedTwo ) {
    std::cout << "25 " << std::endl;
    return ( fixedOne > fixedTwo ? fixedOne : fixedTwo );
}

const Fixed& Fixed::max ( const Fixed& fixedOne, const Fixed& fixedTwo ) {
    std::cout << "26 " << std::endl;
    return ( fixedOne.fixedPointNumber > fixedTwo.fixedPointNumber ? fixedOne : fixedTwo );
}
Fixed& Fixed::min ( Fixed& fixedOne, Fixed& fixedTwo ) {
    std::cout << "27 " << std::endl;
    return ( fixedOne < fixedTwo ? fixedOne : fixedTwo );
}

const Fixed& Fixed::min ( const Fixed& fixedOne, const Fixed& fixedTwo ) {
    std::cout << "28 " << std::endl;
    return ( fixedOne.fixedPointNumber < fixedTwo.fixedPointNumber ? fixedOne : fixedTwo );
}