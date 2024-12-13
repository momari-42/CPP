/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:07:05 by momari            #+#    #+#             */
/*   Updated: 2024/12/02 09:00:32 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    std::vector<int> vec;
    std::deque<int> deq;

    try {
        if ( ac < 2 )
            throw std::invalid_argument("invalid argument");
        fillContainers(av, vec, deq);
        PmergeMe pmergeMe (vec, deq);
        pmergeMe.mergeInsertSort( );
    }
    catch ( const std::exception& e ) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}