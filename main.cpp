#include <iomanip>
#include <iostream>
#include "Account.h"

int main() {
    Account acc("Ayush", 1001, 500.0);
    int choice = 0;

    do {
        std::cout << "\n1. Deposit\n"
                  << "2. Withdraw\n"
                  << "3. Show balance\n"
                  << "4. Show history\n"
                  << "0. Exit\n"
                  << "Choice: ";

        if (!(std::cin >> choice)) {
            break;   // input ended or was not a number
        }

        if (choice == 1) {
            double amount;
            std::cout << "Amount: ";
            std::cin >> amount;
            if (acc.deposit(amount)) {
                std::cout << "Deposit successful.\n";
            } else {
                std::cout << "Invalid amount.\n";
            }
        } else if (choice == 2) {
            double amount;
            std::cout << "Amount: ";
            std::cin >> amount;
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

    std::cout << "Goodbye.\n";
    return 0;
}