// lab7.cpp
#include "lab7.h"

namespace Lab7 {

    CMPLX::CMPLX() { re = 0; im = 0; }
    CMPLX::CMPLX(float real, float imag) { re = real; im = imag; }
    CMPLX::CMPLX(const CMPLX& other) { re = other.re; im = other.im; }

    void CMPLX::Setcompl(float re, float im)
    {
        this->re = re;
        this->im = im;
    }

    // Перегрузка оператора вывода в поток (<<)
    std::ostream& operator<<(std::ostream& os, const CMPLX& obj)
    {
        // Вывод в виде "(re, im)"
        os << "(" << obj.re << ", " << obj.im << ")";
        return os;
    }

    // Перегрузка оператора ввода из потока (>>)
    std::istream& operator>>(std::istream& is, CMPLX& obj)
    {
        float r, i;
        is >> r >> i;
        // Проверка успешности ввода перед изменением объекта
        if (is.good()) {
            obj.Setcompl(r, i);
        }
        return is;
    }
}