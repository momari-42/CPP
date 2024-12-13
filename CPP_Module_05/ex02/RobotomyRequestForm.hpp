/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:41:44 by momari            #+#    #+#             */
/*   Updated: 2024/11/04 15:58:12 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

#define SIGN_RO 72
#define EXEC_RO 45

class RobotomyRequestForm : public AForm {
    private:
        RobotomyRequestForm ( void );

    public:
        RobotomyRequestForm ( std::string target );
        RobotomyRequestForm ( const RobotomyRequestForm& copy );
        RobotomyRequestForm& operator= ( const RobotomyRequestForm& other );
        ~RobotomyRequestForm ( void );
        void execute(Bureaucrat const & executor) const;
};