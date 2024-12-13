/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:41:34 by momari            #+#    #+#             */
/*   Updated: 2024/11/04 17:20:23 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm ( void ) : AForm ("target", 1, 1) {
}

PresidentialPardonForm::PresidentialPardonForm ( std::string target ) : AForm(target, SIGN_PRE, EXEC_PRE) {
}

PresidentialPardonForm::PresidentialPardonForm ( const PresidentialPardonForm& copy ) : AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute()) {
}

PresidentialPardonForm& PresidentialPardonForm::operator= ( const PresidentialPardonForm& other ) {
    (void)other;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm ( void ) {
}

void PresidentialPardonForm::execute( Bureaucrat const & executor ) const {
    if (getSign() == false || executor.getGrade() > getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }
    std::cout << getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
