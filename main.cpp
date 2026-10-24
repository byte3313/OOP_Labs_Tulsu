// main.cpp
// Главный файл проекта: Сборник лабораторных работ по ООП (1-7)
// Выполнил: ст. гр. 220441 Локтев Г.А.
#include <iostream>
#if defined(_WIN32)
#include <windows.h>
#endif

// Объявляем функции запуска из пространств имен наших лаб
namespace Lab1 { void Run(); }
namespace Lab2 { void Run(); }
namespace Lab3 { void Run(); }
namespace Lab4 { void Run(); }
namespace Lab5 { void Run(); }
namespace Lab6 { void Run(); }
namespace Lab7 { void Run(); }

using namespace std;

void PrintMainMenu()
{
    cout << "==========================================================" << endl;
    cout << "  СБОРНИК ЛАБОРАТОРНЫХ РАБОТ ПО ООП                       " << endl;
    cout << "  Выполнил: ст. гр. 220441 Локтев Г.А.                    " << endl;
    cout << "==========================================================" << endl;
    cout << "  1 - Лабораторная работа №1 (Классы, конструкторы)" << endl;
    cout << "  2 - Лабораторная работа №2 (Указатели, цепочка)" << endl;
    cout << "  3 - Лабораторная работа №3 (new/delete, массивы)" << endl;
    cout << "  4 - Лабораторная работа №4 (Наследование, полиморфизм)" << endl;
    cout << "  5 - Лабораторная работа №5 (Перегрузка операторов)" << endl;
    cout << "  6 - Лабораторная работа №6 (Шаблоны классов)" << endl;
    cout << "  7 - Лабораторная работа №7 (Потоковый ввод/вывод)" << endl;
    cout << "  0 - Выход из программы" << endl;
    cout << "==========================================================" << endl;
}

int main()
{
#if defined(_WIN32)
    // Устанавливаем кириллицу один раз для всей программы!
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("cls");
#endif

    int choice;

    do
    {
        PrintMainMenu();
        cout << "Выберите номер лабораторной работы (0-7): ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Некорректный ввод! Попробуйте снова.\n\n";
            continue;
        }

        cout << endl;

        switch (choice)
        {
        case 1:
            cout << ">>> ЗАПУСК ЛАБОРАТОРНОЙ РАБОТЫ №1 <<<\n\n";
            Lab1::Run();
            break;
        case 2:
            cout << ">>> ЗАПУСК ЛАБОРАТОРНОЙ РАБОТЫ №2 <<<\n\n";
            Lab2::Run();
            break;
        case 3:
            cout << ">>> ЗАПУСК ЛАБОРАТОРНОЙ РАБОТЫ №3 <<<\n\n";
            Lab3::Run();
            break;
        case 4:
            cout << ">>> ЗАПУСК ЛАБОРАТОРНОЙ РАБОТЫ №4 <<<\n\n";
            Lab4::Run();
            break;
        case 5:
            cout << ">>> ЗАПУСК ЛАБОРАТОРНОЙ РАБОТЫ №5 <<<\n\n";
            Lab5::Run();
            break;
        case 6:
            cout << ">>> ЗАПУСК ЛАБОРАТОРНОЙ РАБОТЫ №6 <<<\n\n";
            Lab6::Run();
            break;
        case 7:
            cout << ">>> ЗАПУСК ЛАБОРАТОРНОЙ РАБОТЫ №7 <<<\n\n";
            Lab7::Run();
            break;
        case 0:
            cout << "Завершение работы программы.\n";
            break;
        default:
            cout << "Введено неверное значение! Допустимые значения: 0-7.\n";
        }

        if (choice != 0) {
            cout << "\n==========================================================" << endl;
            cout << "Возврат в главное меню...\n\n";
        }

    } while (choice != 0);

    return 0;
}