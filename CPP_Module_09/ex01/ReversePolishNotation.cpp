/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReversePolishNotation.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:03:23 by momari            #+#    #+#             */
/*   Updated: 2024/12/06 11:47:30 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReversePolishNotation.hpp"

// Othodox canonical form

//-------------------------------------------------

ReversePolishNotation::ReversePolishNotation( void ) {
    
}

ReversePolishNotation::~ReversePolishNotation( void ) {
    
}

ReversePolishNotation::ReversePolishNotation( const ReversePolishNotation& rpn ) {
    *this = rpn;
}

ReversePolishNotation& ReversePolishNotation::operator=( const ReversePolishNotation& rpn ) {
    (void)rpn;
    return (*this);
}

//-------------------------------------------------

void ReversePolishNotation::RPN( const std::string argument ) {
    int index = 0;

    if (argument.empty())
        throw std::invalid_argument("invalid argument");
    while (argument[index]) {
        if (isValideArgument(argument[index]))
            throw std::invalid_argument("invalide argument");
        if (  std::isdigit(argument[index]) ) {
            if ( argument[index + 1] == ' ' || argument[index + 1] == '\0' )
                st.push(argument[index] - '0');
            else
                throw std::invalid_argument("invalide argument");
        }
        else if ( isOperators(argument[index]) )
            manageCalculation(argument[index]);
        index++;
    }
    if (st.size() != 1)
        throw std::invalid_argument("invalid argument");
    std::cout << st.top() << std::endl;
    while (!st.empty())
        st.pop();
}

int ReversePolishNotation::isValideArgument( const char c ) {
    if ( !std::isdigit(c) && c != '+' 
            && c != '-' && c != '/' 
            && c != '*' && c != ' ' )
        return (1);
    return (0);
}

int ReversePolishNotation::isOperators( const char c ) {
    if ( c == '+' || c == '-' ||
         c == '/' || c == '*' )
        return (1);
    return (0);
}

void ReversePolishNotation::manageCalculation( char c ) {
    double tmp;

    if (st.size() < 2)
        throw std::invalid_argument("invalid argument");
    if ( c == '+' ) {
        tmp = st.top();
        st.pop();
        st.top() += tmp;
    } else if ( c == '-' ) {
        tmp = st.top();
        st.pop();
        st.top() -= tmp;
    } else if ( c == '*' ) {
        tmp = st.top();
        st.pop();
        st.top() *= tmp;
    } else if ( c == '/' ) {
        tmp = st.top();
        if (!tmp)
            throw std::invalid_argument("invalid devided by 0");
        st.pop();
        st.top() /= tmp;
    }
    if (st.top() > std::numeric_limits<int>::max())
        throw std::invalid_argument("too large number");
}