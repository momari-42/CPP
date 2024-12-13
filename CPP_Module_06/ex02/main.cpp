/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:20:10 by momari            #+#    #+#             */
/*   Updated: 2024/11/09 15:18:09 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main() {
    {
        // Test for identify Pointer
        try {

            Base* basePointer = generate();
            identify(basePointer);
            delete basePointer;

        } 
        catch (const std::exception e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    {
        // Test for identify Reference
        try {

            Base& baseReference = *generate();
            identify(baseReference);
            delete &baseReference;

        } 
        catch (const std::exception e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}