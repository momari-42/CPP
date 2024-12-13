/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:41:40 by momari            #+#    #+#             */
/*   Updated: 2024/11/04 15:57:37 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

#define SIGN_PR 25
#define EXEC_PR 5

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