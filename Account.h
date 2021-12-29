#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>

using namespace std;

class Account
{
private:
    /* data */
    double balance;
    string name {};
public:
    // Constructors
    Account() {
        balance = 0.;
        name = "";
    };
    Account(string n, double b) {
        name = n;
        balance = b;
    };
    Account(string n) {
        name = n;
    };
    Account(double b) {
        balance = b;
    };

    void set_balance(double b);
    double get_balance();
    void set_name(std::string n);
    string get_name();
    bool deposit(double amount);
    bool withdraw(double amount);

    // Destructor
    ~Account() {};
};

#endif