/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:36:45 by momari            #+#    #+#             */
/*   Updated: 2024/09/26 11:52:15 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


static float areaOfTriangle( Point const a, Point const b, Point const c ) {
    float area;

    area = (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())) + \
            (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())) + \
            (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()));
    if (area < 0)
        area *= -1;
    return (area /= 2);
}


bool bsp( Point const a, Point const b, Point const c, Point const point ) {
    float area, area1, area2, area3;

    area = areaOfTriangle(a, b, c);
    area1 = areaOfTriangle(a, b, point);
    area2 = areaOfTriangle(a, point, c);
    area3 = areaOfTriangle(point, b, c);

    if (!area1 || !area2 || !area3)
        return (false);
    if (area1 + area2 + area3 == area)
        return (true);
    return (false);
}