//
//  MyString.cpp
//  дз 3
//
//  Created by Егор Джемлиханов on 16.09.2024.
//

#include "MyString.hpp"
#include <iostream>

using namespace std;

int MyString::objectCount = 0;

MyString::MyString()
{
    length = 80;
    str = new char[length];
    str[0] = '\0';
    ++objectCount;
}

MyString::MyString(int size)
{
    length = size;
    str = new char[length];
    str[0] = '\0';
    ++objectCount;
}

MyString::MyString(const char* inputStr)
{
    length = 0;
    while (inputStr[length] != '\0')
    {
        ++length;
    }
    ++length;

    str = new char[length];
    for (int i = 0; i < length; ++i)
    {
        str[i] = inputStr[i];
    }
    ++objectCount;
}

MyString::MyString(initializer_list<char> list)
{
    length = list.size() + 1;
    str = new char[length];

    int i = 0;
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        str[i++] = *it;
    }
    str[i] = '\0';
    ++objectCount;
}

MyString::MyString(const MyString& obj)
{
    length = obj.length;
    str = new char[length];
    for (int i = 0; i < length; ++i)
    {
        str[i] = obj.str[i];
    }
    ++objectCount;
}

MyString::MyString(MyString& obj)
{
    str = obj.str;
    length = obj.length;
    obj.str = nullptr;
    obj.length = 0;
}

MyString::~MyString()
{
    delete[] str;
    --objectCount;
}

MyString& MyString::operator=(const MyString& obj)
{
    if (this != &obj)
    {
        delete[] str;
        length = obj.length;
        str = new char[length];
        for (int i = 0; i < length; ++i)
        {
            str[i] = obj.str[i];
        }
    }
    return *this;
}

MyString& MyString::operator=(MyString& obj)
{
    if (this != &obj)
    {
        delete[] str;
        str = obj.str;
        length = obj.length;

        obj.str = nullptr;
        obj.length = 0;
    }
    return *this;
}

MyString& MyString::operator+=(const char* rhs)
{
    int rhsLength = 0;
    while (rhs[rhsLength] != '\0')
    {
        ++rhsLength;
    }
    int newLength = MyStrLen() + rhsLength + 1;
    char* newStr = new char[newLength];

    for (int i = 0; i < MyStrLen(); ++i)
    {
        newStr[i] = str[i];
    }
    for (int i = 0; i < rhsLength; ++i)
    {
        newStr[MyStrLen() + i] = rhs[i];
    }
    newStr[newLength - 1] = '\0';

    delete[] str;
    str = newStr;
    length = newLength;

    return *this;
}

char& MyString::operator[](int index)
{
    if (index >= 0 && index < length - 1)
        return str[index];
    return str[0];
}

void MyString::operator()() const
{
    Vihod();
}

void MyString::Vhod()
{
    delete[] str;
    char buff[1000];
    cout << "Введите строку: ";
    cin >> buff;

    length = 0;
    while (buff[length] != '\0')
    {
        ++length;
    }
    ++length;

    str = new char[length];
    for (int i = 0; i < length; ++i)
    {
        str[i] = buff[i];
    }
}

void MyString::Vihod() const
{
    if (str != nullptr)
    {
        cout << str << endl;
    }
    else
    {
        cout << "строка пустая" << endl;
    }
}

int MyString::MyStrLen() const
{
    int len = 0;
    while (str[len] != '\0')
    {
        ++len;
    }
    return len;
}

ostream& operator<<(ostream& out, const MyString& obj)
{
    if (obj.str != nullptr)
        out << obj.str;
    else
        out << "строка пустая";
    return out;
}

istream& operator>>(istream& in, MyString& obj)
{
    char buff[1000];
    in.getline(buff, 1000);

    int len = 0;
    while (buff[len] != '\0')
    {
        ++len;
    }
    len++;

    delete[] obj.str;
    obj.str = new char[len];
    for (int i = 0; i < len; ++i)
    {
        obj.str[i] = buff[i];
    }
    obj.length = len;

    return in;
}

MyString operator+(const char* lhs, const MyString& rhs)
{
    int lhsLength = 0;
    while (lhs[lhsLength] != '\0')
    {
        ++lhsLength;
    }
    int newLength = lhsLength + rhs.MyStrLen() + 1;
    char* newStr = new char[newLength];

    for (int i = 0; i < lhsLength; ++i)
    {
        newStr[i] = lhs[i];
    }
    for (int i = 0; i < rhs.MyStrLen(); ++i)
    {
        newStr[lhsLength + i] = rhs.str[i];
    }
    newStr[newLength - 1] = '\0';

    MyString result(newStr);
    delete[] newStr;

    return result;
}
