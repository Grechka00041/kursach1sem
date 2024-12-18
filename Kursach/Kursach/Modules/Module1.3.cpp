#include <iostream>
#include <Windows.h>
#include <limits>
#include <iomanip>
#include "Module1.3Func.h"
using namespace std;
void pointers() {
    setlocale(0, "");
    srand(time(NULL));
    const int n = 10;
    int N = 6;
    int arr[n][n] = { 0 };
    bool inizialized = 0;
    int choice;
    cin.sync();
    do {
        mainMenuPointers();
        choice = checkInputPointers(1, 8);
        switch (choice) {
        case 1: {
            system("cls");
            N = matrixSize();
            break;
        }
        case 2: {
            system("cls");
            fillMatrixSpiral(*arr, N);
            cout << "Массив:";
            printArr(*arr, N);
            inizialized = 1;
            break;
        }
        case 3: {
            system("cls");
            fillMatrixWorm(*arr, N);
            cout << "Массив:";
            printArr(*arr, N);
            inizialized = 1;
            break;
        }
        case 4: {
            system("cls");
            if (!inizialized) {
                cout << "Сначала нужно создать массив" << endl;
                break;
            }
            cout << "Массив до перестановки блоков: " << endl;
            printArr(*arr, N);
            swapBlocks(*arr, N);
            cout << "Массив после перестановки блоков: " << endl;
            printArr(*arr, N);
            break;
        }
        case 5: {
            system("cls");
            if (!inizialized) {
                cout << "Сначала нужно создать массив" << endl;
                break;
            }
            int choice2;
            do {
                choosingSortMenuPointers();
                choice2 = checkInputPointers(1, 6);
                switch (choice2) {
                case 1:
                    cout << "Без сортировки: " << endl;
                    printArr(*arr, N);
                    cout << "\nС сортировкой: " << endl;
                    bubbleSort(*arr, N);
                    printArr(*arr, N);
                    break;
                case 2:
                    cout << "Без сортировки: " << endl;
                    printArr(*arr, N);
                    cout << "\nС сортировкой: " << endl;
                    shakerSort(*arr, N);
                    printArr(*arr, N);
                    break;
                case 3:
                    cout << "Без сортировки: " << endl;
                    printArr(*arr, N);
                    cout << "\nС сортировкой: " << endl;
                    combSort(*arr, N);
                    printArr(*arr, N);
                    break;
                case 4:
                    cout << "Без сортировки: " << endl;
                    printArr(*arr, N);
                    cout << "\nС сортировкой: " << endl;
                    insertSort(*arr, N);
                    printArr(*arr, N);
                    break;
                case 5:
                {
                    cout << "Без сортировки: " << endl;
                    printArr(*arr, N);
                    cout << "\nС сортировкой: " << endl;
                    quickSort(*arr, *arr + N * N - 1);
                    printArr(*arr, N);
                    break;
                }
                }
                if (choice2 != 6)
                    system("pause");

            } while (choice2 != 6);
            if (choice2 == 6)
                continue;
            break;
        }
        case 6: {
            system("cls");
            if (!inizialized) {
                cout << "Сначала нужно создать массив" << endl;
                break;
            }
            cout << "Введите арифметическую операцию(0(+), 1(-), 2(*), 3(/)): ";
            int move;
            cin >> move;
            cout << "Введите число: ";
            int num = checkInputPointers();
            cout << "Матрица до: ";
            printArr(*arr, N);
            cout << endl;
            changeElements(*arr, N, move, num);
            cout << "Матрица после: ";
            printArr(*arr, N);
            break;
        }
        case 7:
            system("cls");
            minusMatrix();
            break;
        }
        if (choice != 8)
            system("pause");
    } while (choice != 8);
}
