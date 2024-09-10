/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:40:02 by momari            #+#    #+#             */
/*   Updated: 2024/09/07 12:00:29 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"


static int validateString(std::string str)
{
    int i;

    i = 0;
    if (str.empty())
        return (0);
    while (i < (int)str.length())
    {
        if (isalpha(str[i]))
            return (1);
        i++;
    }
    return (0);
}

static int  validatePhoneNumber(std::string str)
{
    int i;

    i = 0;
    if (str.empty())
        return (0);
    if (str[0] == '+')
        i++;
    while (i < (int)str.length())
    {
        if (!isnumber(str[i]))
            return (0);
        i++;
    }
    if (i > 13 || i < 6)
        return (0);
    return (1);
}

static std::string getUserStrings(std::string prompt)
{
    std::string line;

    while (!validateString(line))
    {
        std::cout << prompt;
        if (std::getline(std::cin, line).eof())
            exit(0);
    }
    return (line);
}


static std::string getUserPhoneNumber(std::string prompt)
{
    std::string line;

    while (!validatePhoneNumber(line))
    {
        std::cout << prompt;
        if (std::getline(std::cin, line).eof())
            exit(0);
    }
    return (line);
}

static std::string getUserDarkestSecrete(std::string prompt)
{
    std::string line;

    while (line.empty())
    {
        std::cout << prompt;
        if (std::getline(std::cin, line).eof())
            exit(0);
    }
    return (line);
}


static std::string readLine(std::string prompt, int n)
{
    std::string line;

    if (n == 0)
        line = getUserStrings(prompt);
    else if (n == 1)
        line = getUserPhoneNumber(prompt);
    else
        line = getUserDarkestSecrete(prompt);
    return (line);
}

void PhoneBook::addContact()
{
    std::string     line;
    static int      n;

    std::cout << "   you are in ADD mode" << std::endl;
    line = readLine("      Enter your name: ", 0);
    contact[n].setFirstName(line);
    line = readLine("      Enter your last name: ", 0);
    contact[n].setLastName(line);
    line = readLine("      Enter your nick name: ", 0);
    contact[n].setNickName(line);
    line = readLine("      Enter your phone number: ", 1);
    contact[n].setPhoneNumber(line);
    line = readLine("      Enter your darkest secrete: ", 2);
    contact[n++].setDarkestSecrete(line);
    if (n == 8)
        n = 0;
}

static void displayString(std::string str)
{
    int i;
    int len;

    i = 0;
    len = (int)str.length();
    if (len < 10)
    {
        std::cout << str;
        while (len < 10)
        {
            std::cout << " ";
            len++;
        }
    }
    else
    {
        while (i < 9)
        {
            std::cout << str[i];
            i++;
        }
        std::cout << ".";
    }
    std::cout << "|";
}

void PhoneBook::displaySavedContacts()
{
    int n;

    n = 0;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|index     |first name|last name |nickname  |" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    while (n < 8)
    {
        if (contact[n].getFirstName().length())
        {
            std::cout << "|" << n + 1 << "         |";
            displayString(contact[n].getFirstName());
            displayString(contact[n].getLastName());
            displayString(contact[n].getNickName());
            std::cout << std::endl;
            std::cout << "---------------------------------------------" << std::endl;
        }
        else
            break;
        n++;
    }
}


static int readIndex(std::string prompt)
{
    std::string line;

    while (line.empty())
    {
        std::cout << prompt;
        if (std::getline(std::cin, line).eof())
            exit(0);
    }
    if (line.length() == 1 && (line[0] >= '1' && line[0] <= '8'))
        return ((int)line[0] - '0');
    return (-1);
}

void PhoneBook::searshForSavedContacts()
{
    int index;

    index = readIndex("    Please enter the index of the contact you'd like to display: ");
    if (index == -1) {
        std::cout << "        🚨You inter invalid index🚨" ;
        std::cout << std::endl ;
        return ;
    }
    index--;
    if (contact[index].getFirstName().length() == 0) {
        std::cout << "        🚨This contact is empty🚨" ;
        std::cout << std::endl ;
        return ;
    }
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|index     |first name|last name |nickname  |" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|" << index + 1 << "         |";
    displayString(contact[index].getFirstName());
    displayString(contact[index].getLastName());
    displayString(contact[index].getNickName());
    std::cout << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
}

void PhoneBook::searchContact()
{
    displaySavedContacts();
    searshForSavedContacts();
}