/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 22:23:12 by momari            #+#    #+#             */
/*   Updated: 2024/09/01 10:23:47 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = -1;
    std::string name = "FoO";
    Zombie* newZombie = zombieHorde(N, name);
    for (int i = 0; i < N; i++) {
        newZombie[i].announce();
    }

    // cleanup
    delete [] newZombie;
}