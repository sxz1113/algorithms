#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class MyString
{
private:
    char *str;
public:
    MyString();
    MyString(const char *s);
    // cp constructor
    MyString(const MyString &that);
    // mv constructor
    MyString(MyString &&that);
    ~MyString();

    // cp assignment
    MyString &operator=(const MyString &that);
    // mv assignment
    MyString &operator=(MyString &&that);

    void display() const;
    int get_length() const;
    const char *get_str() const;
};

#endif