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

MyString::~MyString()
{
    delete[] str;
    --objectCount;
}

void MyString::Vhod() 
{
    delete[] str;
    char buff[1000];
    cout << "напишите строку: ";
    cin.getline(buff, 1000);

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

void MyString::MyStrcpy(const MyString& obj)
{
    delete[] str;
    length = obj.MyStrLen() + 1;
    str = new char[length];
    strcpy(str, obj.str);
}

bool MyString::MyStrStr(const char* substr) const 
{
    return strstr(str, substr) != nullptr;
}

int MyString::MyChr(char c) const
{
    for (int i = 0; i < length; i++) 
    {
        if (str[i] == c) 
        {
            return i;
        }
    }
    return -1;
}

int MyString::MyStrLen() const
{
    return strlen(str);
}

void MyString::MyStrCat(const MyString& b)
{
    int newLength = this->MyStrLen() + b.MyStrLen() + 1;
    char* newStr = new char[newLength];
    strcpy(newStr, this->str);
    strcat(newStr, b.str);

    delete[] str;
    str = newStr;
    length = newLength;
}

void MyString::MyDelChr(char c) 
{
    int newLength = 0;
    char* newStr = new char[length];

    for (int i = 0; i < length - 1; i++) 
    {
        if (str[i] != c) 
        {
            newStr[newLength++] = str[i];
        }
    }

    newStr[newLength] = '\0';

    delete[] str;
    str = newStr;
    length = newLength + 1;
}

int MyString::MyStrCmp(const MyString& b) const
{
    int result = strcmp(this->str, b.str);
    if (result < 0) 
    {
        return -1;
    }
    else
        if (result > 0) 
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int MyString::PoluchitKolichestvoObektov()
{
    return objectCount;
}
