#include <iostream>
#include <windows.h>
#include <limits>
#include "Modules/dataTypes.h"
#include "Modules/arrays.h"
#include "Modules/pointers.h"
#include "Modules/strings.h"
using namespace std;
int checkInput(int floor = (numeric_limits<int>::min)(), int ceiling = (numeric_limits<int>::max)()) {
    int num;
    cin >> num;
    while (cin.fail() || cin.peek() != '\n' || num > ceiling || num < floor) {
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        cout << "Введите корректное значение: ";
        cin >> num;
    }
    return num;
}
void mainMenu() {
    system("cls");
    cout << "Выберите действие: " << endl;
    cout << "1. ТИПЫ ДАННЫХ И ИХ ВНУТРЕННЕЕ ПРЕДСТАВЛЕНИЕ В ПАМЯТИ" << endl;
    cout << "2. ОДНОМЕРНЫЕ СТАТИЧЕСКИЕ МАССИВЫ" << endl;
    cout << "3. ДВУМЕРНЫЕ СТАТИЧЕСКИЕ МАССИВЫ. УКАЗАТЕЛИ" << endl;
    cout << "4. ТЕКСТОВЫЕ СТРОКИ КАК МАССИВЫ СИМВОЛОВ" << endl;
    cout << "5. Выход" << endl;
    cout << "Введите число, соответствующее нужному вам действию: ";
}
int main() {
    setlocale(LC_ALL, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    do {
        mainMenu();
        choice = checkInput(1, 10);
        switch (choice) {
        case 1: {
            system("cls");
            dataTypes();
            cout << endl;
            break;
        }
        case 2: {
            system("cls");
            arrays();
            cout << endl;
            break;
        }
        case 3: {
            system("cls");
            pointers();
            cout << endl;
            break;
        }
        case 4: {
            system("cls");
            strings();
            cout << endl;
            break;
        }
        }
        if (choice != 5)
            system("pause");
    } while (choice != 5);
}

