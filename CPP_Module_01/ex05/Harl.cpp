/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:36:28 by momari            #+#    #+#             */
/*   Updated: 2024/09/03 14:36:05 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
    std::cout << std::endl;
}

void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
    std::cout << std::endl;
}

void Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.";
    std::cout << std::endl;
}

void Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now.";
    std::cout << std::endl;
}

void Harl::complain( std::string level )
{
    std::string functionNames[4] = {"debug", "info", "warning", "error"};
    void (Harl::*functionPointers[4])(void);
    functionPointers[0] = &Harl::debug;
    functionPointers[1] = &Harl::info;
    functionPointers[2] = &Harl::warning;
    functionPointers[3] = &Harl::error;
    
    for (int i = 0; i < 4; i++) {
        if (level == functionNames[i]) {
            (this->*functionPointers[i])();
            break;
        }
    }
}