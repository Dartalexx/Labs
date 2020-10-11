#pragma once
using namespace std;
// ����������� ������ ����������� �����
class Complex {
public:
    Complex()
    {
        i = 0;
        r = 0;
    }
    Complex(int rl, int im)//����������� � �����������
    {
        st = new char[10];
        r = rl;
        i = im;
        for (int i1 = 0; i1 < 10; i1++)
            st[i1] ='0';
    }
    Complex(const Complex& other)// ����������� �����������
    {
        st = new char[10];
        r = other.r;
        i = other.i;
        for (int i1 = 0; i1 < 10; i1++)
            st[i1] = other.st[i1];
    }
    void Add(Complex x, Complex y);  // ������� ������������ �����
    void Sub(Complex x, Complex y);  // ������� ����������� �����
    void Multi(Complex x, Complex y); // ��������� ����������� �����
    void Div(Complex x, Complex y); // ������� ����������� ���
    char* toString(); //������� � ������
    int getr() { return r; }
    int geti() { return i; }
    int getID() { c_id = c++;  return c_id; }//��������� ������ ������� ������
    ~Complex(); //����������
private:
    int r;  // ������������ �����
    int i;  // ������ �����
    char* st; //��������� �������������
    static int c;
    int c_id;
};

