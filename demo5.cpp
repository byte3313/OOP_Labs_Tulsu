// demo5.cpp
// Демонстрационная программа для работы с перегруженными операторами
#include "lab5.h"
#include <iostream>

using namespace std;

namespace Lab5 {
	// Подпрограмма вывода приветственного меню
	void PrintMenu()
	{
		cout << "Демонстрационная программа для работы с классом CMPLX." << endl;
		cout << "Доступные действия:" << endl;
		cout << "  1 - Перегрузка функции Div (деление на вещественное число);" << endl;
		cout << "  2 - Перегрузка оператора / (деление комплексных чисел);" << endl;
		cout << "  3 - Перегрузка оператора -- (декремент модуля);" << endl;
		cout << "  4 - Проверка +, -, *, == для z1 и z2 (значения в коде программы);" << endl;
		cout << "  5 - Проверка new и delete;" << endl;
		cout << "  0 - выход из программы." << endl;
		cout << endl;
	}

	void Run()
	{
		CMPLX a, b, res;
		float re, im, div_val;
		int choice;

		do
		{
			PrintMenu();
			cout << "Введите номер действия (0-5): ";
			if (!(cin >> choice))
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Некорректный ввод!" << endl << endl;
				continue;
			}

			switch (choice)
			{
			case 1:
			{
				cout << "Введите действительную часть делимого: "; cin >> re;
				cout << "Введите мнимую часть делимого: "; cin >> im;
				a.Setcompl(re, im);
				cout << "Введите вещественный делитель: "; cin >> div_val;
				res = a.Div(div_val);
				cout << "Результат a.Div(float): ";
				res.Print();
				break;
			}
			case 2:
			{
				cout << "Введите действительную часть делимого: "; cin >> re;
				cout << "Введите мнимую часть делимого: "; cin >> im;
				a.Setcompl(re, im);
				cout << "Введите действительную часть делителя: "; cin >> re;
				cout << "Введите мнимую часть делителя: "; cin >> im;
				b.Setcompl(re, im);
				res = a / b;
				cout << "Результат деления через оператор / : ";
				res.Print();
				break;
			}
			case 3:
			{
				cout << "Введите действительную часть числа: "; cin >> re;
				cout << "Введите мнимую часть числа: "; cin >> im;
				a.Setcompl(re, im);
				cout << "Исходное число: ";
				a.Print();
				cout << "Результат префиксного декремента (--a): ";
				(--a).Print();
				cout << "Само число сейчас: ";
				a.Print();
				cout << "Результат постфиксного декремента (a--): ";
				(a--).Print();
				cout << "Само число после операции: ";
				a.Print();
				break;
			}
			case 4:
			{
				cout << "--- Демонстрация дополнительных перегрузок ---" << endl;
				CMPLX z1(1, 2);
				CMPLX z2(3, 4);

				cout << "z1 = "; z1.Print();
				cout << "z2 = "; z2.Print();

				CMPLX z3 = z1 + z2;
				cout << "z1 + z2 = "; z3.Print();

				CMPLX z4 = z1 - z2;
				cout << "z1 - z2 = "; z4.Print();

				CMPLX z5 = z1 * z2;
				cout << "z1 * z2 = "; z5.Print();

				if (z1 == z2) {
					cout << "z1 и z2 равны!" << endl;
				}
				else {
					cout << "z1 и z2 НЕ равны!" << endl;
				}

				// Демонстрация оператора ()
				cout << "Изменяем z1 с помощью оператора ()..." << endl;
				z1(10, 20); // Вызов оператора ()
				cout << "Новое значение z1: ";
				z1.Print();
			}
			case 5:
			{
				cout << "--- Демонстрация перегрузки new и delete ---" << endl;

				cout << "1. Вызываем оператор new для создания объекта в динамической памяти:" << endl;
				// Здесь сработает наш перегруженный operator new, а затем конструктор
				CMPLX* ptr = new CMPLX(7, 8);
				cout << "Объект успешно создан: ";
				ptr->Print();
				cout << "2. Вызываем оператор delete для удаления объекта:" << endl;
				// Здесь сработает деструктор, а затем наш перегруженный operator delete
				delete ptr;
				cout << "Удаление завершено." << endl;
			}
			case 0:
				cout << "Завершение работы программы." << endl;
				break;
			default:
				cout << "Введено неверное значение! Допустимые значения: 0, 1, 2, 3." << endl;
			}
			cout << endl;
		} while (choice != 0);

		return;
	}
}