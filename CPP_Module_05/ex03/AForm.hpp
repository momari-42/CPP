/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:38:16 by momari            #+#    #+#             */
/*   Updated: 2024/11/02 15:39:41 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string   name;
        const int           gradeToSign;
        const int           gradeToExecute;
        bool                sign;
        AForm ( void );

    public:
        class GradeTooHighException : public std::exception {
            public:
                const char* what ( ) const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what ( void ) const throw();
        };
        AForm ( const std::string name, const int gradeToSign, const int gradeToExecute );
        AForm ( const AForm& aform );
        AForm& operator= ( const AForm& aform );
        virtual ~AForm ( void );
        std::string getName ( void ) const;
        int getGradeToSign ( void ) const;
        int getGradeToExecute ( void ) const;
        bool getSign ( void ) const;
        void beSigned( const Bureaucrat& bureaucrat );
        virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<( std::ostream& out, const AForm& aform );