/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:14:43 by momari            #+#    #+#             */
/*   Updated: 2024/11/07 19:17:39 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {

    Data *data = new (Data);

    data->content = "mohammed";
    data->inumber = 1337;
    data->fNumber = 1337.42;
    data->dNumber = 42;
    data->lNumber = 1337;

    uintptr_t ptr = Serializer::serialize(data);
    Data *finalresult = Serializer::deserialize(ptr);

    std::cout << finalresult->content << std::endl;
    std::cout << finalresult->inumber << std::endl;
    std::cout << finalresult->fNumber << std::endl;
    std::cout << finalresult->dNumber << std::endl;
    std::cout << finalresult->lNumber << std::endl;

    delete data;
}