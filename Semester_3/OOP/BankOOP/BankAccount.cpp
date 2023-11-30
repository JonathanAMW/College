#include <iostream>
#include "BankAccount.h"

// implementasi dari constructor
// untuk inisialisasi atribut
BankAccount::BankAccount(int accNum, int accBalance) {
	AccountNumber = accNum;
	AccountBalance = accBalance;
}

void BankAccount::Deposit(int money) {
	AccountBalance = AccountBalance + money;
}

void BankAccount::Withdrawal(int money) {
	AccountBalance = AccountBalance - money;
}

void BankAccount::ShowCurrentBalance() {
	std::cout << "Current Balance = " << AccountBalance << std::endl;
}

int BankAccount::GetCurrentBalance()
{
	return AccountBalance;
}