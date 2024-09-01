/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:33:46 by momari            #+#    #+#             */
/*   Updated: 2024/08/29 08:56:33 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    int n;
    int i;

    n = 1;
    if (ac < 2)
    {
        std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl; 
        return (1);
    }
    while (av && av[n])
    {
        i = 0;
        while (av[n][i])
        {
            if (av[n][i] >= 'a' && av[n][i] <= 'z')
                std::cout << (char)toupper(av[n][i]);
            else
                std::cout << av[n][i];
            i++;
        }
        n++;
    }
    std::cout << std::endl;
    return (0);
}