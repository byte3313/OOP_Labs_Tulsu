// lab4.h
// ЛР4, вариант 12. Число (Number) - абстрактный интерфейс любого числа,
// от него унаследован CMPLX из ЛР1 (задание 1,3,5,10) и RNUM - обычное
// вещественное число, чтобы было видно, что Dec/Div/Print у разных чисел
// реализованы по-разному, а не просто дублируют друг друга.

namespace Lab4 {

	class Number
	{
	public:
		virtual void Print() = 0;
		virtual void Dec() = 0;
		virtual Number* Div(Number* what) = 0;
		virtual ~Number() {}
	};

	class CMPLX : public Number
	{
	public:
		CMPLX();
		CMPLX(float real, float imag);
		CMPLX(const CMPLX& other);

		virtual void Setcompl(float re, float im); // 3, виртуальный по варианту
		void Dec() override;                       // 5
		CMPLX* Div(Number* what) override;          // 10
		void Print() override;

		CMPLX Add(CMPLX what); // из ЛР1, в состав варианта для ЛР4 не входит

		~CMPLX();

	private:
		float re;
		float im;
	};

	class RNUM : public Number
	{
	public:
		RNUM(float value = 0);

		void Dec() override;
		RNUM* Div(Number* what) override;
		void Print() override;

		float GetValue();

		~RNUM();

	private:
		float value;
	};
}