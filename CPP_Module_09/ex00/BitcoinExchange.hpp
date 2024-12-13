/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:41:09 by momari            #+#    #+#             */
/*   Updated: 2024/12/06 12:50:18 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <exception>

class BitcoinExchange {
    private:
        std::string                     date;
        double                          value;
        int                             errNumber;
        std::map<std::string, double>   data;
        void    manageDataFile( void );
        void    readAndSearchForDate(std::string dataFile);
        void    parseDate(const std::string& line);
        void    validateDate(const int* ymd);
        void    parseValue(const std::string& line);
        void    calculateThePrice( void );
    public:
        BitcoinExchange( void );
        ~BitcoinExchange( void );
        BitcoinExchange( const BitcoinExchange& btc );
        BitcoinExchange& operator=( const BitcoinExchange& btc );
        void bitcoinExchange(std::string firstArgument);
};
