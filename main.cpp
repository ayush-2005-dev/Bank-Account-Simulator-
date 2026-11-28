#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include "Account.h"

// Reads a double. If the input isn't a number, clears the error and discards the bad line.
bool readAmount(double& value) {
    if (std::cin >> value) {
        return true;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return false;
}

int main() {
    const std::string dataFile = "account.txt";
    Account acc("", 0, 0.0);

    if (acc.load(dataFile)) {
        std::cout << "Welcome back, " << acc.getName() << ".\n";
    } else {
        std::string name;
        int number;
        double startBalance;

        std::cout << "No saved account found. Let's create one.\n";
        std::cout << "Name: ";
        std::getline(std::cin, name);
        std::cout << "Account number: ";
        std::cin >> number;
        std::cout << "Starting balance: ";
        std::cin >> startBalance;

        acc = Account(name, number, startBalance);
    }

    int choice = 0;
    do {
        std::cout << "\n1. Deposit\n"
                  << "2. Withdraw\n"
                  << "3. Show balance\n"
                  << "4. Show history\n"
                  << "0. Exit\n"
                  << "Choice: ";

        choice = -1;   // a failed read sets choice to 0, so reset it to a non-exit value
                if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = -1;   // a failed read sets choice to 0, which would exit the loop
            std::cout << "Please enter a number from the menu.\n";
            continue;
        }

        if (choice == 1) {
            double amount;
            std::cout << "Amount: ";
            if (!readAmount(amount)) {
                std::cout << "Please enter a number.\n";
                continue;
            }
            if (acc.deposit(amount)) {
                std::cout << "Deposit successful.\n";
            } else {
                std::cout << "Invalid amount.\n";
            }
        } else if (choice == 2) {
            double amount;
            std::cout << "Amount: ";
            if (!readAmount(amount)) {
                std::cout << "Please enter a number.\n";
                continue;
            }
            if (acc.withdraw(amount)) {
                std::cout << "Withdrawal successful.\n";
            } else {
                std::cout << "Withdrawal failed: invalid amount or insufficient funds.\n";
            }
        } else if (choice == 3) {
            std::cout << std::fixed << std::setprecision(2)
                      << "Balance: " << acc.getBalance() << "\n";
        } else if (choice == 4) {
            acc.printHistory();
        } else if (choice != 0) {
            std::cout << "Unknown option.\n";
        }
    } while (choice != 0);

    if (acc.save(dataFile)) {
        std::cout << "Account saved.\n";
    } else {
        std::cout << "Could not save account.\n";
    }
    std::cout << "Goodbye.\n";
    return 0;
}