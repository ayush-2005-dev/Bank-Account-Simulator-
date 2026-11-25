#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

class Account {
private:
    std::string name;
    int accountNumber;
    double balance;

public:
    Account(const std::string& name, int accountNumber, double initialBalance);

    std::string getName() const;
    int getAccountNumber() const;
    double getBalance() const;

    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif