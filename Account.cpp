#include "Account.h"

Account::Account(const std::string& name, int accountNumber, double initialBalance)
    : name(name), accountNumber(accountNumber), balance(initialBalance) {}

std::string Account::getName() const {
    return name;
}

int Account::getAccountNumber() const {
    return accountNumber;
}

double Account::getBalance() const {
    return balance;
}

bool Account::deposit(double amount) {
    if (amount <= 0) {
        return false;
    }
    balance += amount;
    return true;
}

bool Account::withdraw(double amount) {
    if (amount <= 0 || amount > balance) {
        return false;
    }
    balance -= amount;
    return true;
}