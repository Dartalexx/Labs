#pragma once
#include <stdio.h>
using namespace std;
// îïðåäåëåíèå êëàññà êîìïëåêñíûõ ÷èñåë
class Complex {
public:
    Complex();
    Complex(int rl, int im);//êîíñòðóêòîð ñ ïàðàìåòðàìè
    const Complex& operator = (const Complex& other); // ïåðåãðóçêà îïåðàòîðà ïðèñâàèâàíèÿ
    Complex operator * (Complex& other); // ïåðåãðóçêà îïåðàòîðà óìíîæåíèÿ
    Complex operator / (Complex& other); // ïåðåãðóçêà îïåðàòîðà äåëåíèÿ
    friend bool  operator < (const Complex& o, const Complex& o1);
    friend bool  operator > (const Complex& o, const Complex& o1);
    bool operator == (const Complex& o) const;
    float abs(int x, int y); // Ìîäóëü êîìïëåêñíîãî ÷èñëà
    char* toString(); //ïåðåâîä â ñòðîêó
    char* toTrig();
    int getR();
    int getI();
    int getID();//ïîëó÷åíèå íîìåðà îáúåêòà êëàññà
    ~Complex(); //Äåñòðóêòîð
private:
    int r;  // âåùåñòâåííàÿ ÷àñòü
    int i;  // ìíèìàÿ ÷àñòü
    char* st; //ñòðîêîâîå ïðåäñòàâëåíèå
    static int c;
    int c_id;
};

