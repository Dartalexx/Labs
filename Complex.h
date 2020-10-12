#pragma once
#include <stdio.h>
using namespace std;
// îïðåäåëåíèå êëàññà êîìïëåêñíûõ ÷èñåë
class Complex {
public:
    Complex();
    Complex(int rl, int im);//êîíñòðóêòîð ñ ïàðàìåòðàìè
    Complex(const Complex& other);// Êîíñòðóêòîð êîïèðîâàíèÿ
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

