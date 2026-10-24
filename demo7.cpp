// demo7.cpp
#include "lab7.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace Lab7 {

    // Создаем объект манипулятора
    MyFormat myfmt;

    void Run()
    {
        cout << "--- ЧАСТЬ 1. Потоковый ввод/вывод для класса CMPLX ---" << endl;
        CMPLX z;
        cout << "Введите действительную и мнимую части комплексного числа через пробел: ";
        cin >> z;

        if (cin.fail()) {
            cout << "Ошибка ввода комплексного числа!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else {
            cout << "Вы ввели: " << z << endl << endl;
        }

        cout << "--- ЧАСТЬ 2. Форматированный ввод/вывод последовательности ---" << endl;
        cout << "Введите последовательность (c1 c2 f1 f2 i) через пробел:" << endl;

        MyTuple data;
        cin >> data;

        char c1, c2;
        float f1, f2;
        int i;
        std::tie(c1, c2, f1, f2, i) = data;

        auto print_formatted = [&](ostream& os) {
            os << myfmt << i << " "
                << myfmt << c1 << " "
                << myfmt << c2 << " "
                << myfmt << f1 << " "
                << myfmt << f2 << endl;
            };

        cout << "\nРезультат форматированного вывода на экран:" << endl;
        print_formatted(cout);

        ofstream outFile("output.txt");
        if (outFile.is_open()) {
            print_formatted(outFile);
            outFile.close();
            cout << "\nРезультат успешно записан в файл 'output.txt'." << endl;
        }
        else {
            cout << "\nОшибка открытия файла для записи!" << endl;
        }

        return;
    }
}