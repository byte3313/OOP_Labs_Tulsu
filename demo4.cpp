#include "lab4.h"
#include <iostream>

using namespace std;

namespace Lab4 {

	void Run()
	{
		float re, im, val;

		cout << "Введите комплексное число (re im): ";
		cin >> re >> im;
		CMPLX c(re, im);

		cout << "Введите обычное вещественное число: ";
		cin >> val;
		RNUM r(val);

		Number* nums[2] = { &c, &r };

		cout << endl << "--- Print() через указатель на Number ---" << endl;
		for (int i = 0; i < 2; i++)
			nums[i]->Print();

		cout << endl << "--- Dec() через указатель на Number ---" << endl;
		for (int i = 0; i < 2; i++)
		{
			nums[i]->Dec();
			nums[i]->Print();
		}

		cout << endl << "--- Деление внутри одного вида чисел ---" << endl;
		CMPLX otherC(1, 1);
		Number* q1 = c.Div(&otherC);
		cout << "CMPLX / CMPLX: ";
		q1->Print();
		delete q1;

		RNUM otherR(2);
		Number* q2 = r.Div(&otherR);
		cout << "RNUM / RNUM: ";
		q2->Print();
		delete q2;

		cout << endl << "--- Деление комплексного числа на вещественное (допустимо) ---" << endl;
		Number* q3 = c.Div(&otherR);
		cout << "CMPLX / RNUM: ";
		q3->Print();
		delete q3;

		cout << endl << "--- Попытка разделить вещественное число на комплексное (недопустимо) ---" << endl;
		Number* q4 = r.Div(&otherC);
		cout << "RNUM / CMPLX: ";
		q4->Print();
		delete q4;

		return;
	}
}