#pragma once
#include <stdio.h>
#include<stdlib.h> 
#include <iostream>
#include <fstream>
using namespace std;
// ����������� ������ ����������� �����
class Complex {
public:
    Complex();
    Complex(int rl, int im);//����������� � �����������
    Complex(const Complex& other);// ����������� �����������
    void Add(Complex x, Complex y);  // ������� ������������ �����
    void Sub(Complex x, Complex y);  // ������� ����������� �����
    void Multi(Complex x, Complex y); // ��������� ����������� �����
    void Div(Complex x, Complex y); // ������� ����������� ���
    char* toString(); //������� � ������
    int getR();
    int getI();
    int getID();//��������� ���������� �������� ������
    friend std::ostream& operator << (std::ostream& out, Complex a);
    Complex& operator = (Complex& a);
    ~Complex(); //����������
private:
    int r;  // ������������ �����
    int i;  // ������ �����
    char* st; //��������� �������������
    static int c;
    int c_id;
};