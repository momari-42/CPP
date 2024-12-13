/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:21:36 by momari            #+#    #+#             */
/*   Updated: 2024/11/04 20:50:32 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ) {    
}

Intern::Intern ( const Intern& intern ) {
    *this = intern;
}

Intern& Intern::operator= ( const Intern& intern ) {
    (void)intern;
    return (*this);
}

Intern::~Intern( void ) {   
}

AForm* Intern::makeForm ( std::string name, std::string target ) {
    int         indexOfName = -1;
    std::string nameRequests[3];
    AForm*      forms[] = {new ShrubberyCreationForm(target) ,new PresidentialPardonForm(target) ,new RobotomyRequestForm(target)};
    nameRequests[0] = "shrubbery request";
    nameRequests[1] = "presidential request";
    nameRequests[2] = "robotomy request";
    for (int i = 0; i < 3; i++) {
        if ( nameRequests[i] == name ) {
            indexOfName = i;
            break;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (indexOfName != i) {
            delete forms[i];
            forms[i] = NULL;
        }
    }
	if (indexOfName == -1) {	
		std::cout << "Intern can't creates form" << std::endl;
		return (NULL);
	}
	std::cout << "Intern creates " << nameRequests[indexOfName] << std::endl;
    return (forms[indexOfName]);
}