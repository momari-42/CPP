/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:10:41 by momari            #+#    #+#             */
/*   Updated: 2024/11/07 14:11:24 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

class ScalarConverter {
    private:
        ScalarConverter ( void );

    public:
        ~ScalarConverter ( void );
        ScalarConverter ( const ScalarConverter& scalarConverter );
        ScalarConverter& operator= ( const ScalarConverter& scalarConverter );
        static void convert ( const std::string input );

};