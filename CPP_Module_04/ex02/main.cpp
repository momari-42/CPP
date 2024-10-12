/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 11:24:03 by momari            #+#    #+#             */
/*   Updated: 2024/10/08 17:19:05 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{

    // Create an array of pointers to cat and allocat each pointer
    Cat* cats[5];
    for (size_t i = 0; i < 5; i++) {
        cats[i] = new Cat();
    }
    

    // Create an array of pointers to dog and allocat each pointer
    Dog* dogs[5];
    for (size_t i = 0; i < 5; i++) {
        dogs[i] = new Dog();
    }

    Animal* animals[10];
    for (size_t i = 0; i < 5; i++) {
        animals[i] = cats[i];
    }
    for (size_t i = 5; i < 10; i++) {
        animals[i] = dogs[i - 5];
    }

    for (size_t i = 0; i < 10; i++) {
        delete animals[i];
    }

    // Main of subject.
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();

    // delete j;//should not create a leak
    // delete i;

    return 0;
}