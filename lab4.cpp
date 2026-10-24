#include "lab4.h"
#include <cmath>
#include <iostream>

using namespace std;

namespace Lab4 {

	CMPLX::CMPLX()
	{
		re = 0;
		im = 0;
	}

	CMPLX::CMPLX(float real, float imag)
	{
		re = real;
		im = imag;
	}

	CMPLX::CMPLX(const CMPLX& other)
	{
		re = other.re;
		im = other.im;
	}

	void CMPLX::Setcompl(float re, float im)
	{
		this->re = re;
		this->im = im;
	}

	// декремент модул€: |z| = |z| - 1, направление числа не мен€етс€
	void CMPLX::Dec()
	{
		if (re == 0 && im == 0)
		{
			cout << "„исло нулевое, декремент не выполн€етс€." << endl;
			return;
		}

		double r = sqrt(re * re + im * im);
		double cosRe = re / r;
		double sinIm = im / r;
		r = r - 1;

		re = (float)(cosRe * r);
		im = (float)(sinIm * r);
	}

	// делим комплексное число на другое Number: обычна€ комплексна€ арифметика,
	// если what - тоже CMPLX; деление на вещественное число тоже
	// разрешено - это просто im/re, делЄнные на одно и то же число;
	// на что-то ещЄ делить не умеем.
	CMPLX* CMPLX::Div(Number* what)
	{
		CMPLX* c = dynamic_cast<CMPLX*>(what);
		if (c != nullptr)
		{
			float denom = c->re * c->re + c->im * c->im;
			if (denom == 0)
			{
				cout << "ƒеление на ноль невозможно." << endl;
				return new CMPLX(re, im);
			}
			float rre = (re * c->re + im * c->im) / denom;
			float rim = (im * c->re - re * c->im) / denom;
			return new CMPLX(rre, rim);
		}

		RNUM* r = dynamic_cast<RNUM*>(what);
		if (r != nullptr)
		{
			float v = r->GetValue();
			if (v == 0)
			{
				cout << "ƒеление на ноль невозможно." << endl;
				return new CMPLX(re, im);
			}
			return new CMPLX(re / v, im / v);
		}

		cout << "CMPLX::Div: неизвестный тип аргумента, деление не выполнено." << endl;
		return new CMPLX(re, im);
	}

	CMPLX CMPLX::Add(CMPLX what)
	{
		CMPLX x;
		x.re = re + what.re;
		x.im = im + what.im;
		return x;
	}

	void CMPLX::Print()
	{
		cout << "(" << re << ", " << im << ")" << endl;
	}

	CMPLX::~CMPLX()
	{
	}

	// RNUM - обычное вещественное число, второй наследник Number.

	RNUM::RNUM(float value)
	{
		this->value = value;
	}

	void RNUM::Dec()
	{
		value = value - 1;
	}

	// вещественное число делим только на другое вещественное число - деление
	// на комплексное здесь смысла не имеет, поэтому просто отказываемс€
	RNUM* RNUM::Div(Number* what)
	{
		RNUM* r = dynamic_cast<RNUM*>(what);
		if (r == nullptr)
		{
			cout << "RNUM::Div: обычное число можно делить только на обычное число." << endl;
			return new RNUM(value);
		}

		if (r->value == 0)
		{
			cout << "ƒеление на ноль невозможно." << endl;
			return new RNUM(value);
		}

		return new RNUM(value / r->value);
	}

	void RNUM::Print()
	{
		cout << value << endl;
	}

	float RNUM::GetValue()
	{
		return value;
	}

	RNUM::~RNUM()
	{
	}
}