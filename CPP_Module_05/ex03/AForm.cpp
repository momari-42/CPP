/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:38:14 by momari            #+#    #+#             */
/*   Updated: 2024/11/03 10:38:41 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm ( void ) : gradeToSign(1) , gradeToExecute(1) { }

AForm::AForm ( const std::string name, const int gradeToSign, const int gradeToExecute ) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    sign = false;
    if ( gradeToSign > 150 || gradeToExecute > 150 ) {
        throw AForm::GradeTooLowException();
    } else if ( gradeToSign < 1 || gradeToExecute < 1 ) {
        throw AForm::GradeTooHighException();
    }
}

AForm::AForm ( const AForm& Aform ) : name(Aform.name), gradeToSign(Aform.gradeToSign), gradeToExecute(Aform.gradeToExecute) {
    this->sign = Aform.sign;
}

AForm& AForm::operator= ( const AForm& Aform ) {
    this->sign = Aform.sign;
    return (*this);
}

AForm::~AForm ( void ) { }

std::string AForm::getName ( void ) const {
    return (this->name);
}

int AForm::getGradeToSign ( void ) const {
    return (this->gradeToSign);
}

int AForm::getGradeToExecute ( void ) const {
    return (this->gradeToExecute);
}

bool AForm::getSign ( void ) const {
    return (this->sign);
}

const char* AForm::GradeTooHighException::what ( ) const throw() {
    return ("Too High");
}

const char* AForm::GradeTooLowException::what ( void ) const throw()  {
    return ("Too Low");
}

std::ostream& operator<< ( std::ostream& out, const AForm& aform ) {
    out << aform.getName() << ": Signed: " << aform.getSign() << ", Grade Required to Sign: " << aform.getGradeToSign() << ", Grade Required to Execute: " << aform.getGradeToExecute() << std::endl;
    return (out);
}

void AForm::beSigned( const Bureaucrat& bureaucrat ) {
    if ( bureaucrat.getGrade() > this->gradeToSign ) {
        throw AForm::GradeTooLowException();
    }
    sign = true;
}