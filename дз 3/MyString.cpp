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
    length = strlen(inputStr) + 1;
    str = new char[length];
    strcpy(str, inputStr);
    ++objectCount;
}

MyString::MyString(const MyString& obj)
{
    length = obj.length;
    str = new char[length];
    strcpy(str, obj.str);
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
        strcpy(str, obj.str);
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
    int newLength = MyStrLen() + strlen(rhs) + 1;
    char* newStr = new char[newLength];

    strcpy(newStr, str);
    strcat(newStr, rhs);

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
    cout << "напишите строку: ";
    cin >> buff; 

    length = strlen(buff) + 1;
    str = new char[length];
    strcpy(str, buff);
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

    obj.length = strlen(buff) + 1;
    delete[] obj.str;
    obj.str = new char[obj.length];
    strcpy(obj.str, buff);

    return in;
}

MyString operator+(const char* lhs, const MyString& rhs)
{
    int newLength = strlen(lhs) + rhs.MyStrLen() + 1;
    char* newStr = new char[newLength];

    strcpy(newStr, lhs);
    strcat(newStr, rhs.str);

    MyString result(newStr);
    delete[] newStr;

    return result;
}
