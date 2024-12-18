/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:55:21 by momari            #+#    #+#             */
/*   Updated: 2024/09/11 10:12:27 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <string>

class PhoneBook
{
    private:
        Contact contact[8]; // when we defined a class in class this named "A nested class" and of course can be public of private or protected based on the needs of program
    public:
        void addContact();
        void searchContact();
        void displaySavedContacts();
        void searshForSavedContacts();

};


#endif