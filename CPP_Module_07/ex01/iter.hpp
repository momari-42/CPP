/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:57:53 by momari            #+#    #+#             */
/*   Updated: 2024/11/16 19:50:50 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T, typename U>
void iter (T *array, size_t lenght, U f) {
    if ( array == NULL )
        return ;
    for (size_t i = 0; i < lenght; i++)
    {
        f(array[i]);
    }
}