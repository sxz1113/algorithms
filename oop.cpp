#include <iostream>
#include <string>
#include <vector>
#include "Account.h"

using namespace std;

class Move
{
private:
    int *data;
public:
    Move(int d);
    Move(const Move &src);
    Move(Move &&src);
    ~Move();
    int get_data() { return *data; }
    void set_data(int d) { *data = d; }
};

Move::Move(int d)
{
    data = new int;
    *data = d;
    cout << "Constructor for "  << *data << endl;
}

Move::~Move()
{
    if (data != nullptr)
        cout << "Destructor -- free data for " << *data << endl;
    else
        cout << "Destructor -- freeing data for null pointer" << endl;
    delete data;
}

/* Copy constructor
   Move copy */
// Move::Move(const Move &src)
//     : data {src.data} {
//     cout << "copy constructor -- Move" << endl;
// }
/* Deep copy */
// Move::Move(const Move &src) {
//     data = new int; 
//     *data = *src.data;
//      cout << "copy constructor -- deep" << endl;
// }
// With delegation
Move::Move(const Move &src)
    : Move {*src.data} {
        cout << "Deep copy for "  << *data << endl;
}

// Move constructor
Move::Move(Move &&src)
    : data {src.data} {
        // Steal the data and then null out the src pointer
        src.data = nullptr;
        cout << "Move for: " << *data << endl;
}


void disp(Move s) {
    cout << s.get_data() << endl;
}


int main ()
{
    // Account a1;
    // a1.set_balance(1000.);
    // double b = a1.get_balance();
    // a1.deposit(500.);
    // a1.withdraw(9000.);
    // cout << a1.get_name() << endl;

    // Account a2("aoao", 5000);
    // a2.withdraw(3000.);
    // a2.deposit(10000.);
    // cout << a2.get_name() << endl;

    // Account *a3 = new Account("bobo");
    // a3->deposit(12000.);
    // a3->withdraw(2000.);
    // cout << a3->get_name() << endl;
    // delete a3;
    // Move s1 {100};
    // disp(s1);

    // Move s2 {s1};
    // s2.set_data(1000);
    // disp(s2);
    vector<Move> vec;
    vec.push_back(Move {10});
    vec.push_back(Move {20});
    vec.push_back(Move {30});
    
    // vec.push_back(Move {20});
    return 0;
}