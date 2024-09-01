/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:04:03 by momari            #+#    #+#             */
/*   Updated: 2024/09/01 14:22:17 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReplaceFile.hpp"

int main(int ac, char **av)
{
    if ( ac != 4 ) {
        std::cout << "Error: Please provide exactly three arguments: filename s1 s2";
        std::cout << std::endl;
        return (1);
    }
    replaceFile(av);
}