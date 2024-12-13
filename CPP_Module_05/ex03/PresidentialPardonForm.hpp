/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:41:40 by momari            #+#    #+#             */
/*   Updated: 2024/11/04 12:26:34 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

#define SIGN_PRE 25
#define EXEC_PRE 5

class PresidentialPardonForm : public AForm {
    private:
        PresidentialPardonForm ( void );

    public:
        PresidentialPardonForm ( std::string target );
        PresidentialPardonForm ( const PresidentialPardonForm& copy );
        PresidentialPardonForm& operator= ( const PresidentialPardonForm& other );
        ~PresidentialPardonForm ( void );
        void execute(Bureaucrat const & executor) const;
};