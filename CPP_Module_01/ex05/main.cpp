/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:36:35 by momari            #+#    #+#             */
/*   Updated: 2024/09/03 14:45:34 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;

    harl.complain("debug");
    harl.complain("info");
    harl.complain("warning");
    harl.complain("error");
}