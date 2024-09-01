/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:17:16 by momari            #+#    #+#             */
/*   Updated: 2024/08/31 19:49:49 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


void Account::_displayTimestamp()
{
    std::time_t time = std::time(NULL);
    std::tm *currentTime = std::localtime(&time);

    std::cout << "[" << currentTime->tm_year + 1900 << 1 + currentTime->tm_mon << currentTime->tm_mday << "_"
                << currentTime->tm_hour << currentTime->tm_min << currentTime->tm_sec << "] ";
}

Account::Account(int initial_deposit){
    _displayTimestamp();
    this->_accountIndex = _nbAccounts;
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << initial_deposit;
    std::cout << ";created" << std::endl;
    _nbAccounts++;
    _totalAmount += initial_deposit;
    this->_amount = initial_deposit;
}

Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";closed" << std::endl;
}

int Account::getNbAccounts()
{
    return (_nbAccounts);
}

int Account::getTotalAmount()
{
    return (_totalAmount);
}

int Account::getNbDeposits()
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
        << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex ;
    std::cout << ";p_amount:" << this->_amount ;
    std::cout << ";withdrawal:";
    if (withdrawal >= 0 && withdrawal <= this->_amount)
    {
        std::cout << withdrawal;
        this->_amount -= withdrawal;
        _totalAmount -= withdrawal;
        std::cout << ";amount:" << this->_amount;
        _totalNbWithdrawals++;
        _nbWithdrawals++;
        std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
        return (true);
    }
    else
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex ;
    std::cout << ";amount:" << this->_amount ;
    std::cout << ";deposits:" << this->_nbDeposits ;
    std::cout << ";withdrawals:" << this->_nbWithdrawals ;
    std::cout << std::endl;
}

int		Account::checkAmount( void ) const
{
    return (this->_amount);
}

void Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex ;
    std::cout << ";p_amount:" << this->_amount ;
    this->_amount += deposit;
    this->_totalAmount += deposit;
    this->_totalNbDeposits++;
    this->_nbDeposits++;
    std::cout << ";deposit:" << deposit ;
    std::cout << ";amount:" << this->_amount ;
    std::cout << ";nb_deposits:" << this->_nbDeposits ;
    std::cout << std::endl;
}


