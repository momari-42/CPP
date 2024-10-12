/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 11:24:03 by momari            #+#    #+#             */
/*   Updated: 2024/10/10 08:33:06 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongI = new WrongCat();

    std::cout << wrongI->getType() << " " << std::endl;

    wrongI->makeSound(); //will output the Animal sound!

    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongI;


    // --------------------------------------------------------------------------------------------------------------- // 
    // --------------------------------------------------------------------------------------------------------------- // 
    // --------------------------------------------------------------------------------------------------------------- // 


    // const Animal* meta = new Animal();
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();

    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;

    // i->makeSound(); //will output the cat sound!
    // j->makeSound();
    // meta->makeSound();

    // delete meta;
    // delete i;
    // delete j;

    return 0;
}