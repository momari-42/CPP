/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:41:10 by momari            #+#    #+#             */
/*   Updated: 2024/11/23 11:07:04 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <cstdlib>

class Span {
    private:
        int N;
        std::vector<int> numbers;
        std::vector<int> sortedNumbers;
        Span ( void );

    public:
        Span ( int N );
        Span ( const Span& span );
        Span& operator=( const Span& span );
        void addNumber ( int N );
        void addNumber ( std::vector<int>::iterator itBegin, std::vector<int>::iterator itEnd );
        void shortestSpan ( void );
        void longestSpan ( void );
};