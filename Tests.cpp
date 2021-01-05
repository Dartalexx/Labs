#include "Complex.h";
void testCopy() 
{
    cout <<"Testing object copying: "<<endl<<endl;
    char* d = new char[11];
    char c[11] = "10.10.2005";
    d = c;
    child A(5, 5, d);
    cout << "Testing object copying by constructor(object B was created as copy of object A): " << endl << endl;
    child B(A);
    cout << "Object A: " << endl;
    cout << A.getString();
    cout << A.getDate() << endl;
    cout << "Object B: " << endl;
    cout << B.getString();
    cout << B.getDate() << endl;
    cout << "Here we using a methods of parent's class(setR and setI) to change the real and imaginary parts of number A:" << endl ;
    child C;
    A.setR(7);
    A.setI(15);
    A.toString();
    C = A;
    cout << "Testing object copying by operator(object C was created as copy of object A): " << endl << endl;
    cout << "Object A: " << endl;
    cout << A.getString();
    cout << A.getDate() << endl;
    cout << "Object C: " << endl;
    cout << C.getString();
    cout << C.getDate() << endl;
}