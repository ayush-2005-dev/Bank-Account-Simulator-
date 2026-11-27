#include <fstream>
#include <iomanip>
#include <iostream>
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

void Account::printHistory() const {
    std::cout << "Transaction history for " << name
              << " (#" << accountNumber << ")\n";

    if (history.empty()) {
        std::cout << "  No transactions yet.\n";
        return;
    }

    std::cout << std::left << std::setw(14) << "Type"
              << std::right << std::setw(12) << "Amount"
              << std::setw(16) << "Balance after" << "\n";
    std::cout << std::string(42, '-') << "\n";

    for (const Transaction& t : history) {
        std::cout << std::left << std::setw(14) << t.type
                  << std::right << std::fixed << std::setprecision(2)
                  << std::setw(12) << t.amount
                  << std::setw(16) << t.balanceAfter << "\n";
    }
}

bool Account::save(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) {
        return false;
    }

    out << std::fixed << std::setprecision(2);
    out << name << "\n";
    out << accountNumber << " " << balance << "\n";
    for (const Transaction& t : history) {
        out << t.type << " " << t.amount << " " << t.balanceAfter << "\n";
    }
    return true;
}

bool Account::load(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) {
        return false;   // no file yet, keep the current data
    }

    std::getline(in, name);
    if (!(in >> accountNumber >> balance)) {
        return false;
    }

    history.clear();
    Transaction t;
    while (in >> t.type >> t.amount >> t.balanceAfter) {
        history.push_back(t);
    }
    return true;
}