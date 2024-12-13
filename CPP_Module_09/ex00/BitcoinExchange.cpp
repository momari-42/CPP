/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:41:07 by momari            #+#    #+#             */
/*   Updated: 2024/12/05 17:20:16 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Orthodox canonical form

//------------------------------------------------------

BitcoinExchange::BitcoinExchange( void ) {
    errNumber = 0;
    manageDataFile();
}

BitcoinExchange::~BitcoinExchange( void ) {
    
}
BitcoinExchange::BitcoinExchange( const BitcoinExchange& btc ) {
    *this = btc;
}

BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& btc ) {
    this->data = btc.data;
    return (*this);
}

//------------------------------------------------------


void BitcoinExchange::readAndSearchForDate(std::string dataFile) {
    std::string     value;
    std::string     line;
    std::ifstream   inFile(dataFile);


    if (!inFile.is_open())
        throw std::invalid_argument("Invalide file");
    std::getline(inFile, line);
    if (line.empty() || line != "date | value")
        throw std::invalid_argument("Invalide file");
    while (std::getline(inFile, line)) {
        if (line.empty()) {
            errNumber = -1;
            std::cout << "Error: empty line" << std::endl;
        }
        parseDate(line);
        parseValue(line);
        calculateThePrice();
        errNumber = 0;
    }
    inFile.close();
}

void BitcoinExchange::parseDate(const std::string& line) {
    int         ymd[3];
    std::size_t position;
    std::size_t countHyphen;
    std::string datePart;
    std::string tempraryDate;
    std::string restDate;
    char*       rest = NULL;
    bool        bo = true;

    if (errNumber == -1)
        return ;
    position = line.find("|");
    if (line.size() < 14 || position == std::string::npos || position != 11) {
        errNumber = -1;
        std::cout << "Error: bad input " << line << std::endl;
        return ;
    }
    datePart = line.substr(0, position - 1);
    tempraryDate = datePart;
    this->date = datePart; 
    countHyphen = std::count(tempraryDate.begin(), tempraryDate.end(), '-');
    if (countHyphen != 2) {
        errNumber = -1;
        std::cout << "Error: bad input " << datePart << std::endl;
        return ;
    }
    restDate = tempraryDate.substr(0, tempraryDate.find("-"));
    ymd[0] = std::strtod(restDate.c_str(), &rest);
    if (rest && *rest)
        bo = false;
    tempraryDate.erase(0, tempraryDate.find("-") + 1);
    restDate = tempraryDate.substr(0, tempraryDate.find("-"));
    ymd[1] = std::strtod(restDate.c_str(), &rest);
    if (rest && *rest)
        bo = false;
    tempraryDate.erase(0, tempraryDate.find("-") + 1);
    ymd[2] = std::strtod(tempraryDate.c_str(), &rest);
    if (rest && *rest)
        bo = false;
    if (!bo) {
        errNumber = -1;
        std::cout << "Error: bad input " << datePart << std::endl;
        return ;
    }
    validateDate(ymd);
    if (errNumber == -1) {
        errNumber = -1;
        std::cout << "Error: bad input " << datePart << std::endl;
        return ;
    }
}

void BitcoinExchange::bitcoinExchange(std::string firstArgument) {
    readAndSearchForDate(firstArgument);
}

void BitcoinExchange::manageDataFile() {
    std::string     tempraryLine;
    std::ifstream   inFile("data.csv");
    double          tmp;

    if (!inFile.is_open()) {
        throw std::invalid_argument("Missing data.csv file");
    }
    std::getline(inFile, tempraryLine);
    while (std::getline(inFile, tempraryLine)) {
        tmp = std::stod(tempraryLine.substr(tempraryLine.find(',') + 1, tempraryLine.size()));
        data.insert(std::pair<std::string, double>(tempraryLine.substr(0, tempraryLine.find(',')), tmp));
    }
    inFile.close();
}

void BitcoinExchange::validateDate(const int* ymd) {
    if (ymd[0] < 1000 || ymd[0] > 4000)
        errNumber = -1;
    if (errNumber != -1 && (ymd[1] < 1 || ymd[1] > 12))
        errNumber = -1;
    if (errNumber != -1 && (ymd[2] < 1 || ymd[2] > 31))
        errNumber = -1;
    if (errNumber != -1) {
        if ( (ymd[1] == 4 || ymd[1] == 6 || ymd[1] == 9 || ymd[1] == 11) && ymd[2] > 30 )
            errNumber = -1;
        else if ( ymd[1] == 2 ) {
            if (((ymd[0] % 4 == 0) && (ymd[0] % 100)) || (ymd[0] % 400 == 0)) {
               errNumber = ( ymd[2] > 29 ) ? -1 : 0; 
            } 
            else
                errNumber = ( ymd[2] > 28 ) ? -1 : 0; 
        }
    }
}


void BitcoinExchange::parseValue(const std::string& line) {
    std::size_t     position;
    char            *rest;
    std::string     valuePart;
    double          valueDouble;


    if (errNumber == -1)
        return ;
    position = line.find("|");
    valuePart = line.substr(position + 1, line.size());
    valueDouble = std::strtod(valuePart.c_str(), &rest);
    if ( valueDouble < 0 || valueDouble > 1000 || (rest && *rest)) {
        errNumber = -1;
        if ( valueDouble < 0 )
            std::cout << "Error: not a positive number." << std::endl;
        else if ( valueDouble > 1000 )
            std::cout << "Error: too large a number." << std::endl;
        else 
            std::cout << "Error: not number." << std::endl;
    }
    this->value = valueDouble;
}

void BitcoinExchange::calculateThePrice( ) {
    if (errNumber == -1)
        return ;
    std::map<std::string, double>::iterator it = data.lower_bound(date);
    if ( it != data.begin() &&  (*it).first != date )
        --it;
    std::cout << date << " => " << value << " = " << (double)(*it).second * this->value << std::endl;
}
