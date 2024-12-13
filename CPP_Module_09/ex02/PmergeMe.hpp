/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:07:10 by momari            #+#    #+#             */
/*   Updated: 2024/12/05 20:20:22 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <deque>

class PmergeMe {
    private:
        std::vector<int>    jacobsthalNumbers;
        clock_t             vectorClock[2];
        clock_t             dequeClock[2] ;
        std::vector<int>    vec;
        std::deque<int>     deq;
        PmergeMe( void );
        void mergeInsertSortVector( void );
        void mergeInsertSortDeque( void );
        void generateJacobsthalNumbers(unsigned long size, int n);
        void insertMissingNumbers (unsigned long size );
        void mergeInsertSortForVector( );
        void mergeInsertSortForDeque( );

    public:
        PmergeMe( const std::vector<int>& vec, const std::deque<int>& deq );
        PmergeMe( const PmergeMe& pmergeMe );
        PmergeMe& operator=( const PmergeMe& pmergeMe );
        ~PmergeMe( void );
        void mergeInsertSort (void);
};

void fillContainers(char **arguments, std::vector<int>& vec, std::deque<int>& deq);