// Реализация классов CHAIN и DUPARRAY (вариант 10)
#include "lab3.h"
#include <iostream>

using namespace std;

namespace Lab3 {

	// а) CHAIN — та же цепочка, что и в ЛР 2 (вариант 7), но звенья создаются
	//    и удаляются операторами new/delete, а не calloc/free.

	// Конструктор: создаёт цепочку из n динамических переменных.
	// Каждое звено цепочки создаётся отдельно оператором new, значения
	// вводятся пользователем с клавиатуры по одному и присоединяются друг
	// к другу указателями next.
	CHAIN::CHAIN(int n)
	{
		this->n = n;
		count = 0;
		head = NULL;

		Node* last = NULL; // указатель на последнее добавленное звено цепочки

		for (int i = 1; i <= n; i++)
		{
			float value;
			cout << "Введите " << i << "-е число цепочки: ";
			cin >> value;

			// создаём новое динамическое звено цепочки оператором new
			Node* node = new Node;
			node->value = value;
			node->next = NULL;

			if (head == NULL)
				head = node;        // это первое звено цепочки
			else
				last->next = node;  // присоединяем новое звено к предыдущему

			last = node;
			count++;
		}
	}

	// Печать всех значений цепочки в порядке их следования от головы к хвосту
	void CHAIN::Print()
	{
		if (head == NULL)
		{
			cout << "Цепочка пуста." << endl;
			return;
		}

		Node* cur = head;
		int i = 1;
		while (cur != NULL)
		{
			cout << i << ": " << cur->value << endl;
			cur = cur->next;
			i++;
		}
	}

	// Вставка звена со значением 0 между [n/2]-м и ([n/2]+1)-м элементом,
	// где n — исходное количество чисел, введённых при создании цепочки.
	void CHAIN::InsertZero()
	{
		int pos = n / 2; // номер звена, ПОСЛЕ которого вставляется 0

		if (pos <= 0)
		{
			// вставлять фактически некуда (n = 0) либо ноль должен идти
			// перед единственным звеном цепочки (n = 1) — добавляем 0 в начало
			Node* node = new Node;
			node->value = 0;
			node->next = head;
			head = node;
			count++;
			return;
		}

		// доходим до звена номер pos (считая от 1)
		Node* cur = head;
		for (int i = 1; i < pos && cur != NULL; i++)
			cur = cur->next;

		if (cur == NULL)
		{
			cout << "Недостаточно звеньев цепочки для вставки!" << endl;
			return;
		}

		Node* node = new Node;
		node->value = 0;
		node->next = cur->next; // новое звено указывает туда же, куда указывало cur
		cur->next = node;       // cur теперь указывает на новое звено
		count++;
	}

	// Возвращает текущее количество звеньев цепочки (с учётом вставленного нуля)
	int CHAIN::GetCount()
	{
		return count;
	}

	// Деструктор: последовательно удаляет (delete) все динамические звенья
	// цепочки, созданные оператором new в конструкторе и в InsertZero.
	CHAIN::~CHAIN()
	{
		Node* cur = head;
		while (cur != NULL)
		{
			Node* nxt = cur->next;
			delete cur;
			cur = nxt;
		}
		head = NULL;
	}

	// б) DUPARRAY — вариант 10: динамический массив вещественных чисел;
	//    подсчёт количества совпадающих элементов в последовательности из N чисел.

	// Конструктор: создаёт динамический массив из n вещественных чисел
	// оператором new[] и заполняет его числами, введёнными с клавиатуры.
	DUPARRAY::DUPARRAY(int n)
	{
		this->n = n;
		data = new float[n];

		for (int i = 0; i < n; i++)
		{
			cout << "Введите элемент массива №" << (i + 1) << ": ";
			cin >> data[i];
		}
	}

	// Печать всех элементов массива
	void DUPARRAY::Print()
	{
		for (int i = 0; i < n; i++)
			cout << i + 1 << ": " << data[i] << endl;
	}

	// Подсчёт количества совпадающих элементов в последовательности из N чисел:
	// для каждого элемента проверяется, встречается ли где-либо ещё в массиве
	// (на другой позиции) точно такое же значение. Если да — элемент считается
	// совпадающим (имеющим дубликат) и учитывается в результате.
	int DUPARRAY::CountMatches()
	{
		int result = 0;

		for (int i = 0; i < n; i++)
		{
			bool hasMatch = false;
			for (int j = 0; j < n; j++)
			{
				if (j != i && data[j] == data[i])
				{
					hasMatch = true;
					break;
				}
			}
			if (hasMatch)
				result++;
		}

		return result;
	}

	// Деструктор: освобождает память динамического массива (delete[])
	DUPARRAY::~DUPARRAY()
	{
		delete[] data;
		data = NULL;
	}
}