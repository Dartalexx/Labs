#include "Complex.h";
#include "Tests.h";
#include "List.h"
void testList() 
{
    cout << "Adding three elems in  the end: " << endl;
    List A;
    int a = 0;
    char d[11] = "10.12.2015";
    A.addElem(Complex(7, 2));
    A.addElem(child(5, 6, d));
    A.addElem(Complex(10, 5), 2);
    A.print();
    cout << "Deleting second elem: " << endl;
    A.deleteElem(2);
    A.print();
    cout << "Adding elem in second position: " << endl;
    A.addElem(Complex(8, 5), 2);
    A.print();
}