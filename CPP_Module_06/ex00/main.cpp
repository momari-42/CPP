/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:10:44 by momari            #+#    #+#             */
/*   Updated: 2024/11/07 15:18:55 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) {
    if ( ac != 2 ) {
        std::cout << "Error: Invalid arguments" << std::endl;
        return (1);
    }
    ScalarConverter::convert (av[1]);
    return (0);
}