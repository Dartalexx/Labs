#include "Complex.h";
#include <iostream>
#include <cmath>
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
    t = a / b;
    if ((t.getR() == (a.getR() * b.getR() + a.getI() * b.getI()) / (b.getR() * b.getR() + b.getI() * b.getI())) && (t.getI() == (a.getI() * b.getR() - a.getR() * b.getI()) / (b.getR() * b.getR() + b.getI() * b.getI())))
    {
        return true;
    }
    else return false;
}
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