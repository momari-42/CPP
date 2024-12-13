/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:04:09 by momari            #+#    #+#             */
/*   Updated: 2024/11/22 11:06:14 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
    try {
        {
            std::vector<int> integers;
            integers.push_back(1);
            integers.push_back(2);
            integers.push_back(3);
            integers.push_back(4);
            integers.push_back(5);
            integers.push_back(6);
            integers.push_back(7);
            easyfind(integers, 1);
        }
        {
            std::deque<int> floatNumbers;
            floatNumbers.push_back(9);
            floatNumbers.push_front(9);
            floatNumbers.push_back(19);
            floatNumbers.push_front(70);
            floatNumbers.push_back(100);
            floatNumbers.push_front(899);
            floatNumbers.push_back(10);
            easyfind(floatNumbers, 9);
        }
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}