/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:22:57 by momari            #+#    #+#             */
/*   Updated: 2024/11/04 14:31:01 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
    private:
        const   std::string name;
        Bureaucrat ( void );
        int     grade;
    public:
        class GradeTooHighException : public std::exception {
            public:
                const char* what ( ) const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what ( void ) const throw();
        };
        Bureaucrat ( std::string name,  int grade );
        Bureaucrat ( const Bureaucrat& bureaucrat );
        ~Bureaucrat ( void );
        const std::string getName ( void ) const;
        int getGrade ( void ) const;
        void incrementGrade ( void );
        void decrementGrade ( void );
        Bureaucrat& operator=( const Bureaucrat& bureaucrat );
};

std::ostream& operator<<(std::ostream& out,  const Bureaucrat& bureaucrat );

#endif