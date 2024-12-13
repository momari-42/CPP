/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:10:39 by momari            #+#    #+#             */
/*   Updated: 2024/11/10 12:04:26 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter ( void ) {
}

ScalarConverter::~ScalarConverter ( void ) {
    
}

ScalarConverter::ScalarConverter ( const ScalarConverter& scalarConverter ) {
    *this = scalarConverter;
}

ScalarConverter& ScalarConverter::operator= ( const ScalarConverter& scalarConverter ) {
    (void)scalarConverter;
    return (*this);
}

static int validateInput(const std::string input)
{
    int n;
    int i;

    n = 0;
    if (input[0] == '+' || input[0] == '-')
        n++;
    for ( i = n; i < static_cast<int>(input.length() - 1); i++ ) {
        if ( !isdigit(input[i]) && input[i] != '.' )
            return (0);
    }
    if ( !isdigit(input[i]) && input[i] != 'f' )
        return (0);
    return (1);
}

static void convertChar( const std::string input ) {
    int inputInt;

    std::cout << "char: ";
    if (input.length() == 1 && isalpha(input[0])) {
        std::cout << input[0] << std::endl;
        return;
    }
    if (!validateInput(input)) {
        std::cout << "impossible" << std::endl;
        return ;
    }
    inputInt = atoi(input.c_str());
    if (!isprint(inputInt))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << static_cast<char>(inputInt) << std::endl;
}

static void convertInt( const std::string input ) {
    int inputInt;

    std::cout << "int: ";
    if (input.length() == 1) {
        if (input[0] >= '0' && input[0] <= '9')
            std::cout << atoi(input.c_str()) << std::endl;
        else
            std::cout << static_cast<int>(input[0]) << std::endl;
        return ;
    }
    if (!validateInput(input)) {
        std::cout << "impossible" << std::endl;
        return ;
    }
    inputInt = atoi(input.c_str());
    std::cout << inputInt << std::endl;
}

static void convertFloat( const std::string input ) {
    float inputFloat;

    std::cout << "float: ";
    if (input.length() == 1) {
        if (input[0] >= '0' && input[0] <= '9')
            std::cout << std::fixed << std::setprecision(2) << std::stof(input.c_str()) << 'f' << std::endl;
        else
            std::cout << std::fixed << std::setprecision(2) << static_cast<float>(input[0]) << 'f' << std::endl;
        return ;
    }
    if ( input == "nan") {
        std::cout << "nanf" << std::endl;
        return ;
    }
    if ( input == "nanf" || input == "-inff" || input == "+inff" ) {
        std::cout << input << std::endl;
        return ;
    }   
    if (!validateInput(input)) {
        std::cout << "impossible" << std::endl;
        return ;
    }
    inputFloat = std::stof(input.c_str());
    std::cout << std::fixed << std::setprecision(2) << inputFloat << 'f' << std::endl;
}

static void convertDouble( const std::string input ) {
    double inputDouble;

    std::cout << "double: ";
    if (input.length() == 1) {
        if (input[0] >= '0' && input[0] <= '9')
            std::cout << std::fixed << std::setprecision(2) << std::stof(input.c_str()) << std::endl;
        else
            std::cout << std::fixed << std::setprecision(2) << static_cast<double>(input[0]) << std::endl;
        return ;
    }
    if ( input == "nan" || input == "-nf" || input == "+nf" ) {
        std::cout << input << std::endl;
        return ;
    }  
    if (!validateInput(input)) {
        std::cout << "impossible" << std::endl;
        return ;
    }
    inputDouble = std::stof(input.c_str());
    std::cout << std::fixed << std::setprecision(2) << inputDouble << std::endl;
}

void ScalarConverter::convert ( const std::string input ) {
    convertChar(input);
    convertInt(input);
    convertFloat(input);
    convertDouble(input);
}