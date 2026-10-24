// lab1.h
// Описание класса CMPLX (комплексное число)
// Вариант 12: реализуются методы 1, 3, 5, 10 + деструктор
// Дополнительно (задания к защите): методы 2, 6 и конструктор копирования

namespace Lab1 {

	class CMPLX
	{
	public:
		CMPLX();                       /*1  Инициализация как (0,0) */
		CMPLX(float real, float imag); /*2  Инициализация как (real,imag) */
		CMPLX(const CMPLX& other);     // Конструктор копирования
		void Setcompl(float re, float im); /*3  Изменение числа */
		void Dec();                    /*5  Декремент: |z|=|z|-1 */
		CMPLX Add(CMPLX what);         /*6  Сложение */
		CMPLX Div(CMPLX what);         /*10 Деление */
		void Print();                  // вспомогательный метод вывода числа
		~CMPLX();                      // Деструктор

	private:
		float re; // действительная часть комплексного числа
		float im; // мнимая часть комплексного числа
	};
}