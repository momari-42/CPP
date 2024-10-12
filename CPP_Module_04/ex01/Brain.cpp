/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:10:12 by momari            #+#    #+#             */
/*   Updated: 2024/10/10 08:54:10 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ) {
    std::cout << "Brain Default constructor called";
    std::cout << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain Copy constructor called";
    std::cout << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain Copy assignment operator called";
    std::cout << std::endl;
    for (size_t i = 0; i < 100; i++) {
        this->ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain( void ) {
    std::cout << "Brain Destructor called";
    std::cout << std::endl;
}