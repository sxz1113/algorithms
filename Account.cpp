#include "Account.h"
#include <iostream>

void Account::set_balance(double b) {
    balance = b;
}

double Account::get_balance() {
    cout << "current balance: " << balance << endl;
    return balance;
}

void Account::set_name(std::string n) {
    name = n;
}

string Account::get_name() {
    return name;
}

bool Account::deposit(double amount) {
    if (amount >= 0)
    {
        balance += amount;
        cout << "deposit " << amount << " into acount" << endl;
        return true;
    }
    else
    {
        cout << "deposit amount cannot be negative" << endl;
        return false;
    }
}

bool Account::withdraw(double amount) {
    if (balance > amount)
    {
        cout << "withdraw " << amount << " from acount" << endl;
        balance -= amount;
        return true;
    }
    else
    {
        cout << "insufficient balance, withdraw declined" << endl;
        return false;
    }
}
