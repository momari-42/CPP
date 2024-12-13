/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:41:12 by momari            #+#    #+#             */
/*   Updated: 2024/12/05 17:21:53 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    try {
        if (ac != 2)
            throw std::invalid_argument("Invalid Argument");
        BitcoinExchange bitcoinExchange;
        bitcoinExchange.bitcoinExchange(av[1]);
    }
    catch ( const std::exception& e ) {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
    return (0);
}