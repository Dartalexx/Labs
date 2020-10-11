#pragma once
using namespace std;
// определение класса комплексных чисел
class Complex {
public:
    Complex()
    {
        i = 0;
        r = 0;
    }
    Complex(int rl, int im)//конструктор с параметрами
    {
        st = new char[10];
        r = rl;
        i = im;
        for (int i1 = 0; i1 < 10; i1++)
            st[i1] ='0';
    }
    Complex(const Complex& other)// Конструктор копирования
    {
        st = new char[10];
        r = other.r;
        i = other.i;
        for (int i1 = 0; i1 < 10; i1++)
            st[i1] = other.st[i1];
    }
    void Add(Complex x, Complex y);  // Сложить комплексныые числа
    void Sub(Complex x, Complex y);  // вычесть комплексные числа
    void Multi(Complex x, Complex y); // умножение комплексных чисел
    void Div(Complex x, Complex y); // Деление комплексных чис
    char* toString(); //перевод в строку
    int getr() { return r; }
    int geti() { return i; }
    int getID() { c_id = c++;  return c_id; }//получение номера объекта класса
    ~Complex(); //Деструктор
private:
    int r;  // вещественная часть
    int i;  // мнимая часть
    char* st; //строковое представление
    static int c;
    int c_id;
};

