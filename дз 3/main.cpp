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
    MyString str1;
    MyString str2;
    MyString str3;

    cout << "напишите строку для str3 (стартовая строка): ";
    str3.Vhod();

    cout << "напишите строку для str1: ";
    str1.Vhod();

    cout << "напишите строку для str2: ";
    str2.Vhod();

    cout << "начальная строка str3: ";
    str3.Vihod();

    cout << "обновлена ​​строка str1: ";
    str1.Vihod();

    cout << "обновлена ​​строка str2: ";
    str2.Vihod();

    MyString str4;
    str4.MyStrcpy(str1);
    cout << "скопирована строка str4 из str1: ";
    str4.Vihod();

    MyString result = str3;
    result.MyStrCat(str1);
    result.MyStrCat(str2);
    cout << "результат конкатенации строк: ";
    result.Vihod();

    cout << "количество объектов MyString: " << MyString::PoluchitKolichestvoObektov() << endl;


    return 0;
}
