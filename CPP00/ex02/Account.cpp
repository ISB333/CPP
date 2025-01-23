/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:31:35 by adesille          #+#    #+#             */
/*   Updated: 2025/01/16 13:02:05 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account()
{
	_nbAccounts--;
	_totalAmount -= _amount;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposit:"
		<< _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int	p_amount = _amount;

	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";deposit:"
		<< deposit << ";amount:" << _amount << ";nb_deposits;" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int	p_amount = _amount;

	if (withdrawal > _amount)
		return (_displayTimestamp(), std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount
			<< ";withdrawal:refused" << std::endl, false);
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:"
		<< withdrawal << ";amount:" << checkAmount() << ";nb_withdrawals;" << _nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:"
		<< _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp( void )
{
	std::time_t now = std::time(0);
	std::tm* localTime = std::localtime(&now);

	std::cout << "["
			  << (localTime->tm_year + 1900)
			  << std::setw(2) << std::setfill('0') << (localTime->tm_mon + 1)
			  << std::setw(2) << std::setfill('0') << localTime->tm_mday
			  << "_"
			  << std::setw(2) << std::setfill('0') << localTime->tm_hour
			  << std::setw(2) << std::setfill('0') << localTime->tm_min
			  << std::setw(2) << std::setfill('0') << localTime->tm_sec
			  << "] ";
}

