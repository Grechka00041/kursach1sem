#pragma once

#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <limits>
using namespace std;

int checkInputPointers(int floor = (numeric_limits<int>::min)(), int ceiling = (numeric_limits<int>::max)());
void quickSort(int* begin, int* end);
void combSort(int* arr, int N);
void insertSort(int* arr, int N);
void shakerSort(int* arr, int N);
void bubbleSort(int* arr, int N);
void mainMenuPointers();
void choosingSortMenuPointers();
void swapPointers(int* p1, int* p2);
int matrixSize();
void printArr(int* arr, int N);
void minusMatrix();
void changeElements(int* arr, int N, int move, int num);
void fillMatrixWorm(int* arr, int N);
void fillMatrixSpiral(int* arr, int N);
void swapBlocks(int* arr, int n);
