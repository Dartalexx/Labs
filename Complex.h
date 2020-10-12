#pragma once
#include <stdio.h>
using namespace std;
// определение класса комплексных чисел
class Complex {
public:
    Complex();
    Complex(int rl, int im);//конструктор с параметрами
    Complex(const Complex& other);// Конструктор копирования
    void Add(Complex x, Complex y);  // Сложить комплексныые числа
    void Sub(Complex x, Complex y);  // вычесть комплексные числа
    void Multi(Complex x, Complex y); // умножение комплексных чисел
    void Div(Complex x, Complex y); // Деление комплексных чис
    char* toString(); //перевод в строку
    int getR();
    int getI();
    int getID() { c_id = c++;  return c_id; }//получение номера объекта класса
    ~Complex(); //Деструктор
private:
    int r;  // вещественная часть
    int i;  // мнимая часть
    char* st; //строковое представление
    static int c;
    int c_id;
};
