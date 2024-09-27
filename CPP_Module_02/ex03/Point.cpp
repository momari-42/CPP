/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:49:37 by momari            #+#    #+#             */
/*   Updated: 2024/09/26 11:38:10 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "Point.hpp"

Point::Point( void ) : x(0) , y(0) {
}

Point::Point ( const float num1, const float num2 ) : x(num1) , y(num2) {
}

Point::Point ( const Point& other ) : x(other.getX()), y(other.getY()) {
}

Point& Point::operator=( const Point& other ){
    (Fixed)x = other.x;
    (Fixed)y = other.y;
    return (*this);
}

Point::~Point(){
}

const Fixed Point::getX( void ) const {
    return (x);
}
const Fixed Point::getY( void ) const {
    return (y);
}