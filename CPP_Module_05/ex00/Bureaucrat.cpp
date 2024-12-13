/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:22:53 by momari            #+#    #+#             */
/*   Updated: 2024/11/04 14:34:42 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat ( void ) {
}

Bureaucrat::Bureaucrat ( std::string name, int grade ) : name(name) {
    if ( grade < 1 ) {
        throw Bureaucrat::GradeTooHighException();
    } else if ( grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade = grade;
}

Bureaucrat::Bureaucrat ( const Bureaucrat& bureaucrat ) : name(bureaucrat.getName()) {
    (*this) = bureaucrat;
}

Bureaucrat& Bureaucrat::operator= ( const Bureaucrat& bureaucrat ) {
    this->grade = bureaucrat.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat ( void ) {
}

int Bureaucrat::getGrade ( void ) const {
    return (this->grade);
}

const std::string Bureaucrat::getName ( void ) const {
    return (this->name);
}

void Bureaucrat::incrementGrade ( void ) {
    if ( grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}
void Bureaucrat::decrementGrade ( void ) {
    if ( grade + 1 > 150 )
        throw Bureaucrat::GradeTooLowException();
    grade++;
}

std::ostream& operator<< ( std::ostream& out, const Bureaucrat& bureaucrat ) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return (out);
}

const char* Bureaucrat::GradeTooHighException::what ( ) const throw() {
    return ("Too High");
}
const char* Bureaucrat::GradeTooLowException::what ( void ) const throw()  {
    return ("Too Low");
}