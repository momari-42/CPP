/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:41:13 by momari            #+#    #+#             */
/*   Updated: 2024/11/22 18:03:06 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span ( void ) { }

Span::Span ( int N ) : N(N) {
}

Span::Span ( const Span& span ) {
    *this = span;
}

Span& Span::operator= ( const Span& span ) {
    this->N = span.N;
    numbers.insert(this->numbers.begin(), span.numbers.begin(), span.numbers.end());
    return (*this);
}

void Span::addNumber ( int N ) {
    if (numbers.size() == static_cast<unsigned long>(this->N) )
        throw std::invalid_argument("Unfortunately, you reach the max of this vector.");
    numbers.push_back(N);
}

void Span::addNumber ( std::vector<int>::iterator itBegin, std::vector<int>::iterator itEnd ) {
    if ( numbers.size() + (itEnd - itBegin) > static_cast<unsigned long>(this->N) )
        throw std::invalid_argument("Unfortunately, you reach the max of this vector.");
    numbers.insert(numbers.begin(), itBegin, itEnd);
}

void Span::shortestSpan ( void ) {
    int resultFinal = 0;
    int tempraryNumber = 0;
    if (sortedNumbers.size() !=  numbers.size()
        || std::is_sorted(sortedNumbers.begin(), sortedNumbers.end()) == 0) {
        sortedNumbers = numbers;
        std::sort(sortedNumbers.begin(), sortedNumbers.end());
    }
    if ( sortedNumbers.size() < 2 )
        throw std::length_error("The size of the span is less two numbers");
    for (std::vector<int> ::iterator it = sortedNumbers.begin(); it != sortedNumbers.end() - 1; it++) {
        tempraryNumber = *(++it) - *(--it);
        resultFinal = ( it == sortedNumbers.begin() || tempraryNumber < resultFinal ) ? tempraryNumber : resultFinal;
    }
    std::cout << resultFinal << std::endl;
}

void Span::longestSpan ( void ) {
    if (sortedNumbers.size() !=  numbers.size()
        || std::is_sorted(sortedNumbers.begin(), sortedNumbers.end()) == 0) {
        sortedNumbers = numbers;
        std::sort(sortedNumbers.begin(), sortedNumbers.end());
    }
    if ( sortedNumbers.size() < 2 )
        throw std::length_error("The size of the span is less two numbers");
    std::vector<int>::iterator itmin = sortedNumbers.begin();
    std::vector<int>::reverse_iterator itmax = sortedNumbers.rbegin();
    std::cout << *itmax - *itmin  << std::endl;
}