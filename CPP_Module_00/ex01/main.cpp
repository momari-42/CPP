/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:06:59 by momari            #+#    #+#             */
/*   Updated: 2024/09/11 10:12:38 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string line;

    std::cout << "Welcome to Phonebook programme you have three commands" << std::endl;
    std::cout << "   ADD: save a new contact" << std::endl;
    std::cout << "   SEARCH: display a specific contact" << std::endl;
    std::cout << "   EXIT: the program quits" << std::endl;
    while (TRUE)
    {
        std::cout << "Enter command: ";
        std::getline(std::cin, line);
        if (std::cin.eof() || line == "EXIT")
            exit(0);
        if (line == "ADD")
            phoneBook.addContact();
        else if (line == "SEARCH")
            phoneBook.searchContact();
        else
            std::cout << "   Invalid command! Please enter 'ADD', 'SEARCH', or 'EXIT'." << std::endl;
        }
}