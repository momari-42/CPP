/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:57:56 by momari            #+#    #+#             */
/*   Updated: 2024/11/16 20:07:50 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template< typename  P> 
void f(P &content) {
  std::cout << "content is : " << content << std::endl;
}


int main()
{
  {
    int data[] = {1, 2, 3, 4, 5, 6};
    iter(data, 6, f<int>);
  }
    std::cout << "*****************" << std::endl;
  {
    const char *userName[] = {"momari", "mohammed", "omari"};
    iter(userName, 3, f<const char *>);
  }
}