// lab2.cpp
// Реализация методов класса CHAIN
#include "lab2.h"
#include <iostream>
#include <cstdlib>

using namespace std;

namespace Lab2 {

	// Конструктор: создаёт цепочку из n динамических переменных.
	// Каждое звено цепочки выделяется отдельно функцией calloc, значения
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

			// выделяем память под новое динамическое звено цепочки
			Node* node = (Node*)calloc(1, sizeof(Node));
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
	// где n — исходное количество чисел, введённых при создании цепочки
	// (число n сохранено в конструкторе и не пересчитывается после вставки).
	void CHAIN::InsertZero()
	{
		int pos = n / 2; // номер звена, ПОСЛЕ которого вставляется 0

		if (pos <= 0)
		{
			// вставлять фактически некуда (n = 0) либо ноль должен идти
			// перед единственным звеном цепочки (n = 1) — добавляем 0 в начало
			Node* node = (Node*)calloc(1, sizeof(Node));
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

		Node* node = (Node*)calloc(1, sizeof(Node));
		node->value = 0;
		node->next = cur->next; // новое звено указывает туда же, куда указывало cur
		cur->next = node;       // cur теперь указывает на новое звено
		count++;
	}

	// (Доп. задание) Вставка звена со значением 0 на позицию index,
	// указанную пользователем (нумерация с 1). Новое звено становится именно
	// index-м элементом цепочки. Метод можно вызывать несколько раз подряд
	// каждый вызов добавляет ещё один ноль в указанное место без ограничения
	// на их количество.
	// Если index <= 1 (или цепочка пуста) 0 становится первым элементом.
	// Если index больше текущей длины цепочки 0 добавляется в конец
	void CHAIN::InsertZeroAt(int index)
	{
		Node* node = (Node*)calloc(1, sizeof(Node));
		node->value = 0;

		if (index <= 1 || head == NULL)
		{
			node->next = head;
			head = node;
			count++;
			return;
		}

		// нужно дойти до звена номер (index - 1) — после него встанет новый 0
		Node* cur = head;
		int steps = index - 2;
		for (int i = 0; i < steps && cur->next != NULL; i++)
			cur = cur->next;

		node->next = cur->next; // новое звено занимает место после cur
		cur->next = node;
		count++;
	}

	// Возвращает текущее количество звеньев цепочки (с учётом вставленного нуля)
	int CHAIN::GetCount()
	{
		return count;
	}

	// Деструктор: последовательно освобождает память, выделенную под все
	// динамические звенья цепочки функцией calloc в конструкторе и в InsertZero
	CHAIN::~CHAIN()
	{
		Node* cur = head;
		while (cur != NULL)
		{
			Node* nxt = cur->next;
			free(cur);
			cur = nxt;
		}
		head = NULL;
	}
}