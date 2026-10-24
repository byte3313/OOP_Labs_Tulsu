// lab1.cpp
// Реализация методов класса CMPLX
#include "lab1.h"
#include <cmath>
#include <iostream>

using namespace std;

namespace Lab1 {

	// 1. Конструктор по умолчанию — инициализация числа как (0, 0)
	CMPLX::CMPLX()
	{
		re = 0;
		im = 0;
	}

	// 2. Конструктор с параметрами — инициализация как (real, imag)
	CMPLX::CMPLX(float real, float imag)
	{
		re = real;
		im = imag;
	}

	// Конструктор копирования — создаёт новый объект как точную копию other.
	// Вызывается, например, при передаче/возврате CMPLX по значению или
	// при явной инициализации CMPLX b(a);
	// Строка cout ниже добавлена ТОЛЬКО для наглядной демонстрации на защите —
	// она печатает сообщение каждый раз, когда компилятор реально вызывает
	// именно этот конструктор (а не обычный конструктор с параметрами).
	CMPLX::CMPLX(const CMPLX& other)
	{
		re = other.re;
		im = other.im;
		cout << "[Вызван конструктор копирования] Создана копия числа: ";
		Print();
	}

	// 3. Изменение (установка) значения комплексного числа
	void CMPLX::Setcompl(float re, float im)
	{
		this->re = re;
		this->im = im;
	}

	// 5. Декремент модуля комплексного числа: |z| = |z| - 1
	// Число представляется в тригонометрической форме z = |z|*(cos+i*sin),
	// модуль уменьшается на 1, аргумент (направление) сохраняется.
	void CMPLX::Dec()
	{
		double r;      // модуль комплексного числа
		double cosRe;  // косинус аргумента (re / |z|)
		double sinIm;  // синус аргумента (im / |z|)

		if ((re == 0) && (im == 0))
		{
			cout << "Нулевое комплексное число нельзя представить "
				<< "в тригонометрической форме, декремент не выполнен!" << endl;
			return;
		}

		r = sqrt(re * re + im * im); // модуль числа
		cosRe = re / r;
		sinIm = im / r;
		r = r - 1;                   // декремент модуля
		re = (float)(cosRe * r);
		im = (float)(sinIm * r);
	}

	// 6. Сложение текущего комплексного числа с what
	CMPLX CMPLX::Add(CMPLX what)
	{
		CMPLX x; // результат сложения
		x.re = re + what.re;
		x.im = im + what.im;
		return x;
	}

	// 10. Деление текущего комплексного числа на what
	CMPLX CMPLX::Div(CMPLX what)
	{
		CMPLX x; // результат деления

		if ((what.re == 0) && (what.im == 0))
		{
			cout << "Деление на ноль невозможно!" << endl;
			x.re = re;
			x.im = im;
			return x;
		}

		float denom = what.re * what.re + what.im * what.im;
		x.re = (re * what.re + im * what.im) / denom;
		x.im = (im * what.re - re * what.im) / denom;
		return x;
	}

	// Вспомогательный метод вывода комплексного числа в виде (re, im)
	void CMPLX::Print()
	{
		cout << "(" << re << ", " << im << ")" << endl;
	}

	// Деструктор
	CMPLX::~CMPLX()
	{
	}
}