#pragma once
#include <stdio.h>
using namespace std;
// îïðåäåëåíèå êëàññà êîìïëåêñíûõ ÷èñåë
class Complex {
public:
    Complex()
    {
        i = 0;
        r = 0;
    }
    Complex(int rl, int im)//êîíñòðóêòîð ñ ïàðàìåòðàìè
    {
        st = new char[10];
        r = rl;
        i = im;
        for (int i1 = 0; i1 < 10; i1++)
            st[i1] ='0';
    }
    Complex(const Complex& other)// Êîíñòðóêòîð êîïèðîâàíèÿ
    {
        st = new char[10];
        r = other.r;
        i = other.i;
        for (int i1 = 0; i1 < 10; i1++)
            st[i1] = other.st[i1];
    }
    void Add(Complex x, Complex y);  // Ñëîæèòü êîìïëåêñíûûå ÷èñëà
    void Sub(Complex x, Complex y);  // âû÷åñòü êîìïëåêñíûå ÷èñëà
    void Multi(Complex x, Complex y); // óìíîæåíèå êîìïëåêñíûõ ÷èñåë
    void Div(Complex x, Complex y); // Äåëåíèå êîìïëåêñíûõ ÷èñ
    char* toString(); //ïåðåâîä â ñòðîêó
    int getr() { return r; }
    int geti() { return i; }
    int getID() { c_id = c++;  return c_id; }//ïîëó÷åíèå íîìåðà îáúåêòà êëàññà
    ~Complex(); //Äåñòðóêòîð
private:
    int r;  // âåùåñòâåííàÿ ÷àñòü
    int i;  // ìíèìàÿ ÷àñòü
    char* st; //ñòðîêîâîå ïðåäñòàâëåíèå
    static int c;
    int c_id;
};

