/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:53:48 by momari            #+#    #+#             */
/*   Updated: 2024/09/26 20:56:20 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixedPointNumber;
        static const int numberOfFructional = 8;
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        // The new constructors and member functions

        Fixed( const int num );
        Fixed( const float num );
        float toFloat( void ) const;
        int toInt( void ) const;
        int operator>( const Fixed& fixedTwo ); //check 
        int operator<( const Fixed& fixedTwo ) const; //+1
        int operator>=( const Fixed& fixedTwo ); //+1
        int operator<=( const Fixed& fixedTwo ); //+1
        int operator==( const Fixed& fixedTwo ); //+1
        int operator!=( const Fixed& fixedTwo ); //+1
        Fixed operator+( const Fixed& fixedTwo ); //+1
        Fixed operator-( const Fixed& fixedTwo ); //+1
        Fixed operator*( const Fixed& fixedTwo );//+1
        Fixed operator/( const Fixed& fixedTwo );//+1
        Fixed& operator++( void );
        Fixed operator++( int );
        Fixed& operator--( void );
        Fixed operator--( int );
        static Fixed& max(  Fixed& fixedOne,  Fixed& fixedTwo);
        static const Fixed& max( const Fixed& fixedOne, const Fixed& fixedTwo);
        static Fixed& min(  Fixed& fixedOne,  Fixed& fixedTwo);
        static const Fixed& min( const Fixed& fixedOne, const Fixed& fixedTwo);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif