/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:41:49 by momari            #+#    #+#             */
/*   Updated: 2024/11/04 12:27:14 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"
#include <fstream>

#define SIGN_SH 145
#define EXEC_SH 137

class ShrubberyCreationForm : public AForm {
      private:
        ShrubberyCreationForm( void );

      public:
        ShrubberyCreationForm( std::string target );
        ShrubberyCreationForm ( const ShrubberyCreationForm& shrubberyCreationForm );
        ShrubberyCreationForm& operator= ( ShrubberyCreationForm& other );
        ~ShrubberyCreationForm( void );
        void execute(Bureaucrat const & executor) const;
};