/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:53:48 by momari            #+#    #+#             */
/*   Updated: 2024/09/10 10:39:31 by momari           ###   ########.fr       */
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
        Fixed operator+( const Fixed& f1);
};


#endif