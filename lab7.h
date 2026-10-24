// lab7.h
#pragma once
#include <iostream>
#include <iomanip>
#include <tuple>

namespace Lab7 {

    class CMPLX
    {
    public:
        CMPLX();
        CMPLX(float real, float imag);
        CMPLX(const CMPLX& other);

        void Setcompl(float re, float im);

        friend std::ostream& operator<<(std::ostream& os, const CMPLX& obj);
        friend std::istream& operator>>(std::istream& is, CMPLX& obj);

    private:
        float re;
        float im;
    };

    // Класс-манипулятор для форматирования
    class MyFormat {
    public:
        friend std::ostream& operator<<(std::ostream& os, const MyFormat& mf) {
            os << std::setfill('0') << std::fixed << std::setprecision(0) << std::dec << std::setw(9);
            return os;
        }
    };

    // Синоним для кортежа
    using MyTuple = std::tuple<char, char, float, float, int>;

    // Перегрузка оператора ввода для кортежа
    inline std::istream& operator>>(std::istream& is, MyTuple& t) {
        is >> std::get<0>(t) >> std::get<1>(t) >> std::get<2>(t) >> std::get<3>(t) >> std::get<4>(t);
        return is;
    }
}