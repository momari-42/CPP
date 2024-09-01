/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:28:41 by momari            #+#    #+#             */
/*   Updated: 2024/09/01 10:38:53 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string name = "HI THIS IS BRAIN";
    std::string* namePtr = &name;
    std::string& nameRef = name;

    std::cout << "The memory address of the name variable : " << &name <<  std::endl;
    std::cout << "The memory address held by namePtr      : " << &namePtr << std::endl;
    std::cout << "The memory address held by nameRef      : " << &nameRef << std::endl;

    std::cout << "The value of the string variable        : " << name << std::endl;
    std::cout << "The value pointed to by namePtr         : " << *namePtr << std::endl;
    std::cout << "The value pointed to by nameRef         : " << nameRef << std::endl;
}