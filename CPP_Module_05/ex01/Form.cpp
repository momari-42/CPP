/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:38:14 by momari            #+#    #+#             */
/*   Updated: 2024/11/04 14:44:15 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form ( void ) : gradeToSign(1) , gradeToExecute(1) { }

Form::Form ( const std::string name, const int gradeToSign, const int gradeToExecute ) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    sign = false;
    if ( gradeToSign > 150 || gradeToExecute > 150 ) {
        throw Form::GradeTooLowException();
    } else if ( gradeToSign < 1 || gradeToExecute < 1 ) {
        throw Form::GradeTooHighException();
    }
}

Form::Form ( const Form& form ) : name(form.name), gradeToSign(form.gradeToSign), gradeToExecute(form.gradeToExecute) {
    this->sign = form.sign;
}

Form& Form::operator= ( const Form& form ) {
    this->sign = form.sign;
    return (*this);
}

Form::~Form ( void ) { }

std::string Form::getName ( void ) const {
    return (this->name);
}

int Form::getGradeToSign ( void ) const {
    return (this->gradeToSign);
}

int Form::getGradeToExecute ( void ) const {
    return (this->gradeToExecute);
}

bool Form::getSign ( void ) const {
    return (this->sign);
}

const char* Form::GradeTooHighException::what ( ) const throw() {
    return ("Too High");
}

const char* Form::GradeTooLowException::what ( void ) const throw()  {
    return ("Too Low");
}

std::ostream& operator<< ( std::ostream& out, const Form& form ) {
    out << form.getName() << ": Signed: " << form.getSign() << ", Grade Required to Sign: " << form.getGradeToSign() << ", Grade Required to Execute: " << form.getGradeToExecute() << std::endl;
    return (out);
}

void Form::beSigned( const Bureaucrat& bureaucrat ) {
    if ( bureaucrat.getGrade() > this->gradeToSign ) {
        throw Form::GradeTooLowException();
    }
    sign = true;
}