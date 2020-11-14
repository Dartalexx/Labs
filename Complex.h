#pragma once
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
// ����������� ������ ����������� �����
class Complex {
public:
    Complex();
    Complex(int rl, int im);//����������� � �����������
    Complex(const Complex& other);
    const Complex& operator = (const Complex& other); // ���������� ��������� ������������
    void Add(Complex x, Complex y);  // ������� ����������� �����
    void Sub(Complex x, Complex y);  // ������� ����������� �����
    void Multi(Complex x, Complex y); // ��������� ����������� �����
    void Div(Complex x, Complex y); // ������� ����������� �����
    void readf(istream& in);
    void writef(ofstream& out);
    Complex operator * (Complex& other); // ���������� ��������� ���������
    Complex operator / (Complex& other); // ���������� ��������� �������
    friend bool  operator < (const Complex& o, const Complex& o1);
    friend bool  operator > (const Complex& o, const Complex& o1);
    friend ostream& operator << (ostream& out, const Complex& x); // ���������� ��������� ������
    friend istream& operator >> (istream& in, Complex& x); // ���������� ��������� �����
    bool operator == (const Complex& o) const;
    float abs(int x, int y); // ������ ������������ �����
    char* toString(); //������� � ������
    char* toTrig();//������� � ������������������ �����
    int getR();
    int getI();
    int getID();//��������� ������ ������� ������
    ~Complex(); //����������
private:
    int r;  // ������������ �����
    int i;  // ������ �����
    char* st; //��������� �������������
    static int c;
    int c_id;
};

