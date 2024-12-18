﻿#include <iostream>
#include <iomanip>
#include "f.h"
#include <Windows.h>
using namespace std;


int dataTypes() {
    setlocale(0, "");
    sizeOfTypes();
    cout << "\n" << setfill(' ') << setw(85) << "Двоичное представление в памяти целого числа " << "\n";
    cout << "\n" << "Введите любое целое число: ";
    int number;
    cin >> number;
    unsigned int mask = 1 << 31;
    cout << "Ваше число в памяти компьютера выглядит так: ";
    for (int i = 0; i < 32; i++) {
        putchar(number & mask ? '1' : '0');
        mask >>= 1;
        if (i % 8 == 0 || i == 31) {
            putchar(' ');
        }
    }
    cout << endl;
    int moveInt = 0;
    moveInt = moveToLeft(moveInt);
    unsigned int maskIntLeft = 1 << (31 - moveInt);
    if (moveInt > 0) {
        cout << "Ваше число со сдвигом в памяти компьютера выглядит так: ";
        for (int i = 0; i < 32; i++) {
            putchar(number & maskIntLeft ? '1' : '0');
            maskIntLeft >>= 1;
            if (i % 8 == 0 || i == 31) {
                putchar(' ');
            }
        }
    }
    cout << endl;

    cout << "\n" << setfill(' ') << setw(85) << "Двоичное представление в памяти типа float " << endl;
    cout << "\n" << "Введите любое число типа float: ";
    union {
        int tool;
        float numberFloat;
    };
    cin >> numberFloat;
    unsigned int maskFloat = 1 << 31;
    cout << "Ваше число в памяти компьютера выглядит так: ";
    for (int i = 0; i < 32; i++) {
        putchar(tool & maskFloat ? '1' : '0');
        maskFloat >>= 1;
        if (i == 0 || i == 11) {
            putchar(' ');
        }
    }
    cout << endl;
    int moveFloat = 0;
    moveFloat = moveToLeft(moveFloat);
    unsigned int maskFloatLeft = 1 << (31 - moveFloat);
    if (moveFloat > 0) {
        cout << "Ваше число со сдвигом в памяти компьютера выглядит так: ";
        for (int i = 0; i < 32; i++) {
            putchar(tool & maskFloatLeft ? '1' : '0');
            maskFloatLeft >>= 1;
            if (i == 0 || i == 11) {
                putchar(' ');
            }
        }
    }
    cout << endl;

    cout << "\n" << setfill(' ') << setw(85) << "Двоичное представление в памяти числа типа double" << endl;
    cout << "\n" << "Введите любое число типа double: ";

    union {
        unsigned int Double[2];
        double numberDouble;
    };
    cin >> numberDouble;
    unsigned int maskD = 1 << 31;

    cout << "Ваше число в памяти компьютера выглядит так: ";
    for (int i = 0; i <= 32; ++i) {
        putchar(Double[1] & maskD ? '1' : '0');
        maskD >>= 1;
        if (i == 0 || i == 11) {
            putchar(' ');
        }
    }
    maskD = 1 << 31;
    for (int i = 0; i <= 32; ++i) {
        putchar(Double[0] & maskD ? '1' : '0');
        maskD >>= 1;
    }
    cout << endl;

    int moveDouble = 0;
    moveDouble = moveToLeft(moveDouble);
    unsigned int maskDLeft = 1 << (31 - moveDouble);
    if (moveDouble > 0) {
        cout << "Ваше число со сдвигом в памяти компьютера выглядит так: ";
        for (int i = 0; i <= 32; ++i) {
            putchar(Double[1] & maskDLeft ? '1' : '0');
            maskDLeft >>= 1;
            if (i == 0 || i == 11) {
                putchar(' ');
            }
        }
        maskDLeft = 1 << 31;
        for (int i = 0; i <= 32; ++i) {
            putchar(Double[0] & maskDLeft ? '1' : '0');
            maskDLeft >>= 1;
        }
    }
    cout << endl;

    return(0);
}