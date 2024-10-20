//
//  main.cpp
//  дз 3
//
//  Created by Егор Джемлиханов on 16.09.2024.
//

#include <iostream>
#include "MyString.hpp"
using namespace std;

int main()
{

    MyString a({'H', 'e', 'l', 'l', 'o'});
    cout << "Строка a: " << a << endl;

    MyString b;
    b = "Hello " + a;
    cout << "b после конкатенации: " << b << endl;

    a += " world";
    cout << "a после +=: " << a << endl;

    return 0;
}
