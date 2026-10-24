// ConsoleApplication1.cpp
// Демонстрационная программа для класса CMPLX (вариант 12)
// Операции: инициализация/изменение числа, декремент модуля, деление чисел
#include "lab1.h"
#include <iostream>

using namespace std;

namespace Lab1 {

	void Run()
	{
		CMPLX a, b, res; // рабочие комплексные числа
		float re, im;
		int choice;

		cout << "Демонстрационная программа для работы с комплексными числами (класс CMPLX)." << endl;
		cout << "Доступные действия:" << endl;
		cout << "  1 - задать (изменить) комплексное число и вывести его;" << endl;
		cout << "  2 - декремент модуля комплексного числа: |z| = |z| - 1;" << endl;
		cout << "  3 - деление одного комплексного числа на другое;" << endl;
		cout << "  4 - сложение двух комплексных чисел;" << endl;
		cout << "  5 - демонстрация конструктора копирования;" << endl;
		cout << "  0 - выход из программы." << endl;
		cout << endl;

		do
		{
			cout << "Введите номер действия (0-5): ";
			if (!(cin >> choice))
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Некорректный ввод!" << endl;
				continue;
			}

			switch (choice)
			{
			case 1:
			{
				cout << "Введите действительную часть числа: ";
				cin >> re;
				cout << "Введите мнимую часть числа: ";
				cin >> im;
				a.Setcompl(re, im);
				cout << "Комплексное число установлено: ";
				a.Print();
				break;
			}
			case 2:
			{
				cout << "Введите действительную часть числа: ";
				cin >> re;
				cout << "Введите мнимую часть числа: ";
				cin >> im;
				a.Setcompl(re, im);
				cout << "Исходное число: ";
				a.Print();
				a.Dec();
				cout << "Число после декремента модуля: ";
				a.Print();
				break;
			}
			case 3:
			{
				cout << "Введите действительную часть делимого: ";
				cin >> re;
				cout << "Введите мнимую часть делимого: ";
				cin >> im;
				a.Setcompl(re, im);
				cout << "Введите действительную часть делителя: ";
				cin >> re;
				cout << "Введите мнимую часть делителя: ";
				cin >> im;
				b.Setcompl(re, im);
				res = a.Div(b);
				cout << "Результат деления: ";
				res.Print();
				break;
			}
			case 4:
			{
				cout << "Введите действительную часть первого слагаемого: ";
				cin >> re;
				cout << "Введите мнимую часть первого слагаемого: ";
				cin >> im;
				a.Setcompl(re, im);
				cout << "Введите действительную часть второго слагаемого: ";
				cin >> re;
				cout << "Введите мнимую часть второго слагаемого: ";
				cin >> im;
				b.Setcompl(re, im);
				res = a.Add(b);
				cout << "Результат сложения: ";
				res.Print();
				break;
			}
			case 5:
			{
				cout << "Введите действительную часть числа: ";
				cin >> re;
				cout << "Введите мнимую часть числа: ";
				cin >> im;

				cout << endl << "1) Создаём исходное число через конструктор с параметрами:" << endl;
				CMPLX original(re, im); // вызывается конструктор №2 (real, imag)
				cout << "   original = ";
				original.Print();

				cout << endl << "2) Создаём копию через конструктор копирования (CMPLX copy(original);):" << endl;
				CMPLX copy(original); // явный вызов конструктора копирования

				cout << endl << "3) Меняем ТОЛЬКО оригинал и печатаем оба числа:" << endl;
				original.Setcompl(re + 1, im + 1);
				cout << "   original (изменённый) = ";
				original.Print();
				cout << "   copy (осталась прежней) = ";
				copy.Print();
				cout << "Это показывает, что copy — отдельный объект со своей памятью," << endl;
				cout << "а не просто ещё одно имя для original." << endl;
				break;
			}
			case 0:
				cout << "Завершение работы программы." << endl;
				break;
			default:
				cout << "Введено неверное значение! Допустимые значения: 0, 1, 2, 3, 4, 5." << endl;
			}
			cout << endl;
		} while (choice != 0);

		return;
	}
}