#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdlib>
#include <limits>
#include "Module1.2Functions.h"

using namespace std;
using namespace chrono;

int arrays() {
    setlocale(0, "");
    srand(time(NULL));
    const int n = 100;
    int A[n];
    int size = sizeof(A) / sizeof(A[0]);
    unsigned int startRand = -99;
    int endRand = 99;
    for (int i = 0; i < n; ++i)
        A[i] = rand() % (endRand - startRand + 1) + startRand;
    cin.sync();
    int choice;
    do {
        mainMenuArrays();
        choice = checkInputArrays(9, 1);
        int endSort = n - 1, beginSort = 0;
        switch (choice) {
        case 1:
            cout << "Вот новый массив: ";
            for (int i = 0; i < n; ++i) {
                A[i] = rand() % (endRand - startRand + 1) + startRand;
                cout << A[i] << ' ';
            }
            cout << endl;
            break;

        case 2:
            cout << "Вот все элементы массива: ";
            for (int i = 0; i < n; ++i)
                cout << A[i] << " ";
            cout << endl;
            break;
        case 3:
            int choice2;
            do {
                choosingSortMenuArrays();
                choice2 = checkInputArrays(6, 1);
                switch (choice2) {
                case 1:
                    cout << "Без сортировки: " << endl;
                    MinMaxAverage(A, n);
                    bubbleSort(A, n);
                    cout << "\nС сортировкой: " << endl;
                    MinMaxAverageForSorted(A, n);
                    break;
                case 2:
                    cout << "Без сортировки: " << endl;
                    MinMaxAverage(A, n);
                    ShakerSort(A, n);
                    cout << "\nС сортировкой: " << endl;
                    MinMaxAverageForSorted(A, n);
                    break;
                case 3:
                    cout << "Без сортировки: " << endl;
                    MinMaxAverage(A, n);
                    combSort(A, n);
                    cout << "\nС сортировкой: " << endl;
                    MinMaxAverageForSorted(A, n);
                    break;
                case 4:
                    cout << "Без сортировки: " << endl;
                    MinMaxAverage(A, n);
                    insertSort(A, n);
                    cout << "\nС сортировкой: " << endl;
                    MinMaxAverageForSorted(A, n);
                    break;
                case 5:
                {
                    cout << "Без сортировки: " << endl;
                    MinMaxAverage(A, n);
                    auto start1 = steady_clock::now();
                    quickSort(A, endSort, beginSort);
                    auto end1 = steady_clock::now();
                    auto result1 = duration_cast<nanoseconds>(end1 - start1);
                    cout << "Сортировка заняла " << duration_cast<nanoseconds>(end1 - start1).count() << " нс" << endl;
                    cout << "\nС сортировкой: " << endl;
                    MinMaxAverageForSorted(A, n);
                    break;
                }
                }
                if (choice2 != 6)
                    system("pause");

            } while (choice2 != 6);
            if (choice2 == 6)
                continue;
        case 4:
        {
            cout << "Введите число: ";
            int num = checkInputArrays();
            quickSort(A, endSort, beginSort);
            int count = 0;
            for (int i = 0; i < n; ++i) {
                if (A[i] < num)
                    count += 1;
                else
                    break;
            }
            cout << "Чисел, меньше вашего: " << count << endl;
            break;
        }
        case 5:
        {
            cout << "Введите число: ";
            int num = checkInputArrays();
            quickSort(A, endSort, beginSort);
            int count = 0;
            for (int i = n - 1; i >= 0; --i) {
                if (A[i] > num)
                    count += 1;
                else
                    break;
            }
            cout << "Чисел, больше вашего: " << count << endl;
            break;
        }
        case 6:
        {
            cout << "Введите число, которое вы ищите: ";
            int value = checkInputArrays();
            cout << "Поиск перебором: " << endl;
            bool flag = 0;
            auto start = steady_clock::now();
            for (int i = 0; i < n; i++) {
                if (A[i] == value) {
                    flag = 1;
                    break;
                }
            }
            auto end = steady_clock::now();
            auto result = duration_cast<nanoseconds>(end - start);
            if (flag) {
                cout << "Элемент был найден " << endl;
            }
            else {
                cout << "Элемент не найден" << endl;
            }
            cout << "Поиск занял " << duration_cast<nanoseconds>(end - start).count() << " нс" << endl;
            quickSort(A, endSort, beginSort);
            cout << "Бинарный поиск: " << endl;
            auto startB = steady_clock::now();
            int reply = binarySearch(A, value, 0, size - 1);
            auto endB = steady_clock::now();
            auto resultB = duration_cast<nanoseconds>(endB - startB);
            if (reply == -1) {
                cout << "Элемент не найден" << endl;
            }
            else {
                cout << "Элемент был найден " << endl;
            }
            cout << "Поиск занял " << duration_cast<nanoseconds>(endB - startB).count() << " нс" << endl;
            break;
        }
        case 7:
        {
            int index1, index2;
            cout << "Введите индексы элементов массива, которые вы хотите поменять местами" << endl;
            cout << "Первый индекс: ";
            index1 = checkInputArrays();
            cout << "Второй индекс: ";
            index2 = checkInputArrays();
            auto start1 = steady_clock::now();
            swap(A[index1], A[index2]);
            auto end1 = steady_clock::now();
            auto result1 = duration_cast<nanoseconds>(end1 - start1);
            cout << "Перестановка заняла " << duration_cast<nanoseconds>(end1 - start1).count() << " нс" << endl;
            cout << "Измененный массив выглядит так: " << endl;
            for (int i = 0; i < n; ++i)
                cout << A[i] << "; ";
            cout << endl;
            break;

        }
        case 8:
        {
            cout << "Введите на какое значение уменьшить нечетные элементы массива: ";
            int num = checkInputArrays();
            int randNum = ((rand() % 9) + 1);
            cout << "Рандомное число: " << randNum << endl;
            for (int i = 1; i < n; i += 2) {
                A[i] = (A[i] - num) * randNum;
            }
            cout << "Измененный массив выглядит так: ";
            for (int i = 0; i < n; ++i)
                cout << A[i] << "; ";
            cout << endl;
            cout << "Количество элементов, которые нацело делятся на " << endl;
            int count = 0;
            cout << "1: " << n << endl;
            for (int i = 2; i < 9; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (A[j] % i == 0)
                        count += 1;
                }
                cout << i << ": " << count << endl;
                count = 0;
            }
            break;
        }
        }
        if (choice != 9)
            system("pause");
    } while (choice != 9);
    return 0;
}
