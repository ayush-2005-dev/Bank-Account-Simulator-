#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

struct Transaction {
    std::string type;   // "Deposit" or "Withdrawal"
    double amount;
    double balanceAfter;
};

class Account {
private:
    std::string name;
    int accountNumber;
    double balance;
    std::vector<Transaction> history;

public:
    Account(const std::string& name, int accountNumber, double initialBalance);

    std::string getName() const;
    int getAccountNumber() const;
    double getBalance() const;
    const std::vector<Transaction>& getHistory() const;

    bool deposit(double amount);
    bool withdraw(double amount);

    void printHistory() const;
    bool save(const std::string& filename) const;
    bool load(const std::string& filename);
};

#endif