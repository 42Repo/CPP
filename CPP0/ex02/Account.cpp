/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:50:31 by asuc              #+#    #+#             */
/*   Updated: 2024/05/17 20:10:18 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <string>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/**********************************************************/
/*                     Public methods                     */
/**********************************************************/

Account::Account(int initial_deposit) {
    _amount = initial_deposit;
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _totalNbDeposits = 0;
    _totalNbWithdrawals = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void) {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts(void) { return _nbAccounts; }

int Account::getTotalAmount(void) { return _totalAmount; }

int Account::getNbDeposits(void) { return _totalNbDeposits; }

int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

int Account::checkAmount(void) const { return _amount; }

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals
              << std::endl;
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount - deposit
              << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits
              << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    if (_amount < withdrawal) {
        _displayTimestamp();
        std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused"
                  << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount + withdrawal
              << ";withdrawal:" << withdrawal << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

/**********************************************************/
/*                     Private methods                    */
/**********************************************************/

void Account::_displayTimestamp(void) {
    time_t now = time(0);
    tm    *ltm = localtime(&now);
    std::cout << "[" << 1900 + ltm->tm_year;
    if (1 + ltm->tm_mon < 10) {
        std::cout << "0";
    }
    std::cout << 1 + ltm->tm_mon;
    if (ltm->tm_mday < 10) {
        std::cout << "0";
    }
    std::cout << ltm->tm_mday << "_";
    if (ltm->tm_hour < 10) {
        std::cout << "0";
    }
    std::cout << ltm->tm_hour;
    if (ltm->tm_min < 10) {
        std::cout << "0";
    }
    std::cout << ltm->tm_min;
    if (ltm->tm_sec < 10) {
        std::cout << "0";
    }
    std::cout << ltm->tm_sec << "]";
}

Account::Account(void) {
    _amount = 0;
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _totalAmount += 0;
    _totalNbDeposits = 0;
    _totalNbWithdrawals = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}
