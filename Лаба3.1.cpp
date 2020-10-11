#include <iostream>
#include <conio.h>
using namespace std;
// определение класса комплексных чисел
class Complex {
public:
    void Init(int rl, int im = 0); // инициализировать
    void Read();           // ввод с клавиатуры
    void Display();        // вывод
    void Add(Complex x, Complex y);  // Сложить комплексныые числа
    void Sub(Complex x, Complex y);  // вычесть комплексные числа
    void Multi(Complex x, Complex y); // умножение комплексных чисел
    void Div(Complex x, Complex y); // Деление комплексных чис
    void Convert(); //перевод в строку
    int getr() { return r; }
    int geti() { return i; }
    Complex() { c_id = c++; };
    int getID() const {return c_id;}//получение номера объекта класса
    ~Complex(); //Деструктор
private:
    int r;  // вещественная часть
    int i;  // мнимая часть
    char* st; //строковое представление
    static int c;
    int c_id;//
};

Complex::~Complex() 
{
    delete[] st;
}
// определение метода ввода
void Complex::Read()
{
    cout << "Enter r : ";
    cin >> r;
    cout << "Enter i : ";
    cin >> i;
}
// определение метода вывода
void Complex::Display()
{
    if ((r != 0) && (i > 0))
        cout << r << '+' << i << 'i' << "\n";
    if ((r!=0)&&(i<0))
        cout << r-i <<"\n";
    if ((r != 0) && (i == 0))
        cout << r <<"\n";
}
// метод инициализации
void Complex::Init(int rl, int im)
{
    r = rl;
    i = im;
}
// метод сложения
void Complex::Add(Complex op1, Complex op2) {
    r = op1.r + op2.r;
    i = op1.i + op2.i;
}
//метод вычитания
void Complex::Sub(Complex op1, Complex op2) {
    r = op1.r - op2.r;
    i = op1.i - op2.i;
}
//метод умножения
void Complex::Multi(Complex op1, Complex op2)
{
    r = (op1.r * op2.r-op1.i * op2.i);
    i = (op1.i*op2.r+op1.r*op2.i);
}
//метод деления
void Complex::Div(Complex op1, Complex op2)
{
    r = (op1.r * op2.r + op1.i * op2.i) / (op2.r*op2.r+op2.i*op2.i);
    i = (op1.i * op2.r - op1.r * op2.i) / (op2.r * op2.r + op2.i * op2.i);
}
//метод перевода в массив char
void Complex::Convert()
{
    st = new char[10];
    int k=0,d,i1=0;
    d = r;
    for (;d != 0;k++)
    {
        d=d/10;
    }
    d = r;
    if (r > 0) 
    {
        k--;
        i1 = k;
    }
    if(r < 0)
    {
        i1 = k;
        st[0] = '-';
    }
    for (;d!=0;k--)
    {
        st[k] = abs(d % 10)+'0';
        d = d / 10;
    }
    i1++;
    if (i > 0)
        st[i1] = '+';
    else
        st[i1] = '-';
    d = i;
    k = 0;
    for (; d > 0; k++)
    {
        d = d / 10;
    }
    d = i;
    i1 += k;
    for (int i2=i1; d > 0; i2--)
    {
        st[i2] = d % 10 + '0';
        d = d / 10;
    }
    i1++;
    st[i1] = 'i';
    i1++;
    st[i1] = '\0';
    cout <<st<<endl;
}
int Complex::c = 1;
bool testAdd(Complex a, Complex b, Complex r) 
{
    r.Add(a,b);
    if ((r.getr() == a.getr() + b.getr())&& (r.geti() == a.geti() + b.geti()))
    {
        return true;
    }
    else
        return false;
}
bool testSub(Complex a, Complex b, Complex r)
{
    r.Sub(a, b);
    if ((r.getr() == a.getr() - b.getr()) && (r.geti() == a.geti() - b.geti()))
    {
        return true;
    }
    else
        return false;
}
bool testMulti(Complex a, Complex b, Complex r)
{
    r.Multi(a, b);
    if ((r.getr() == (a.getr() * b.getr() - a.geti() * b.geti()))&&(r.geti() == (a.geti() * b.getr() + a.getr() * b.geti())))
    {
        return true;
    }
    else return false;
}
bool testDiv(Complex a, Complex b, Complex r) 
{
    r.Div(a, b);
    if ((r.getr()==(a.getr()*b.getr()+a.geti()*b.geti())/(b.getr()*b.getr()+b.geti()*b.geti()))&&(r.geti()==(a.geti()*b.getr()-a.getr()*b.geti())/(b.getr()*b.getr()+b.geti()*b.geti())))
    {
        return true;
    }
    else return false;
}
int main()
{
    Complex num1;   // первый объект класса Complex
    Complex num2;   // второй объект класса Complex
    Complex res; // объект, предназначенный для записи результатов вычислений
    num1.Init(2, 8);
    cout << "1st num "<<'\n';
    num1.Display();
    num1.getID();
    num2.Init(1, 5);
    cout << "2nd num "<<'\n';
    num2.Display();
    if (testAdd(num1, num2, res)) { cout << "Adding test was succesfully completed" << endl; }
    else cout << "Adding test was failed" << endl;
    if (testSub(num1, num2, res)) { cout << "Subtraction test 1 was succesfully completed" << endl; }
    else cout << "Subtraction test 1 was failed" << endl;
    if (testSub(num2, num1, res)) { cout << "Subtraction test 2 was succesfully completed" << endl; }
    else cout << "Subtraction test 2 was failed" << endl;
    if (testMulti(num1, num2, res)) { cout << "Multiplication test was succesfully completed" << endl; }
    else cout << "Multiplication test was failed" << endl;
    if (testDiv(num1, num2, res)) { cout << "Division test 1 was succesfully completed" << endl; }
    else cout << "Division test 1 was failed" << endl;
    if (testDiv(num2, num1, res)) { cout << "Division test 2 was succesfully completed" << endl; }
    else cout << "Division test 2 was failed" << endl;
    cout <<"Number of objects:"<<num2.getID()<< endl;
    cout << "In String:" << endl;
    num1.Convert();
    num2.Convert();
    return 0;
}