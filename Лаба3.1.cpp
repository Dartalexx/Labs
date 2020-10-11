#include <iostream>
#include <conio.h>
#include "Лаба3.1.1.h";
bool testAdd(Complex a,Complex b,Complex r);
bool testSub(Complex a, Complex b, Complex r);
bool testMulti(Complex a, Complex b, Complex r);
bool testDiv(Complex a, Complex b, Complex r);
int main()
{
    Complex num1(2, 8);  // первый объект класса Complex
    Complex num2(1,5); // второй объект класса Complex
    Complex res(num1); // объект, предназначенный для записи результатов вычислений
    cout << "1st num " << '\n';
    if ((num1.getr() != 0) && (num1.geti() > 0))
        cout << num1.getr() << '+' << num1.geti() << 'i' << "\n";
    else
    if ((num1.getr() != 0) && (num1.geti() < 0))
        cout << num1.getr() - num1.geti() << "\n";
    else
    if ((num1.getr() != 0) && (num1.geti() == 0))
        cout << num1.getr() << "\n";
    num1.getID();
    cout << "2nd num " << '\n';
    if ((num2.getr() != 0) && (num2.geti() > 0))
        cout << num2.getr() << '+' << num2.geti() << 'i' << "\n";
    else
    if ((num2.getr() != 0) && (num2.geti() < 0))
        cout << num2.getr() - num2.geti() << "\n";
    else
    if ((num2.getr() != 0) && (num2.geti() == 0))
        cout << num2.getr() << "\n";
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
    cout << "Number of objects:" << num2.getID() << endl;
    cout << "In String:" << endl;
    cout << num1.toString() << endl;
    cout << num2.toString() << endl;
    return 0;
}
