#include "Complex.h";
void testFile()
{
    ifstream fin;
    ifstream fr;
    int i = 0;
    cout <<"Text file test started: "<<endl;
    fin.exceptions(ifstream::badbit | ifstream::failbit);
    try
    {
        fin.open("D:\\file.txt");
        cout << "File was successfully opened" << endl;
        i++;
        fin.close();
    }
    catch (exception& ex)
    {
        cout << "Incorrect way to file" << endl;
    }
    try
    {
        fin.open("D:\\file.tt");
        cout << "File was successfully opened" << endl;
        fin.close();
    }
    catch (exception& ex)
    {
        cout << "Incorrect way to file" << endl;
        i++;
    }
    if (i == 2)
        cout << "Incorrect way to file was successfully identified" << endl << endl;
    else
        cout << "File opening test was failed" << endl << endl;
}
void testZero()
{
    Complex a(0, 0);
    Complex b(1, 1);
    Complex d(1, 1);
    Complex c;
    int e = 0;
    cout << "Division test started: " << endl;
    try
    {
        c = b / d;
        cout << "Denominator was not a zero"<<endl;
        e++;
    }
    catch (exception& ex)
    {
        cout<<"Denominator was zero"<<endl;
    }
    try
    {
        c = b / a;
        cout << "Denominator was not a zero" << endl;
    }
    catch (exception& ex)
    {
        cout << "Denominator was zero" << endl;
        e++;
    }
    if (e == 2) cout << "Division on zero was succesfully identified" << endl << endl;
    else cout << "Division test was failed" << endl << endl;
}
void testString()
{
    Complex a(10,-10);
    Complex b(10000,10000);
    int i = 0;
    cout<<"Buffer test started: "<<endl;
    try
    {
        a.toString();
        cout <<"There was enough buffer for writing"<<endl;
        i++;
    }
    catch (exception & e)
    {
        cout << "There was not enough buffer for writing" << endl;
    }
    try
    {
        b.toString();
        cout << "There was enough buffer for writing" << endl;
    }
    catch (exception& e)
    {
        cout << "There was not enough buffer for writing" << endl;
        i++;
    }
    if (i == 2) cout << "Buffer test was successfully completed" << endl << endl;
    else cout << "Buffer test was failed" << endl << endl;
}
