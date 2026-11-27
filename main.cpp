#include <iostream>
#include "Account.h"

int main() {
    Account acc("Ayush", 1001, 500.0);

    acc.deposit(200.0);
    acc.withdraw(100.0);
    acc.withdraw(10000.0);   // fails, so it won't appear in history

    acc.printHistory();
    return 0;
}