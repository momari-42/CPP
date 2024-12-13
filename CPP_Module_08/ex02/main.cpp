/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:18:16 by momari            #+#    #+#             */
/*   Updated: 2024/11/22 17:47:11 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    
   {
        std::cout << "---- This is MutantStack test ----" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);

        std::cout << mstack.top() << std::endl;

        mstack.pop();

        std::cout << mstack.size() << std::endl;

        mstack.push(3); 
        mstack.push(5); 
        mstack.push(737);
        //[...] mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    
    {
        std::cout << "----     This is list test     ----" << std::endl;
        std::list<int> mlist;

        mlist.push_back(5);
        mlist.push_back(17);

        std::cout << mlist.back() << std::endl;

        mlist.pop_back();

        std::cout << mlist.size() << std::endl;

        mlist.push_back(3);
        mlist.push_back(5);
        mlist.push_back(737);
        //[...] mlist.push_back(0);

        std::list<int>::iterator it = mlist.begin();
        std::list<int>::iterator ite = mlist.end();

        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }

        // Copying to a stack (std::stack works on any container with back access)
        std::stack<int, std::list<int> > s(mlist);

        return 0;
    }    
    return 0;
}
