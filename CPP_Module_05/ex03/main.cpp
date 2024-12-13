/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:22:59 by momari            #+#    #+#             */
/*   Updated: 2024/11/06 09:22:48 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main ()
{
    AForm*   rrf;
    try {
    {
        Bureaucrat bureaucrat("buro", 10);
        Intern  someRandomIntern;
        rrf = someRandomIntern.makeForm("shrubbery request", "Bender");
        bureaucrat.signForm (*rrf);
        rrf->execute( bureaucrat );
    }
        
    }
    catch ( std::exception& e) {
        std::cout << "Exception Error: Grade " << e.what() << std::endl;
    }
    if (rrf)
        delete rrf;
}