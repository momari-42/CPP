/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:53:53 by momari            #+#    #+#             */
/*   Updated: 2024/09/26 20:38:54 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {

    const Fixed a;
    Fixed b(5);
    std::cout << (a < b) << std::endl ;
    // Fixed const b( Fixed( 5 ) - Fixed( 1.5f ) );

    // std::cout << a << std::endl;
    // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;

    // std::cout << b << std::endl;

    // std::cout << Fixed::max( a, b ) << std::endl;

    return 0;
}