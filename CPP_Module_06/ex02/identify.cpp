/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:43:13 by momari            #+#    #+#             */
/*   Updated: 2024/11/08 22:07:58 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base* p) {

    std::string type;

    type =  (dynamic_cast<A *>(p)) ? "A" : type;
    type =  (dynamic_cast<B *>(p)) ? "B" : type;
    type =  (dynamic_cast<C *>(p)) ? "C" : type;

    std::cout << "Base pointer is prointed to " << type << std::endl;
}

void identify(Base& p) {

    std::string type;
    try {
        (void)dynamic_cast<A &>(p);
        type = "A";
    }
    catch (const std::exception& e) {}
    try {
        (void)dynamic_cast<B &>(p);
        type = "B";
    }
    catch (const std::exception& e) {}
    try {
        (void)dynamic_cast<C &>(p);
        type = "C";
    }
    catch (const std::exception& e) {}
    std::cout << "Base pointer is prointed to " << type << std::endl;
}