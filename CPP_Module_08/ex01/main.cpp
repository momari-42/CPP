/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:38:47 by momari            #+#    #+#             */
/*   Updated: 2024/11/22 18:03:36 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <set>

int main()
{
    try {
        std::vector<int> vec;
        while (vec.size() < 10000)
        {
            vec.push_back(std::rand() % 100000);
        }
        Span span(10000);
        for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
            span.addNumber(*it);
        }
        Span newspan(10000);
        newspan.addNumber(vec.begin(), vec.end());
        span.shortestSpan();
        span.longestSpan();
        newspan.shortestSpan();
        newspan.longestSpan();
    }
    catch (std::exception& e) {
        std::cout << "Error : " << e.what() << std::endl;
    }
}