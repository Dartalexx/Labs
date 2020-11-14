#include "Complex.h";
bool testMulti(Complex a, Complex b, Complex t)
{
    t = a * b;
    if ((t.getR() == (a.getR() * b.getR() - a.getI() * b.getI())) && (t.getI() == (a.getI() * b.getR() + a.getR() * b.getI())))
    {
        return true;
    }
    else return false;
}
bool testDiv(Complex a, Complex b, Complex t)
{
    t = a / b;
    if ((t.getR() == (a.getR() * b.getR() + a.getI() * b.getI()) / (b.getR() * b.getR() + b.getI() * b.getI())) && (t.getI() == (a.getI() * b.getR() - a.getR() * b.getI()) / (b.getR() * b.getR() + b.getI() * b.getI())))
    {
        return true;
    }
    else return false;
}
bool testEqual(Complex a, Complex b)
{
    if ((a == b) == ((a.getI() == b.getI()) && (a.getR() == b.getR())))
        return true;
    else return false;
}
bool testLSign(Complex a, Complex b)
{
    if ((a < b) == ((a.getI() < b.getI()) && (a.getR() < b.getR())))
        return true;
    else return false;
}
bool testMSign(Complex a, Complex b)
{
    if ((a > b) == ((a.getI() > b.getI()) && (a.getR() > b.getR())))
        return true;
    else return false;
}
bool testText(Complex& a,Complex& b) //тест ввода/вывода в текстовый файл
{
    cout << "Testing Text file: "<<endl;
    ofstream fout("D:\\file.txt");
    if (fout.is_open())
    {
        fout << a;
    }
    fout.close();
    ifstream fin("D:\\file.txt");
    if (fin.is_open())
    {
        fin >> b;
    }
    fin.close();
    if ((a.getR()==b.getR())&&(a.getI()==b.getI())) 
    { 
        return true; 
    } 
    else 
    { 
        return false;
    };
};
bool testBinary(Complex& a, Complex& b) //тест ввода/вывода в двоичный файл
{
    cout << "Testing Binary file: " << endl;
    ofstream fout("D:\\file1.dat", ios::binary || ios::app);
    if (fout.is_open())
    {
        a.writef(fout);
    }
    fout.close();
    ifstream fr("D:\\file1.dat", ios::binary);
    if (fr.is_open())
        b.readf(fr);
    fr.close();
    if ((a.getR() == b.getR()) && (a.getI() == b.getI()))
    {
        return true;
    }
    else
    {
        return false;
    };
};
void testConsole(Complex& a)
{
    cout << "Enter the complex number:"<<endl;
    cin >> a;
    cout << "Entered number: ";
    cout << a <<endl;
};