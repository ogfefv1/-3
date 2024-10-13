//
//  MyString.hpp
//  дз 3
//
//  Created by Егор Джемлиханов on 16.09.2024.
//

#pragma once
#include <iostream>
using namespace std;

class MyString
{
    char* str;
    int length;
    static int objectCount;

public:
    MyString();
    MyString(int size);
    MyString(const char* inputStr);
    MyString(const MyString& obj);
    MyString(MyString& obj);
    ~MyString();

    MyString& operator=(const MyString& obj);
    MyString& operator=(MyString& obj);
    MyString& operator+=(const char* rhs);           

    char& operator[](int index);
    void operator()() const;

    void Vhod();
    void Vihod() const;
    void MyStrcpy(const MyString& obj);
    bool MyStrStr(const char* substr) const;
    int MyChr(char c) const;
    int MyStrLen() const;
    void MyStrCat(const MyString& b);
    void MyDelChr(char c);
    int MyStrCmp(const MyString& b) const;
    static int PoluchitKolichestvoObektov();

    friend ostream& operator<<(ostream& out, const MyString& obj);
    friend istream& operator>>(istream& in, MyString& obj);
    friend MyString operator+(const char* lhs, const MyString& rhs);
};
