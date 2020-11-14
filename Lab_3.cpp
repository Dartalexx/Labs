#include "Complex.h";
#include "Tests.h";
int main()
{
    Complex num1(4, 5);  // первый объект класса Complex
    Complex num2(1, 1); // второй объект класса Complex
    Complex num3(3, 5); // третий объект класса Complex
    Complex num4(1, 1); //четвертый объект класса Complex
    Complex res; // объект, предназначенный для записи результатов вычислений
    cout <<"Before testing: "<<endl;
    cout << num1 << ", "<< num2 <<", "<<num3<<endl;
    if (testText(num1, num2))
    {
        cout << "Object was successfully loaded in and out from text file" << endl; 
    }
    else
    {
        cout << "Loading from text file was failed"<<endl;
    };
    if (testBinary(num1, num3))
    {
        cout << "Object was successfully loaded in and out from binary file" << endl;
    }
    else
    {
        cout << "Loading from binary file was failed" << endl;
    };
    cout << "After testing: " << endl;
    cout << num1 << ", " << num2 << ", " << num3 << endl;
    testConsole(num4);
    return 0;
}
