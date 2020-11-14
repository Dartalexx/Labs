#include "Complex.h";
Complex::~Complex()
{
    delete[] st;
}
Complex::Complex()
{
    st = new char[10];
    i = 0;
    r = 0;
    for (int i1 = 0; i1 < 10; i1++)
        st[i1] = '0';
}
Complex:: Complex(int rl, int im)//����������� � �����������
{
    st = new char[10];
    r = rl;
    i = im;
    for (int i1 = 0; i1 < 10; i1++)
        st[i1] = '0';
}
Complex::Complex(const Complex& other)// ����������� �����������
{
    st = new char[10];
    r = other.r;
    i = other.i;
    for (int i1 = 0; i1 < 10; i1++)
        st[i1] = other.st[i1];
}
int Complex::getR() { return r; }
int Complex::getI() { return i; }
int Complex::getID() { c_id = c++;  return c_id; }//��������� ������ ������� ������
const Complex& Complex:: operator = (const Complex &other) // ���������� ��������� ������������
{
    r = other.r;
    i = other.i;
    toString();
    return (*this);
}
// ����� ��������
void Complex::Add(Complex op1, Complex op2) {
    r = op1.r + op2.r;
    i = op1.i + op2.i;
}
//����� ���������
void Complex::Sub(Complex op1, Complex op2) {
    r = op1.r - op2.r;
    i = op1.i - op2.i;
}
//����� ���������
void Complex::Multi(Complex op1, Complex op2)
{
    r = (op1.r * op2.r - op1.i * op2.i);
    i = (op1.i * op2.r + op1.r * op2.i);
}
//�������� ���������
Complex Complex:: operator * (Complex& other) {
    Complex temp;
    temp.r = (r * other.r - i * other.i);
    temp.i = (i * other.r + r * other.i);
    return temp;
}
//����� �������
void Complex::Div(Complex op1, Complex op2)
{
    r = (op1.r * op2.r + op1.i * op2.i) / (op2.r * op2.r + op2.i * op2.i);
    i = (op1.i * op2.r - op1.r * op2.i) / (op2.r * op2.r + op2.i * op2.i);
}
//�������� �������
Complex Complex:: operator / (Complex& other) // ���������� ��������� �������
{
    Complex temp;
    temp.r = (r * other.r + i * other.i) / (other.r * other.r + other.i * other.i);
    temp.i = (i * other.r - r * other.i) / (other.r * other.r + other.i * other.i);
    return temp;
}
float Complex:: abs(int r, int i) // ������ ������������ �����
{
    float b;
    b = sqrt(r * r + i * i);
    return b;
}
//����� �������� � ������ char
char* Complex::toString()
{
    st = new char[10];
    sprintf_s(st,10,"%d+%di\n",r,i);
    char* ch = st;
    return ch;
}
char* Complex::toTrig()
{
    char* tr;
    tr = new char[50];
    float di = i;
    float ri = r;
    float f = atan(i / r);
    float ab = abs(r,i);
    sprintf_s(tr, 49, "%1.2f(cos(%1.2f)+sin(%1.2f)i)",ab, f,f);
    return tr;
}
void Complex:: writef(ofstream& out)//������ ������� ������ � ����
{
    toString();
    int k = 0;
    while (st[k]!='\n')
    {
        k++;
    };
    k++;
    char* t = new char[k];
    t = st;
    out.write(t, sizeof(t)-2);
};
void Complex::readf(istream& in)
{
    char c[15];
    char re[5];
    char im[5];
    in.read((char*)&c, sizeof(c));
    int i2 = 0;
    int i1 = 0;
    while (((c[i2] != '-') || (i2 != 0)) && (c[i2] != '+'))
    {
        re[i2] = c[i2];
        i2++;
    }
    r = atoi(re);
    while (c[i2] != 'i')
    {
        im[i1] = c[i2];
        i2++;
        i1++;
    }
    i = atoi(im);
};
bool Complex:: operator == (const Complex& o) const
{
    return (r == o.r && i == o.i);
}
bool  operator < (const Complex& o,const Complex& o1) 
{
    return ((o.r < o1.r) && (o.i < o1.i));
}
bool  operator > (const Complex& o, const Complex& o1)
{
    return ((o.r > o1.r) && (o.i > o1.i));
}
ostream& operator<<(ostream& out, const Complex& c)
{
    char* t = new char[10];
    if (c.i>0)
        sprintf_s(t, 10, "%d+%di", c.r, c.i);
    if (c.i < 0)
        sprintf_s(t, 10, "%d%di", c.r, c.i);
    char* ch = t;
    out << ch;
    return out;
}
istream& operator>>(istream& in,  Complex& c)
{
    char ch [15];
    char re [5];
    char im[5];
    int i = 0;
    int i1 = 0; 
    in >> ch;
    while (((ch[i] != '-') || (i == 0)) && (ch[i] != '+'))
    { 
      re[i] = ch[i];   
      i++;
    }
    c.r = atoi(re);                             
    while (ch[i] != 'i')
    {
       im[i1] = ch[i];
       i++;
       i1++;
    }
    c.i = atoi(im);
    return in;
}
int Complex::c = 1;