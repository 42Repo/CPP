/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:50:31 by asuc              #+#    #+#             */
/*   Updated: 2024/05/17 18:34:52 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

// Private methods

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

Account::~Account(void) {}

int Account::getNbAccounts(void) {}

int Account::getTotalAmount(void) {}

int Account::getNbDeposits(void) {}

int Account::getNbWithdrawals(void) {}

int Account::checkAmount(void) const {}

void Account::displayAccountsInfos(void) {}

void Account::makeDeposit(int deposit) {}

bool Account::makeWithdrawal(int withdrawal) {}

void Account::displayStatus(void) const {}

// Public methods

void Account::_displayTimestamp(void) {}

Account::Account(void) {}
