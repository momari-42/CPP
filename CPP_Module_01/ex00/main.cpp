/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:38:54 by momari            #+#    #+#             */
/*   Updated: 2024/09/25 08:09:58 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie* heapZombie = newZombie("Heap");
    heapZombie->announce();
    randomChump("Stack");


    // cleanup
    delete heapZombie;
}