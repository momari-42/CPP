/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:22:59 by momari            #+#    #+#             */
/*   Updated: 2024/11/04 14:36:24 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main ()
{
    try {
        // Bureaucrat bureaucrat ( "bureaucrat1", 150 );
        // std::cout << bureaucrat;
        // bureaucrat.incrementGrade();
        // std::cout << bureaucrat;
        // bureaucrat.decrementGrade();
        // std::cout << bureaucrat;
        // bureaucrat.decrementGrade();

        // Bureaucrat bureaucrat ( "bureaucrat1", 0 );

        Bureaucrat bureaucrat ( "bureaucrat1", 2 );
        std::cout << bureaucrat;
        bureaucrat.incrementGrade();
        std::cout << bureaucrat;
        bureaucrat.decrementGrade();
        std::cout << bureaucrat;
        bureaucrat.decrementGrade();
    }
    catch ( std::exception& e) {
        std::cout << "Exception Error: Grade " << e.what() << std::endl;
    }
    
}