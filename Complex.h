#pragma once
#include <stdio.h>
using namespace std;
// определение класса комплексных чисел
class Complex {
public:
    Complex();
    Complex(int rl, int im);//конструктор с параметрами
    Complex(const Complex& other);
    const Complex& operator = (const Complex& other); // перегрузка оператора присваивания
    void Add(Complex x, Complex y);  // Сложить комплексные числа
    void Sub(Complex x, Complex y);  // вычесть комплексные числа
    void Multi(Complex x, Complex y); // умножение комплексных чисел
    void Div(Complex x, Complex y); // деление комплексных чисел
    Complex operator * (Complex& other); // перегрузка оператора умножения
    Complex operator / (Complex& other); // перегрузка оператора деления
    friend bool  operator < (const Complex& o, const Complex& o1);
    friend bool  operator > (const Complex& o, const Complex& o1);
    bool operator == (const Complex& o) const;
    float abs(int x, int y); // Модуль комплексного числа
    char* toString(); //перевод в строку
    char* toTrig();
    int getR();
    int getI();
    int getID();//получение номера объекта класса
    ~Complex(); //Деструктор
private:
    int r;  // вещественная часть
    int i;  // мнимая часть
    char* st; //строковое представление
    static int c;
    int c_id;
};

