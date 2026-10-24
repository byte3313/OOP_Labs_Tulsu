// lab5.h
// Описание класса CMPLX (комплексное число)
// Вариант 12: реализация методов и перегрузка операторов/функций

namespace Lab5 {

	class CMPLX
	{
	public:
		CMPLX();
		CMPLX(float real, float imag);
		CMPLX(const CMPLX& other);

		void Setcompl(float re, float im);
		void Dec();
		CMPLX Add(CMPLX what);

		// Метод по варианту
		CMPLX Div(CMPLX what);

		// Перегрузка функций
		CMPLX Div(float what);

		// Перегрузка операторов
		CMPLX operator/(CMPLX what);
		CMPLX operator/(float what);
		CMPLX& operator--();   // Префиксный декремент (--z)
		CMPLX operator--(int); // Постфиксный декремент (z--)

		// Перегрузка операторов выделения и освобождения памяти
		void* operator new(size_t size);
		void operator delete(void* ptr);

		// Дополнительные перегруженные операторы для защиты
		CMPLX operator+(const CMPLX& what); // Сложение
		CMPLX operator-(const CMPLX& what); // Вычитание
		CMPLX operator*(const CMPLX& what); // Умножение
		bool operator==(const CMPLX& what); // Сравнение на равенство

		// Перегрузка оператора вызова функции () 
		// (например, сделаем его шорткатом для быстрого изменения чисел)
		void operator()(float r, float i);

		void Print();
		~CMPLX();
	private:
		float re;
		float im;
	};
}