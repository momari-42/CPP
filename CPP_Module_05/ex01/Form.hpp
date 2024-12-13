/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
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

class Form {
    private:
        const std::string   name;
        const int           gradeToSign;
        const int           gradeToExecute;
        bool                sign;
        Form ( void );

    public:
        class GradeTooHighException : public std::exception {
            public:
                const char* what ( ) const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what ( void ) const throw();
        };
        Form ( const std::string name, const int gradeToSign, const int gradeToExecute );
        Form ( const Form& form );
        Form& operator= ( const Form& form );
        ~Form ( void );
        std::string getName ( void ) const;
        int getGradeToSign ( void ) const;
        int getGradeToExecute ( void ) const;
        bool getSign ( void ) const;
        void beSigned( const Bureaucrat& bureaucrat );
};

std::ostream& operator<<( std::ostream& out, const Form& form );