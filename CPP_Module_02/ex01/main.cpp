/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:53:53 by momari            #+#    #+#             */
/*   Updated: 2024/09/10 10:41:03 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {

    Fixed a(1);
    Fixed b(2);
    Fixed c = a + b;


    std::cout << c.getRawBits() / 256 / 256 << std::endl;

    // Fixed a;
    // Fixed const b( 10 );
    // Fixed const c( 42.42f );
    // Fixed const d( b );

    // a = Fixed( 1234.4321f );

    // std::cout << "a is " << a << std::endl;
    // std::cout << "b is " << b << std::endl;
    // std::cout << "c is " << c << std::endl;
    // std::cout << "d is " << d << std::endl;

    // std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    // std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    // std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    // std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;

}