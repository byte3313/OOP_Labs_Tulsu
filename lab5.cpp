// lab5.cpp
// Реализация методов класса CMPLX
#include "lab5.h"
#include <cmath>
#include <iostream>
#include <cstdlib>
using namespace std;

namespace Lab5 {

	CMPLX::CMPLX() { re = 0; im = 0; }
	CMPLX::CMPLX(float real, float imag) { re = real; im = imag; }
	CMPLX::CMPLX(const CMPLX& other) { re = other.re; im = other.im; }

	void CMPLX::Setcompl(float re, float im)
	{
		this->re = re;
		this->im = im;
	}

	void CMPLX::Dec()
	{
		double r;
		double cosRe;
		double sinIm;

		if ((re == 0) && (im == 0))
		{
			cout << "Нулевое комплексное число нельзя представить "
				<< "в тригонометрической форме, декремент не выполнен!" << endl;
			return;
		}
		r = sqrt(re * re + im * im);
		cosRe = re / r;
		sinIm = im / r;
		r = r - 1;
		re = (float)(cosRe * r);
		im = (float)(sinIm * r);
	}

	CMPLX CMPLX::Add(CMPLX what)
	{
		CMPLX x;
		x.re = re + what.re;
		x.im = im + what.im;
		return x;
	}

	CMPLX CMPLX::Div(CMPLX what)
	{
		CMPLX x;
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

	// Перегрузка функции Div (деление на вещественное число)
	CMPLX CMPLX::Div(float what)
	{
		CMPLX x;
		if (what == 0)
		{
			cout << "Деление на ноль невозможно!" << endl;
			x.re = re;
			x.im = im;
			return x;
		}
		x.re = re / what;
		x.im = im / what;
		return x;
	}

	// Перегрузка оператора / для двух комплексных чисел
	CMPLX CMPLX::operator/(CMPLX what)
	{
		return this->Div(what);
	}

	// Перегрузка оператора / для деления на вещественное число
	CMPLX CMPLX::operator/(float what)
	{
		return this->Div(what);
	}

	// Перегрузка префиксного декремента (--z)
	CMPLX& CMPLX::operator--()
	{
		this->Dec();
		return *this;
	}

	// Перегрузка постфиксного декремента (z--)
	CMPLX CMPLX::operator--(int)
	{
		CMPLX temp(*this);
		this->Dec();
		return temp;
	}

	void CMPLX::Print()
	{
		cout << "(" << re << ", " << im << ")" << endl;
	}

	CMPLX::~CMPLX() {}

	// Перегрузка оператора + (сложение)
	CMPLX CMPLX::operator+(const CMPLX& what)
	{
		return CMPLX(re + what.re, im + what.im);
	}

	// Перегрузка оператора - (вычитание)
	CMPLX CMPLX::operator-(const CMPLX& what)
	{
		return CMPLX(re - what.re, im - what.im);
	}

	// Перегрузка оператора * (умножение комплексных чисел)
	// Формула: (a + bi)(c + di) = (ac - bd) + (bc + ad)i
	CMPLX CMPLX::operator*(const CMPLX& what)
	{
		float newRe = (re * what.re) - (im * what.im);
		float newIm = (re * what.im) + (im * what.re);
		return CMPLX(newRe, newIm);
	}

	// Перегрузка оператора == (сравнение на равенство)
	bool CMPLX::operator==(const CMPLX& what)
	{
		// Комплексные числа равны, если равны их действительные и мнимые части
		return (re == what.re) && (im == what.im);
	}

	// Перегрузка оператора () (вызов функции)
	// Позволяет использовать объект как функцию. В нашем случае — для быстрого задания новых значений
	void CMPLX::operator()(float r, float i)
	{
		re = r;
		im = i;
	}

	// Перегрузка оператора new
	void* CMPLX::operator new(size_t size)
	{
		cout << "[Свой new] Выделение памяти размером " << size << " байт." << endl;
		void* ptr = malloc(size); // Выделяем сырую память

		// для простой лабы можно обойтись без исключений или вернуть NULL
		return ptr;
	}

	// Перегрузка оператора delete
	void CMPLX::operator delete(void* ptr)
	{
		cout << "[Свой delete] Освобождение выделенной памяти." << endl;
		free(ptr); // Освобождаем сырую память
	}
}