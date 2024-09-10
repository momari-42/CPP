/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:36:35 by momari            #+#    #+#             */
/*   Updated: 2024/09/03 14:48:29 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "Error: Please provide exactly One of this four arguments: DEBUG INFO WARNING ERROR";
        std::cout << std::endl;
        return (1);
    }
    Harl harl;

    harl.complain(av[1]);
}