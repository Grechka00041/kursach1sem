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
    cout << "�������� ��������: " << endl;
    cout << "1. ������� ����� ������" << endl;
    cout << "2. ������� �������� �������" << endl;
    cout << "3. ���������� �������, ����� ������������� � ������������ ���������, ����� �������� � ���������� ���������, ������ �������� �������� ������������� � ������������" << endl;
    cout << "4. ����� � ��������������� ������� ���������� ���������, ������� ������ ���������� ���� �����" << endl;
    cout << "5. ����� � ��������������� ������� ���������� ���������, ������� ������ ���������� ���� �����" << endl;
    cout << "6. �������� ����� ���������� ����� � �������" << endl;
    cout << "7. �������� �������� ������� �������" << endl;
    cout << "8. ��������� �������� �������� �� ��������� ��������, �������� �� �� ��������� �����, ������� ��������� ��������� " << endl;
    cout << "9. �����" << endl;
    cout << "������� �����, ��������������� ������� ��� ��������: ";
}
void choosingSortMenuArrays() {
    system("cls");
    cout << "�������� ����������: " << endl;
    cout << "1. Bubble sort " << endl;
    cout << "2. Shaker sort" << endl;
    cout << "3. Comb sort" << endl;
    cout << "4. Insert sort" << endl;
    cout << "5. Quick sort" << endl;
    cout << "6. �����" << endl;
    cout << "������� �����, ��������������� ������� ��� ��������: ";
}
int checkInputArrays(int ceiling, int floor) {
    int num;
    cin >> num;
    while (cin.fail() || cin.peek() != '\n' || num > ceiling || num < floor) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "������� ���������� ��������: ";
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
    cout << "������������ �������: " << arrMax;
    cout << ", ����������� �������: " << arrMin << endl;
    cout << "������� �������� ������������� � ������������ ���������: " << average << endl;
    cout << "B���� �� �����: " << duration_cast<nanoseconds>(end - start).count() << '\n';
    cout << "������� ���� ���������, ������ �������� ��������: ";
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
    cout << "����� ����� " << duration_cast<nanoseconds>(end1 - start1).count() << " ��" << endl;
    cout << "����� ������� ���������� ���������: " << amount << endl;
}
void MinMaxAverageForSorted(int arr[], int N) {
    int average = 0, amount = 0;
    auto start = steady_clock::now();
    int arrMax = arr[N - 1], arrMin = arr[0];
    average = (arrMax + arrMin) / 2;
    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);
    cout << "������������ �������: " << arrMax;
    cout << ", ����������� �������: " << arrMin << endl;
    cout << "������� �������� ������������� � ������������ ���������: " << average << endl;
    cout << "B���� �� �����: " << duration_cast<nanoseconds>(end - start).count() << '\n';
    cout << "������� ���� ���������, ������ �������� ��������: ";
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
    cout << "����� ����� " << duration_cast<nanoseconds>(end1 - start1).count() << " ��" << endl;
    cout << "����� ������� ���������� ���������: " << amount << endl;
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
    cout << "���������� ������ " << duration_cast<nanoseconds>(end1 - start1).count() << " ��" << endl;
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
    cout << "���������� ������ " << duration_cast<nanoseconds>(end1 - start1).count() << " ��" << endl;
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
    cout << "���������� ������ " << duration_cast<nanoseconds>(end1 - start1).count() << " ��" << endl;
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
    cout << "���������� ������ " << duration_cast<nanoseconds>(end1 - start1).count() << " ��" << endl;
}