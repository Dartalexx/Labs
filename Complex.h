#pragma once
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
// определение класса комплексных чисел
class Complex {
public:
    Complex();
    Complex(int rl, int im);//конструктор с параметрами
    Complex(const Complex& other);
    const Complex& operator = (const Complex& other); // перегрузка оператора присваивани€
    void Add(Complex x, Complex y);  // —ложить комплексные числа
    void Sub(Complex x, Complex y);  // вычесть комплексные числа
    void Multi(Complex x, Complex y); // умножение комплексных чисел
    void Div(Complex x, Complex y); // деление комплексных чисел
    void readf(istream& in);
    void writef(ofstream& out);
    Complex operator * (Complex& other); // перегрузка оператора умножени€
    Complex operator / (Complex& other); // перегрузка оператора делени€
    friend bool  operator < (const Complex& o, const Complex& o1);
    friend bool  operator > (const Complex& o, const Complex& o1);
    friend ostream& operator << (ostream& out, const Complex& x); // перегрузка оператора вывода
    friend istream& operator >> (istream& in, Complex& x); // перегрузка оператора ввода
    bool operator == (const Complex& o) const;
    float abs(int x, int y); // ћодуль комплексного числа
    char* toString(); //перевод в строку
    char* toTrig();//перевод в тригонометрическую форму
    int getR();
    int getI();
    void setR(int a);
    void setI(int a);
    int getID();//получение номера объекта класса
    ~Complex(); //ƒеструктор
private:
    int r;  // вещественна€ часть
    int i;  // мнима€ часть
    char* st; //строковое представление
    static int c;
    int c_id;
};
class child : public Complex
{
public:
    child();
    child (int rl, int im, char* d);//конструктор с параметрами
    child( child& other);
    ~child(); //ƒеструктор
    const child& operator = (child other); // перегрузка оператора присваивани€
    void Add(child x, child y);  // —ложить комплексные числа
    void Sub(child x, child y);  // вычесть комплексные числа
    void Multi(child x, child y); // умножение комплексных чисел
    void Div(child x, child y); // деление комплексных чисел
    void readf(istream& in);
    void writef(ofstream& out);
    child operator * (child& other); // перегрузка оператора умножени€
    child operator / (child& other); // перегрузка оператора делени€
    friend bool  operator < ( child o, child o1);
    friend bool  operator > ( child o,  child o1);
    bool operator == (child o);
    void strToNum();
    void toString(); //перевод в строку
    char* toTrig();
    char* getDate() { return date; };
    char* getString() { return st; };
private:
    char* st;
    char* date;
};