/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:41:42 by momari            #+#    #+#             */
/*   Updated: 2024/11/04 16:02:00 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm ( void ) : AForm ("target", 1, 1) {

}

RobotomyRequestForm::RobotomyRequestForm ( std::string target ) : AForm(target, SIGN_RO, EXEC_RO) {
}

RobotomyRequestForm::RobotomyRequestForm ( const RobotomyRequestForm& copy ) : AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute()) {
}

RobotomyRequestForm& RobotomyRequestForm::operator= ( const RobotomyRequestForm& other ) {
    (void)other;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm ( void ) {
}

void RobotomyRequestForm::execute( Bureaucrat const & executor ) const {
    if (getSign() == false || executor.getGrade() > getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }
    std::srand(std::time(NULL));
    int randomNumber = rand () % 2;
    if (randomNumber) {
        std::cout << getName() << " has been robotomized successfully" << std::endl;
    } else {
        std::cout << getName() << " robotomy failed" << std::endl;
    }
}
