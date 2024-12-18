#include "Module1.2Functions.h"
int binarySearch(int arr[], int value, int start, int end) {
    if (end >= start) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == value) {
            return mid;
        }
        if (arr[mid] > value) {
            return binarySearch(arr, value, start, mid - 1);
        }
        return binarySearch(arr, value, mid + 1, end);
    }
    return -1;
}
void mainMenuArrays() {
    system("cls");
    cout << "Выберите действие: " << endl;
    cout << "1. Создать новый массив" << endl;
    cout << "2. Вывести элементы массива" << endl;
    cout << "3. Сортировка массива, поиск максимального и минимального элементов, поиск индексов и количества элементов, равных среднему значению максимального и минимального" << endl;
    cout << "4. Найти в отсортированном массиве количество элементов, которые меньше введенного вами числа" << endl;
    cout << "5. Найти в отсортированном массиве количество элементов, которые больше введенного вами числа" << endl;
    cout << "6. Бинарный поиск введенного числа в массиве" << endl;
    cout << "7. Поменять элементы массива местами" << endl;
    cout << "8. Уменьшить нечетные элементы на выбранное значение, умножить их на рандомное число, вывести делимость элементов " << endl;
    cout << "9. Выход" << endl;
    cout << "Введите число, соответствующее нужному вам действию: ";
}
void choosingSortMenuArrays() {
    system("cls");
    cout << "Выберите сортировку: " << endl;
    cout << "1. Bubble sort " << endl;
    cout << "2. Shaker sort" << endl;
    cout << "3. Comb sort" << endl;
    cout << "4. Insert sort" << endl;
    cout << "5. Quick sort" << endl;
    cout << "6. Выход" << endl;
    cout << "Введите число, соответствующее нужному вам действию: ";
}
int checkInputArrays(int ceiling, int floor) {
    int num;
    cin >> num;
    while (cin.fail() || cin.peek() != '\n' || num > ceiling || num < floor) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Введите корректное значение: ";
        cin >> num;
    }
    return num;
}
void MinMaxAverage(int arr[], int N) {
    int arrMax = arr[0], arrMin = arr[0], average = 0, amount = 0;
    auto start = steady_clock::now();
    for (int i = 1; i < N; i++)
    {
        if (arr[i] > arrMax)
            arrMax = arr[i];
        if (arr[i] < arrMin)
            arrMin = arr[i];
    }
    average = (arrMax + arrMin) / 2;
    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);
    cout << "максимальный элемент: " << arrMax;
    cout << ", минимальный элемент: " << arrMin << endl;
    cout << "Среднее значение максимального и минимального элементов: " << average << endl;
    cout << "Bремя на поиск: " << duration_cast<nanoseconds>(end - start).count() << '\n';
    cout << "Индексы всех элементов, равных среднему значению: ";
    auto start1 = steady_clock::now();
    for (int i = 0; i < N; ++i) {
        if (arr[i] == average) {
            amount = amount + 1;
            cout << i << " ";
        }
    }
    cout << endl;
    auto end1 = steady_clock::now();
    auto result1 = duration_cast<nanoseconds>(end1 - start1);
    cout << "Поиск занял " << duration_cast<nanoseconds>(end1 - start1).count() << " нс" << endl;
    cout << "Всего нашлось подходящих элементов: " << amount << endl;
}
void MinMaxAverageForSorted(int arr[], int N) {
    int average = 0, amount = 0;
    auto start = steady_clock::now();
    int arrMax = arr[N - 1], arrMin = arr[0];
    average = (arrMax + arrMin) / 2;
    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);
    cout << "максимальный элемент: " << arrMax;
    cout << ", минимальный элемент: " << arrMin << endl;
    cout << "Среднее значение максимального и минимального элементов: " << average << endl;
    cout << "Bремя на поиск: " << duration_cast<nanoseconds>(end - start).count() << '\n';
    cout << "Индексы всех элементов, равных среднему значению: ";
    auto start1 = steady_clock::now();
    int index = binarySearch(arr, average, 0, 99);
    if (index != -1) {
        cout << index << " ";
        amount += 1;
        for (int i = 1; i < N - index; i++) {
            if (arr[index + i] == arr[index]) {
                cout << index + i << " ";
                amount++;
            }
            else if (arr[index - i] == arr[index]) {
                cout << index - i << " ";
                amount++;
            }
            else
                break;
        }
    }
    auto end1 = steady_clock::now();
    auto result1 = duration_cast<nanoseconds>(end1 - start1);
    cout << endl;
    cout << "Поиск занял " << duration_cast<nanoseconds>(end1 - start1).count() << " нс" << endl;
    cout << "Всего нашлось подходящих элементов: " << amount << endl;
}
void quickSort(int* arr, int  end, int begin) {
    int left = begin, right = end;
    int mid = arr[(left + right) / 2];
    while (left < right)
    {
        while (arr[left] < mid) left++;
        while (arr[right] > mid) right--;
        if (left <= right)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    if (begin < right) {
        quickSort(arr, right, begin);
    }
    if (left < end) {
        quickSort(arr, end, left);
    }
}
void combSort(int arr[], int N) {
    auto start1 = steady_clock::now();
    int swap, count = 0;
    float k = 1.247, S = N - 1;
    while (S >= 1)
    {
        for (int i = 0; i + S < N; i++)
        {
            if (arr[i] > arr[int(i + S)])
            {
                swap = arr[int(i + S)];
                arr[int(i + S)] = arr[i];
                arr[i] = swap;
            }
        }
        S /= k;
    }

    while (true)
    {
        for (int i = 0; i < N - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = swap;
            }
            else count++;
        }
        if (count == N - 1)
            break;
        else
            count = 0;
    }
    auto end1 = steady_clock::now();
    auto result1 = duration_cast<nanoseconds>(end1 - start1);
    cout << "Сортировка заняла " << duration_cast<nanoseconds>(end1 - start1).count() << " нс" << endl;
}
void insertSort(int arr[], int n) {
    auto start1 = steady_clock::now();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    auto end1 = steady_clock::now();
    auto result1 = duration_cast<nanoseconds>(end1 - start1);
    cout << "Сортировка заняла " << duration_cast<nanoseconds>(end1 - start1).count() << " нс" << endl;
}
void ShakerSort(int arr[], int n) {
    auto start1 = steady_clock::now();
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
    auto end1 = steady_clock::now();
    auto result1 = duration_cast<nanoseconds>(end1 - start1);
    cout << "Сортировка заняла " << duration_cast<nanoseconds>(end1 - start1).count() << " нс" << endl;
}
void bubbleSort(int arr[], int n) {
    auto start1 = steady_clock::now();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j + 1] < arr[j])
            {
                swap(arr[j], arr[j + 1]);
            }
    }
    auto end1 = steady_clock::now();
    auto result1 = duration_cast<nanoseconds>(end1 - start1);
    cout << "Сортировка заняла " << duration_cast<nanoseconds>(end1 - start1).count() << " нс" << endl;
}