/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 11:24:00 by momari            #+#    #+#             */
/*   Updated: 2024/10/10 08:26:59 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
    protected:
        std::string type;
    public:
        Animal( void );
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal();
        std::string getType ( void ) const;
        virtual void makeSound( void ) const;
};

#endif