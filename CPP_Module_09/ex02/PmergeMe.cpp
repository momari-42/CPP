/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:07:07 by momari            #+#    #+#             */
/*   Updated: 2024/12/06 12:53:51 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Orthodox canonical form
// ----------------------------------

PmergeMe::PmergeMe( void ) {
}

PmergeMe::~PmergeMe( void ) { }


PmergeMe::PmergeMe( const PmergeMe& pmergeMe ) {
    *this = pmergeMe;
}

PmergeMe& PmergeMe::operator=( const PmergeMe& pmergeMe ) {
    this->jacobsthalNumbers = pmergeMe.jacobsthalNumbers;
    this->vec = pmergeMe.vec;
    this->deq = pmergeMe.deq;
    return (*this);
}

// ----------------------------------

PmergeMe::PmergeMe( const std::vector<int>& vec, const std::deque<int>& deq ) {
    if (vec.size() == 0 || deq.size() == 0)
        return;
    this->vec.insert(this->vec.begin(), vec.begin(), vec.end());
    this->deq.insert(this->deq.begin(), deq.begin(), deq.end());
    generateJacobsthalNumbers(this->vec.size() / 2, 0);
    insertMissingNumbers( this->vec.size() / 2 );
}

void PmergeMe::mergeInsertSortVector( void ) {
    vectorClock[0] = clock();
    mergeInsertSortForVector();
    vectorClock[1] = clock();
}

void PmergeMe::mergeInsertSortDeque( void ) {
    dequeClock[0] = clock();
    mergeInsertSortForDeque();
    dequeClock[1] = clock();
}



void PmergeMe::mergeInsertSort (void) {
    if (vec.size() == 0 || deq.size() == 0)
        throw std::invalid_argument("Vector or Deque is empty");
    std::cout  << "before  : ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end() ; it++) {
        std::cout  << *it << " ";
    }
    std::cout  << std::endl;

    //----------------------------------------
    if ( vec.size() > 1 )
        PmergeMe::mergeInsertSortVector();
    if ( deq.size() > 1 )
        PmergeMe::mergeInsertSortDeque();
    //----------------------------------------

    std::cout  << "after   : ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end() ; it++) {
        std::cout  << *it << " ";
    }
    std::cout  << std::endl;
    std::cout << "Time to process a range of " << vec.size()  << " elements with std::vector : " << (double)((double)(vectorClock[1] - vectorClock[0]) / CLOCKS_PER_SEC * 1e6) << "us" << std::endl;
    std::cout << "Time to process a range of " << deq.size()  << " elements with std::deque  : " << (double)((double)(dequeClock[1] - dequeClock[0]) / CLOCKS_PER_SEC * 1e6) << "us" << std::endl;
}

void PmergeMe::mergeInsertSortForDeque( ) {
    int index = 0;
    int unpaireNumber = -1;
    unsigned long size = deq.size();
    if ( deq.size() % 2 ) {
        unpaireNumber = deq.back();
        deq.pop_back();
        size--;
    }
    std::deque<int> mainChain(size / 2);
    std::deque<int> pendChain(size / 2);
    for ( unsigned long n = 0; n < size; n+=2 ) {
        if (deq[n] < deq[n + 1]) {
            std::swap(deq[n], deq[n + 1]);
        }
    }
    unsigned long tmp;
    for ( unsigned long n = 2; n < size; n+=2 ) {
        tmp = n;
        while ( tmp &&  deq[tmp] < deq[tmp - 2]) {
            std::swap(deq[tmp], deq[tmp - 2]);
            std::swap(deq[tmp + 1], deq[tmp - 1]);
            tmp -= 2;
        }
    }
    for ( unsigned long n = 0; n < size; n+=2 ) {
        mainChain[index] = deq[n];
        pendChain[index] = deq[n + 1];
        index++;
    }
    mainChain.insert(mainChain.begin(), pendChain[0]);
    unsigned long jsize = jacobsthalNumbers.size();
    unsigned long psize = pendChain.size();
    for ( unsigned long n = 0; n < jsize; n++ ) {
        if (jacobsthalNumbers[n] < static_cast<int>(psize))
            mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), \
            pendChain[jacobsthalNumbers[n]]), pendChain[jacobsthalNumbers[n]]);
    }
    if (unpaireNumber != -1) {
            mainChain.insert(std::lower_bound(mainChain.begin(),\
            mainChain.end(), unpaireNumber), unpaireNumber);
    }
    deq = mainChain;
}


void PmergeMe::mergeInsertSortForVector( ) {
    int index = 0;
    int unpaireNumber = -1;
    unsigned long size = vec.size();
    if ( vec.size() % 2 ) {
        unpaireNumber = vec.back();
        vec.pop_back();
        size--;
    }
    std::vector<int> mainChain(size / 2);
    std::vector<int> pendChain(size / 2);
    for ( unsigned long n = 0; n < size; n+=2 ) {
        if (vec[n] < vec[n + 1]) {
            std::swap(vec[n], vec[n + 1]);
        }
    }
    unsigned long tmp;
    for ( unsigned long n = 2; n < size; n+=2 ) {
        tmp = n;
        while ( tmp &&  vec[tmp] < vec[tmp - 2]) {
            std::swap(vec[tmp], vec[tmp - 2]);
            std::swap(vec[tmp + 1], vec[tmp - 1]);
            tmp -= 2;
        }
    }
    for ( unsigned long n = 0; n < size; n+=2 ) {
        mainChain[index] = vec[n];
        pendChain[index] = vec[n + 1];
        index++;
    }
    mainChain.insert(mainChain.begin(), pendChain[0]);
    unsigned long jsize = jacobsthalNumbers.size();
    unsigned long psize = pendChain.size();
    for ( unsigned long n = 0; n < jsize; n++ ) {
        if (jacobsthalNumbers[n] < static_cast<int>(psize))
            mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), \
            pendChain[jacobsthalNumbers[n]]), pendChain[jacobsthalNumbers[n]]);
    }
    if (unpaireNumber != -1) {
            mainChain.insert(std::lower_bound(mainChain.begin(),\
            mainChain.end(), unpaireNumber), unpaireNumber);
    }
    vec = mainChain;
}

void fillContainers(char **arguments, std::vector<int>& vec, std::deque<int>& deq) {
    char            *rest   =  NULL;
    double          number  = 0;
    int             index   = 1;
    std::string     tempraryString;

    while (arguments && arguments[index]) {
        tempraryString = arguments[index];
        if (tempraryString.size() == 0)
            throw std::invalid_argument("invalid argument");
        number = std::strtod(arguments[index], &rest);
        if ( number < 0 || number > std::numeric_limits<int>::max() || (rest && *rest) )
            throw std::invalid_argument("invalid argument");
        vec.push_back(number);
        deq.push_back(number);
        index++;
    }
}

void PmergeMe::generateJacobsthalNumbers(unsigned long size, int n) {
    if (jacobsthalNumbers.size() && jacobsthalNumbers.back() >= static_cast<int>(size))
        return;
    if (n == 0 || n == 1) {
        jacobsthalNumbers.push_back(n);
        generateJacobsthalNumbers(size, n + 1);
    } else {
        jacobsthalNumbers.push_back(jacobsthalNumbers[n - 1] + (2 * jacobsthalNumbers[n - 2]));
        generateJacobsthalNumbers(size, n + 1);
    }
}

void PmergeMe::insertMissingNumbers ( unsigned long size ) {
    if (!size)
        return;
    jacobsthalNumbers.erase(jacobsthalNumbers.begin());
    jacobsthalNumbers.erase(jacobsthalNumbers.begin());
    for (unsigned long n = size; n > 1; n--) {
        if ( std::find(jacobsthalNumbers.begin(), jacobsthalNumbers.end(), n) == jacobsthalNumbers.end()) {
            for (std::vector<int>::iterator it = jacobsthalNumbers.begin(); it != jacobsthalNumbers.end(); it++) {
                if ( static_cast<int>(n) < *it ) {
                    jacobsthalNumbers.insert(++it, n);
                    break;
                }
            }
        }
    }
}