#include "f.h"

int moveToLeft(int m) {
    cout << "���� ������ �������� ����, �� ������� 1:";
    int answer;
    cin >> answer;
    if (answer == 1) {
        cout << "������� ���������� ���:";
        int howMuch;
        cin >> howMuch;
        m += howMuch;
    }
    return m;
}

int sizeOfTypes() {
    cout << setfill(' ') << setw(74) << "������ ������ ����� ������" << "\n";
    cout << "��� ������ int �������� " << sizeof(int) << " �����" << endl;
    cout << "��� ������ short int �������� " << sizeof(short int) << " �����" << endl;
    cout << "��� ������ long int �������� " << sizeof(long int) << " �����" << endl;
    cout << "��� ������ float �������� " << sizeof(float) << " �����" << endl;
    cout << "��� ������ double �������� " << sizeof(double) << " ����" << endl;
    cout << "��� ������ char �������� " << sizeof(char) << " ����" << endl;
    cout << "��� ������ bool �������� " << sizeof(bool) << " ����" << "\n";
    return (0);
}
