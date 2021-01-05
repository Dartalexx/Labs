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
    void setR(int a);
    void setI(int a);
    int getID();//��������� ������ ������� ������
    ~Complex(); //����������
private:
    int r;  // ������������ �����
    int i;  // ������ �����
    char* st; //��������� �������������
    static int c;
    int c_id;
};
class child : public Complex
{
public:
    child();
    child (int rl, int im, char* d);//����������� � �����������
    child( child& other);
    ~child(); //����������
    const child& operator = (child other); // ���������� ��������� ������������
    void Add(child x, child y);  // ������� ����������� �����
    void Sub(child x, child y);  // ������� ����������� �����
    void Multi(child x, child y); // ��������� ����������� �����
    void Div(child x, child y); // ������� ����������� �����
    void readf(istream& in);
    void writef(ofstream& out);
    child operator * (child& other); // ���������� ��������� ���������
    child operator / (child& other); // ���������� ��������� �������
    friend bool  operator < ( child o, child o1);
    friend bool  operator > ( child o,  child o1);
    bool operator == (child o);
    void strToNum();
    void toString(); //������� � ������
    char* toTrig();
    char* getDate() { return date; };
    char* getString() { return st; };
private:
    char* st;
    char* date;
};