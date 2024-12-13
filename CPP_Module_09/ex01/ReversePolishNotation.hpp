/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReversePolishNotation.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:03:26 by momari            #+#    #+#             */
/*   Updated: 2024/12/06 11:47:25 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <stack>
#include <iomanip>

class ReversePolishNotation {
    private:
        std::stack<double> st;
        int     isValideArgument( const char c );
        int     isOperators( const char c );
        void    manageCalculation( char c );
    public:
        ReversePolishNotation( void );
        ~ReversePolishNotation( void );
        ReversePolishNotation( const ReversePolishNotation& rpn );
        ReversePolishNotation& operator=( const ReversePolishNotation& rpn );
        void RPN( const std::string argument );
        
};

