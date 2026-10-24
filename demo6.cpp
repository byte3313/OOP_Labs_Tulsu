// demo6.cpp
// Демонстрационная программа для работы с шаблонным классом
#include "lab6.h"
#include <iostream>

using namespace std;

namespace Lab6 {

    void Run()
    {

        int n;

        // Используем наш вариативный шаблон для вывода
        my_printf("--- Лабораторная работа №% (%) ---\n", 6, "Шаблоны классов и функций");
        my_printf("Вариант : Сначала отрицательные, затем неотрицательные (с сохранением порядка).\n", 10);

        // РАБОТА С ЦЕЛЫМИ ЧИСЛАМИ
        my_printf("\n[1] Работа с целыми числами (тип %):\n", "int");
        my_printf("Введите размер последовательности N: ");

        if (cin >> n && n > 0)
        {
            Sequence<int> intSeq(n);
            my_printf("Введите % целых чисел через пробел: ", n);

            // Здесь вызовется специализированный метод Input(), защищенный от ввода букв
            intSeq.Input();

            my_printf("Исходная последовательность:       ");
            intSeq.Print();

            intSeq.Rearrange();

            my_printf("Преобразованная последовательность: ");
            intSeq.Print();
        }
        else
        {
            my_printf("Некорректный размер!\n");
            cin.clear(); cin.ignore(10000, '\n');
        }

        // РАБОТА С ВЕЩЕСТВЕННЫМИ ЧИСЛАМИ
        my_printf("\n[2] Работа с вещественными числами (тип %):\n", "double");
        my_printf("Введите размер последовательности N: ");

        if (cin >> n && n > 0)
        {
            Sequence<double> doubleSeq(n);
            my_printf("Введите % вещественных чисел через пробел: ", n);

            // Вызовется обычный обобщенный Input()
            doubleSeq.Input();

            my_printf("Исходная последовательность:       ");
            doubleSeq.Print();

            doubleSeq.Rearrange();

            my_printf("Преобразованная последовательность: ");
            doubleSeq.Print();
        }
        else
        {
            my_printf("Некорректный размер!\n");
        }

        my_printf("\nПрограмма завершена.\n");
        return;
    }
}