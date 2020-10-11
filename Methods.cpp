#include "Лаба3.1.1.h";
#include <iostream>
Complex::~Complex()
{
    delete[] st;
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
//метод деления
void Complex::Div(Complex op1, Complex op2)
{
    r = (op1.r * op2.r + op1.i * op2.i) / (op2.r * op2.r + op2.i * op2.i);
    i = (op1.i * op2.r - op1.r * op2.i) / (op2.r * op2.r + op2.i * op2.i);
}
//метод перевода в массив char
char* Complex::toString()
{
    st = new char[10];
    char* ch = st;
    int k = 0, d, i1 = 0;
    d = r;
    for (; d != 0; k++)
    {
        d = d / 10;
    }
    d = r;
    if (r > 0)
    {
        k--;
        i1 = k;
    }
    if (r < 0)
    {
        i1 = k;
        st[0] = '-';
    }
    for (; d != 0; k--)
    {
        st[k] = abs(d % 10) + '0';
        d = d / 10;
    }
    i1++;
    if (i > 0)
        st[i1] = '+';
    else
        st[i1] = '-';
    d = i;
    k = 0;
    for (; d > 0; k++)
    {
        d = d / 10;
    }
    d = i;
    i1 += k;
    for (int i2 = i1; d > 0; i2--)
    {
        st[i2] = d % 10 + '0';
        d = d / 10;
    }
    i1++;
    st[i1] = 'i';
    i1++;
    st[i1] = '\0';
    return ch;
}
bool testAdd(Complex a, Complex b, Complex r)
{
    r.Add(a, b);
    if ((r.getr() == a.getr() + b.getr()) && (r.geti() == a.geti() + b.geti()))
    {
        return true;
    }
    else
        return false;
}
bool testSub(Complex a, Complex b, Complex r)
{
    r.Sub(a, b);
    if ((r.getr() == a.getr() - b.getr()) && (r.geti() == a.geti() - b.geti()))
    {
        return true;
    }
    else
        return false;
}
bool testMulti(Complex a, Complex b, Complex r)
{
    r.Multi(a, b);
    if ((r.getr() == (a.getr() * b.getr() - a.geti() * b.geti())) && (r.geti() == (a.geti() * b.getr() + a.getr() * b.geti())))
    {
        return true;
    }
    else return false;
}
bool testDiv(Complex a, Complex b, Complex r)
{
    r.Div(a, b);
    if ((r.getr() == (a.getr() * b.getr() + a.geti() * b.geti()) / (b.getr() * b.getr() + b.geti() * b.geti())) && (r.geti() == (a.geti() * b.getr() - a.getr() * b.geti()) / (b.getr() * b.getr() + b.geti() * b.geti())))
    {
        return true;
    }
    else return false;
}
int Complex::c = 1;