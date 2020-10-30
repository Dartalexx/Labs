#pragma once
#include <stdio.h>
using namespace std;
// ����������� ������ ����������� �����
class Complex {
public:
    Complex();
    Complex(int rl, int im);//����������� � �����������
    const Complex& operator = (const Complex& other); // ���������� ��������� ������������
    void Add(Complex x, Complex y);  // ������� ����������� �����
    void Sub(Complex x, Complex y);  // ������� ����������� �����
    void Multi(Complex x, Complex y); // ��������� ����������� �����
    void Div(Complex x, Complex y); // ������� ����������� �����
    Complex operator * (Complex& other); // ���������� ��������� ���������
    Complex operator / (Complex& other); // ���������� ��������� �������
    friend bool  operator < (const Complex& o, const Complex& o1);
    friend bool  operator > (const Complex& o, const Complex& o1);
    bool operator == (const Complex& o) const;
    float abs(int x, int y); // ������ ������������ �����
    char* toString(); //������� � ������
    char* toTrig();
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

