/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:22:59 by momari            #+#    #+#             */
/*   Updated: 2024/11/04 17:42:51 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
    try {
        Bureaucrat bureaucrat ( "momari", 2 );
        Form form("Form_01", 10, 10);
        
        // form.beSigned(bureaucrat);
        bureaucrat.signForm (form);
        // bureaucrat.signForm("form1", false);
    }
    catch ( std::exception& e) {
        std::cout << "Exception Error: Grade " << e.what() << std::endl;
    }
    
}