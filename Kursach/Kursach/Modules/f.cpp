#include "f.h"

int moveToLeft(int m) {
    cout << "Если хотите сдвинуть биты, то нажмите 1:";
    int answer;
    cin >> answer;
    if (answer == 1) {
        cout << "Введите количество бит:";
        int howMuch;
        cin >> howMuch;
        m += howMuch;
    }
    return m;
}

int sizeOfTypes() {
    cout << setfill(' ') << setw(74) << "Размер разных типов данных" << "\n";
    cout << "Тип данных int занимает " << sizeof(int) << " байта" << endl;
    cout << "Тип данных short int занимает " << sizeof(short int) << " байта" << endl;
    cout << "Тип данных long int занимает " << sizeof(long int) << " байта" << endl;
    cout << "Тип данных float занимает " << sizeof(float) << " байта" << endl;
    cout << "Тип данных double занимает " << sizeof(double) << " байт" << endl;
    cout << "Тип данных char занимает " << sizeof(char) << " байт" << endl;
    cout << "Тип данных bool занимает " << sizeof(bool) << " байт" << "\n";
    return (0);
}
