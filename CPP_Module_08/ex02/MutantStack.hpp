/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:18:19 by momari            #+#    #+#             */
/*   Updated: 2024/11/22 17:44:32 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <vector>
#include <list>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack ( void ) {};
        ~MutantStack ( void ) {};
        MutantStack ( const MutantStack& mutantStack ) : std::stack<T>(mutantStack) {
            *this = mutantStack;
        };
        MutantStack& operator= ( const MutantStack& mutantStack ){
            (void)mutantStack;
            std::stack<T>::operator=(mutantStack);
            return (*this);
        };
        typedef typename std::deque<T>::iterator iterator;
        iterator begin ( void ) {
            return (this->c.begin());
        };
        iterator end ( void ) {
            return (this->c.end());
        };
};