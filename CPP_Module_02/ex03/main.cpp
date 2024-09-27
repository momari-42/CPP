/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:53:53 by momari            #+#    #+#             */
/*   Updated: 2024/09/26 20:48:03 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) {
    Point a(6.88155, -5.1464);
    Point b(6.41679, -5.31803);
    Point c(6.4821, -4.81378);
    Point d(6.4821, -4.81378);

    if (bsp (a, b, c, d))
        std::cout << "the point is <<in>> the triangle" << std::endl;
    else
        std::cout << "the point is <<out>> the triangle" << std::endl;
}