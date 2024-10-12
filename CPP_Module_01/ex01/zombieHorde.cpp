/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 22:23:20 by momari            #+#    #+#             */
/*   Updated: 2024/09/25 08:14:03 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){

    if (N <= 0) {
        return (NULL);
    }
    Zombie* myZombie = new Zombie [N];
    if (!myZombie) {
        return (NULL); 
    }
    for (int i = 0; i < N; i++) {
        myZombie[i].setName( name );
    }
    return (myZombie);
}