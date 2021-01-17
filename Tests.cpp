#include "Tests.h";
#include "List.h"
void testList() 
{
    cout << "Adding Complex elem in  the end: " << endl;
    List<Complex> A;
    List<int> B;
    List<float> C;
    A.addElem(Complex(7, 2));
    cout << "This is Complex List:" << endl;
    A.print();
    B.addElem(2);
    cout << "This is int List:" << endl;
    B.print();
    C.addElem(5.56);
    cout << "This is float List:" << endl;
    C.print();
}