#pragma once

#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdlib>
#include <limits>


using namespace std;
using namespace chrono;

int binarySearch(int arr[], int value, int start, int end);
void mainMenuArrays();
void choosingSortMenuArrays();
int checkInputArrays(int ceiling = (numeric_limits<int>::max)(), int floor = (numeric_limits<int>::min)());
void MinMaxAverage(int arr[], int N);
void MinMaxAverageForSorted(int arr[], int N);
void quickSort(int* arr, int  end, int begin);
void combSort(int arr[], int N);
void insertSort(int arr[], int n);
void ShakerSort(int arr[], int n);
void bubbleSort(int arr[], int n);