/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:22:59 by momari            #+#    #+#             */
/*   Updated: 2024/11/04 20:45:00 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main ()
{
    try {
        Bureaucrat bureaucrat("momari", 10);
        ShrubberyCreationForm shrubbery_01("sh01");
        bureaucrat.signForm(shrubbery_01);
        shrubbery_01.execute(bureaucrat);
    }
    catch ( std::exception& e) {
        std::cout << "Exception Error: Grade " << e.what() << std::endl;
    }



    try {
        Bureaucrat bureaucrat("momari", 1);
        PresidentialPardonForm presidential ("pr01");
        bureaucrat.signForm(presidential);
        presidential.execute(bureaucrat);
    }
    catch ( std::exception& e) {
        std::cout << "Exception Error: Grade " << e.what() << std::endl;
    }

    try {
        Bureaucrat bureaucrat("momari", 1);
        RobotomyRequestForm robot ("robot");
        bureaucrat.signForm(robot);
        robot.execute(bureaucrat);
    }
    catch ( std::exception& e) {
        std::cout << "Exception Error: Grade " << e.what() << std::endl;
    }
    
}