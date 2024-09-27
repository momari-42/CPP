/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:05:43 by momari            #+#    #+#             */
/*   Updated: 2024/09/26 11:03:51 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
    private:
        const Fixed x;
        const Fixed y;
    public:
        Point( void );
        Point ( const float num1, const float num2 );
        Point ( const Point& other );
        Point& operator=( const Point& other );
        ~Point( void );

        const Fixed getX( void ) const;
        const Fixed getY( void ) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point );

# endif