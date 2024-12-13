/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:37 by momari            #+#    #+#             */
/*   Updated: 2024/11/22 15:54:24 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <exception>

template <typename T>
void easyfind ( T type, int N ) {
    if (std::find(type.begin(), type.end(), N) == type.end())
        throw std::invalid_argument("Unfortunately, we couldn't find the number you were looking for.");
    std::cout << "Congratulations! We found the number you were looking for!" << std::endl;
}