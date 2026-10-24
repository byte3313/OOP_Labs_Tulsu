// lab6.h
// Шаблонный класс для работы с числовыми последовательностями
// Вариант 10: отрицательные числа в начало, неотрицательные в конец (без сортировки)
#pragma once
#include <iostream>
#include <string>
#include <cctype>

namespace Lab6 {

    // ВАРИАТИВНЫЙ ШАБЛОН: Собственная реализация printf

    // Базовый случай рекурсии: вызывается, когда переданные аргументы закончились
    inline void my_printf(const char* s) {
        while (*s) {
            if (*s == '%' && *(s + 1) != '%') {
                std::cout << "[ОШИБКА: не хватает аргументов]";
                return;
            }
            if (*s == '%' && *(s + 1) == '%') ++s; // Обработка %% как одного %
            std::cout << *s++;
        }
    }

    // Вариативный шаблон: обрабатывает один аргумент и рекурсивно передает хвост
    template<typename T, typename... Args>
    void my_printf(const char* s, T value, Args... args) {
        while (*s) {
            if (*s == '%') {
                if (*(s + 1) == '%') {
                    ++s; // Пропускаем экранированный %
                }
                else {
                    std::cout << value; // Выводим текущий аргумент
                    my_printf(s + 1, args...); // Рекурсивно вызываем для остальных
                    return;
                }
            }
            std::cout << *s++;
        }
    }

    // ШАБЛОН КЛАССА Sequence

    template <class T>
    class Sequence
    {
    private:
        T* data;    // Динамический массив для хранения данных
        int size;   // Размер последовательности

    public:
        Sequence(int n);
        ~Sequence();

        void Input();
        void Print();
        void Rearrange(); // Метод по варианту 10
    };

    // Конструктор
    template <class T>
    Sequence<T>::Sequence(int n)
    {
        size = n;
        data = new T[size];
    }

    // Деструктор
    template <class T>
    Sequence<T>::~Sequence()
    {
        delete[] data;
    }

    // Обобщенный метод ввода элементов (например, для double)
    template <class T>
    void Sequence<T>::Input()
    {
        for (int i = 0; i < size; ++i)
        {
            std::cin >> data[i];
        }
    }

    // ЯВНАЯ СПЕЦИАЛИЗАЦИЯ ШАБЛОНА ДЛЯ ТИПА INT (Защита ввода)
    template <>
    inline void Sequence<int>::Input()
    {
        std::string s;
        for (int i = 0; i < size; )
        {
            std::cin >> s;
            bool isInt = true;
            for (size_t j = 0; j < s.length(); ++j) {
                if (j == 0 && s[j] == '-') continue; // пропускаем минус в начале
                if (!isdigit(s[j])) {
                    isInt = false;
                    break;
                }
            }

            if (isInt) {
                data[i] = std::stoi(s);
                i++;
            }
            else {
                my_printf("\nОшибка: '%' не является целым числом! Повторите ввод элемента %: ", s, i + 1);
            }
        }
    }

    // Метод вывода элементов с использованием my_printf
    template <class T>
    void Sequence<T>::Print()
    {
        for (int i = 0; i < size; ++i)
        {
            my_printf("% ", data[i]);
        }
        my_printf("\n");
    }

    // Метод преобразования массива (отрицательные -> неотрицательные с сохранением порядка)
    template <class T>
    void Sequence<T>::Rearrange()
    {
        // Вспомогательный массив для временного хранения результата
        T* temp = new T[size];
        int idx = 0;

        // Первый проход: копируем только отрицательные элементы
        for (int i = 0; i < size; ++i)
        {
            if (data[i] < 0)
            {
                temp[idx++] = data[i];
            }
        }

        // Второй проход: копируем неотрицательные элементы
        for (int i = 0; i < size; ++i)
        {
            if (data[i] >= 0)
            {
                temp[idx++] = data[i];
            }
        }

        // Копируем переупорядоченные элементы обратно в исходный массив
        for (int i = 0; i < size; ++i)
        {
            data[i] = temp[i];
        }

        // Освобождаем временную память
        delete[] temp;
    }
}