/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:03:21 by momari            #+#    #+#             */
/*   Updated: 2024/12/06 11:47:10 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReversePolishNotation.hpp"

int main(int ac, char **av) {
    try {
        if ( ac != 2 )
            throw std::invalid_argument("Invalid argument");
        ReversePolishNotation Rpn;
        Rpn.RPN(av[1]);
    }
    catch ( const std::exception& e ) {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
}