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

const std::vector<Transaction>& Account::getHistory() const {
    return history;
}

bool Account::deposit(double amount) {
    if (amount <= 0) {
        return false;
    }
    balance += amount;
    history.push_back({"Deposit", amount, balance});
    return true;
}

bool Account::withdraw(double amount) {
    if (amount <= 0 || amount > balance) {
        return false;
    }
    balance -= amount;
    history.push_back({"Withdrawal", amount, balance});
    return true;
}