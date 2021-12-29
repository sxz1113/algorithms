#include <cstring>
#include <iostream>
#include "MyString.h"

using namespace std;

// constructor
MyString::MyString()
    : str {nullptr} {
    str = new char[1];
    *str = '\0';
}

// overloaded constructor
MyString::MyString(const char *s)
    : str {nullptr} {
    if (s == nullptr)
    {
        str = new char[1];
        *str = '\0';
    } else
    {
        int n = strlen(s);
        str = new char[n + 1];
        strcpy(str, s);
    }
}

// copy constructor
MyString::MyString(const MyString &src)
    : str {nullptr} {
    int n = strlen(src.str);
    str = new char[n + 1];
    strcpy(str, src.str);
}

// destructor
MyString::~MyString() {
    cout << "Calling destructor for string: " << str << endl;
    delete [] str;
}

void MyString::display() const {
    cout << str << ": " << get_length() << endl;
}

int MyString::get_length() const { return strlen(str); }

const char *MyString::get_str() const { return str; }

// Type &Type::operator=(const Type &that);
MyString &MyString::operator=(const MyString &that) {
    cout << "Calling copy assignment" << endl;
    if (this == &that)
        return *this;

    delete [] this->str;
    str = new char[strlen(that.str) + 1];
    strcpy(this->str, that.str);
    return *this;
}

// Type &Type::operator=(Type &&that);
MyString &MyString::operator=(MyString &&that) {
    cout << "Calling move assignment" << endl;
    if (this != &that) {
        delete [] str;
        str = that.str;
        that.str = nullptr;
    }

    return *this;
}
