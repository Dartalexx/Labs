#include "Complex.h";
#include <iostream>
#include <cmath>
Complex::~Complex()
{

}
Complex::Complex()
{
    st = new char[10];
    i = 0;
    r = 0;
    for (int i1 = 0; i1 < 10; i1++)
        st[i1] = '0';
}
Complex:: Complex(int rl, int im)//конструктор с параметрами
{
    st = new char[10];
    r = rl;
    i = im;
    for (int i1 = 0; i1 < 10; i1++)
        st[i1] = '0';
}
const Complex& Complex:: operator = (const Complex &other) // перегрузка оператора присваивания
{
    r = other.r;
    i = other.i;
    toString();
    return (*this);
}
// метод сложения
void Complex::Add(Complex op1, Complex op2) {
    r = op1.r + op2.r;
    i = op1.i + op2.i;
}
//метод вычитания
void Complex::Sub(Complex op1, Complex op2) {
    r = op1.r - op2.r;
    i = op1.i - op2.i;
}
//метод умножения
void Complex::Multi(Complex op1, Complex op2)
{
    r = (op1.r * op2.r - op1.i * op2.i);
    i = (op1.i * op2.r + op1.r * op2.i);
}
//оператор умножения
Complex Complex:: operator * (Complex& other) {
    Complex temp;
    temp.r = (r * other.r - i * other.i);
    temp.i = (i * other.r + r * other.i);
    return temp;
}
//метод деления
void Complex::Div(Complex op1, Complex op2)
{
    r = (op1.r * op2.r + op1.i * op2.i) / (op2.r * op2.r + op2.i * op2.i);
    i = (op1.i * op2.r - op1.r * op2.i) / (op2.r * op2.r + op2.i * op2.i);
}
//оператор деления
Complex Complex:: operator / (Complex& other) // перегрузка оператора деления
{
    Complex temp;
    temp.r = (r * other.r + i * other.i) / (other.r * other.r + other.i * other.i);
    temp.i = (i * other.r - r * other.i) / (other.r * other.r + other.i * other.i);
    return temp;
}
float Complex:: abs(int r, int i) // Модуль комплексного числа
{
    float b;
    b = sqrt(r * r + i * i);
    return b;
}
//метод перевода в массив char
char* Complex::toString()
{
    st = new char[15];
    sprintf_s(st,15,"%d+%di",r,i);
    char* ch = st;
    return ch;
}
char* Complex::toTrig()
{
    char* tr;
    tr = new char[50];
    float di = i;
    float ri = r;
    float f = atan(i / r);
    float ab = abs(r,i);
    sprintf_s(tr, 49, "%1.2f(cos(%1.2f)+sin(%1.2f)i)",ab, f,f);
    return tr;
}
bool testMulti(Complex a, Complex b, Complex t)
{
    t = a * b;
    if ((t.getR() == (a.getR() * b.getR() - a.getI() * b.getI())) && (t.getI() == (a.getI() * b.getR() + a.getR() * b.getI())))
    {
        return true;
    }
    else return false;
}
bool testDiv(Complex a, Complex b, Complex t)
{
    t=a/b;
    if ((t.getR() == (a.getR() * b.getR() + a.getI() * b.getI()) / (b.getR() * b.getR() + b.getI() * b.getI())) && (t.getI() == (a.getI() * b.getR() - a.getR() * b.getI()) / (b.getR() * b.getR() + b.getI() * b.getI())))
    {
        return true;
    }
    else return false;
}
bool Complex:: operator == (const Complex& o) const
{
    return (r == o.r && i == o.i);
}
bool  operator < (const Complex& o,const Complex& o1) 
{
    return ((o.r < o1.r) && (o.i < o1.i));
}
bool  operator > (const Complex& o, const Complex& o1)
{
    return ((o.r > o1.r) && (o.i > o1.i));
}
int Complex:: getR() { return r; }
int Complex:: getI() { return i; }
bool testEqual(Complex a, Complex b)
{
    if ((a == b) == ((a.getI() == b.getI()) && (a.getR() == b.getR())))
        return true;
    else return false;
}
bool testLSign(Complex a, Complex b)
{
    if ((a < b) == ((a.getI() < b.getI()) && (a.getR() < b.getR())))
        return true;
    else return false;
}
bool testMSign(Complex a, Complex b)
{
    if ((a > b) == ((a.getI() > b.getI()) && (a.getR() > b.getR())))
        return true;
    else return false;
}
int Complex:: getID() { c_id = c++;  return c_id; }//получение номера объекта класса
int Complex::c = 1;