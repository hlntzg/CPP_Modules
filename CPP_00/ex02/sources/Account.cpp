#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// Constructor
// Initializes an account with an initial deposit.
Account::Account(int initial_deposit) {
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << initial_deposit;
	std::cout << ";created" << std::endl;
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

// Destructor
// Called when an Account object is destroyed.
// This cleans up any resources if needed.
Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
	return ;
}

// Static functions that operates on static member variables.
// They do not have access to non-static member variables.
int	Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

// Member functions
// These functions operate on individual instances of the class (i.e., on a specific Account object).
// They can access both static and non-static member variables.
void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
	_totalAmount += deposit;
	_totalNbDeposits++;
	return ;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	if (checkAmount() > withdrawal) {
		std::cout << ";withdrawal:" << withdrawal;
		_amount -= withdrawal;
		_nbWithdrawals++;
		std::cout << ";amount:" << _amount;
		std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		return (true);
	}
	else {
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
}

int		Account::checkAmount(void) const {
	return (_amount);
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

// Private member function to display the current timestamp
void	Account::_displayTimestamp(void) {
    char result[18];
    
	std::time_t currentTime = std::time(0);
    std::strftime(result, sizeof(result), "%Y%m%d_%H%M%S", std::localtime(&currentTime));  
    std::cout << "[" << result << "] ";
}

Account::Account(void) {}
