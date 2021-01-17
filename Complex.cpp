#include "Complex.h"
Complex::~Complex()
{
    if(st)
    delete[] st;
}
Complex::Complex()
{
    i = 0;
    r = 0;
}
Complex::Complex(int rl, int im)//êîíñòðóêòîð ñ ïàðàìåòðàìè
{
    st = new char[10];
    r = rl;
    i = im;
    for (int i1 = 0; i1 < 10; i1++)
        st[i1] = '0';
}
Complex::Complex(const Complex& other)// Êîíñòðóêòîð êîïèðîâàíèÿ
{
    r = other.r;
    i = other.i;
    toString();
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
    sprintf_s(st, 15, "%d+%di", r, i);
    char* ch = st;
    return ch;
}
bool testAdd(Complex a, Complex b, Complex r)
{
    r.Add(a, b);
    if ((r.getR() == a.getR() + b.getR()) && (r.getI() == a.getI() + b.getI()))
    {
        return true;
    }
    else
        return false;
}
bool testSub(Complex a, Complex b, Complex r)
{
    r.Sub(a, b);
    if ((r.getR() == a.getR() - b.getR()) && (r.getI() == a.getI() - b.getI()))
    {
        return true;
    }
    else
        return false;
}
bool testMulti(Complex a, Complex b, Complex r)
{
    r.Multi(a, b);
    if ((r.getR() == (a.getR() * b.getR() - a.getI() * b.getI())) && (r.getI() == (a.getI() * b.getR() + a.getR() * b.getI())))
    {
        return true;
    }
    else return false;
}
bool testDiv(Complex a, Complex b, Complex r)
{
    r.Div(a, b);
    if ((r.getR() == (a.getR() * b.getR() + a.getI() * b.getI()) / (b.getR() * b.getR() + b.getI() * b.getI())) && (r.getI() == (a.getI() * b.getR() - a.getR() * b.getI()) / (b.getR() * b.getR() + b.getI() * b.getI())))
    {
        return true;
    }
    else return false;
}
int Complex::getR() { return r; }
int Complex::getI() { return i; }
int Complex::getID() { c_id = c++;  return c_id; }
ostream& operator << (ostream& out, Complex a) {
    out << a.toString();
    return out;
}
Complex &Complex::operator = (Complex& a) {
    this->r = a.getR();
    this->i = a.getI();
    if (st) delete st;
    st = new char[strlen(a.st) + 1];
    strcpy_s(st, strlen(a.st) + 1, a.st);
    return *this;
}
int Complex::c = 1;
