/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:43:10 by momari            #+#    #+#             */
/*   Updated: 2024/11/09 15:18:41 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
    int index;

    Base *base[4] = {
        new A(),
        new B(),
        new C()
    };
    std::srand(std::time(NULL));
    index = std::rand() % 3;
    for (int i = 0; i < 3; i++) {
        if ( i != index) {
            delete base[i];
            base[i] = NULL;
        }
    }
    return (base[index]);
}