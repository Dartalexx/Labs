#include "Ëàáà3.1.1.h";
#include <iostream>
Complex::~Complex()
{
    delete[] st;
}
// ìåòîä ñëîæåíèÿ
void Complex::Add(Complex op1, Complex op2) {
    r = op1.r + op2.r;
    i = op1.i + op2.i;
}
//ìåòîä âû÷èòàíèÿ
void Complex::Sub(Complex op1, Complex op2) {
    r = op1.r - op2.r;
    i = op1.i - op2.i;
}
//ìåòîä óìíîæåíèÿ
void Complex::Multi(Complex op1, Complex op2)
{
    r = (op1.r * op2.r - op1.i * op2.i);
    i = (op1.i * op2.r + op1.r * op2.i);
}
//ìåòîä äåëåíèÿ
void Complex::Div(Complex op1, Complex op2)
{
    r = (op1.r * op2.r + op1.i * op2.i) / (op2.r * op2.r + op2.i * op2.i);
    i = (op1.i * op2.r - op1.r * op2.i) / (op2.r * op2.r + op2.i * op2.i);
}
//ìåòîä ïåðåâîäà â ìàññèâ char
char* Complex::toString()
{
    st = new char[15];
    sprintf_s(st,15,"%d+%di",r,i);
    char* ch = st;
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
