#include "Complex.h";
child::~child()
{
    if(st)
    delete[] st;
    if(date)
    delete[] date;
}
child::child():Complex()//конструктор по умолчанию
{
    st = new char[10];
    date = new char[11];
    for (int i1 = 0; i1 < 9; i1++)
        st[i1] = '0';
    for (int i1 = 0; i1 < 10; i1++)
        date[i1] = '0';
}
child::child(int rl,int im,char* d)//конструктор с параметрами
{
    st = new char[10];
    date = nullptr;
    date = new char[strlen(d) + 1];
    strcpy_s(date,strlen(d)+1,d);
    setR(rl);
    setI(im);
    toString();
}
child::child(child& other)// Конструктор копирования
{
    st = nullptr;
    st = new char[strlen(other.st) + 1];
    strcpy_s(st, strlen(other.st) + 1, other.st);
    date = nullptr;
    date = new char[strlen(other.date) + 1];
    strcpy_s(date, strlen(other.date) + 1, other.date);
    setR(other.getR());
    setI(other.getI());
}
const child& child:: operator = (child other) // перегрузка оператора присваивания
{
    setR(other.getR());
    setI(other.getI());
    st = nullptr;
    st = new char[strlen(other.st) + 1];
    strcpy_s(st, strlen(other.st) + 1, other.st);
    date = nullptr;
    date = new char[strlen(other.date) + 1];
    strcpy_s(date, strlen(other.date) + 1, other.date);
    return (*this);
}
// метод сложения
void child::Add(child op1, child op2) {
    setR(op1.getR() + op2.getR());
    setI(op1.getI() + op2.getI());
}
//метод вычитания
void child::Sub(child op1, child op2) {
    setR(op1.getR() - op2.getR());
    setI(op1.getI() - op2.getI());
}
//метод умножения
void child::Multi(child op1, child op2)
{
    setR(op1.getR()*op2.getR() - op1.getI() * op2.getI());
    setI(op1.getR() * op2.getR() + op1.getI() * op2.getI());
}
//оператор умножения
child child:: operator * (child& other) {
    child temp;
    temp.setR(getR() * other.getR() - getI() * other.getI());
    temp.setI(getR() * other.getR() + getI() * other.getI());;
    return temp;
}
//метод деления
void child::Div(child op1, child op2)
{
    setR((op1.getR() * op2.getR() + op1.getI() * op2.getI()) / (op2.getR() * op2.getR() + op2.getI() * op2.getI()));
    setI((op1.getI() * op2.getR() - op1.getR() * op2.getI()) / (op2.getR() * op2.getR() + op2.getI() * op2.getI()));
}
//оператор деления
child child:: operator / (child& other) // перегрузка оператора деления
{
    child temp;
    if ((other.getR() * other.getR() + other.getI() * other.getI()) == 0)
    {
        return other;
    }
    temp.setR((getR() * other.getR() + getI() * other.getI()) / (other.getR() * other.getR() + other.getI() * other.getI()));
    temp.setI((getI() * other.getR() - getR() * other.getI()) / (other.getR() * other.getR() + other.getI() * other.getI()));
    return temp;
}
char* child::toTrig()
{
    char* tr;
    tr = new char[50];
    float di = getI();
    float ri = getR();
    float f = atan(getI() / getR());
    float ab = abs(getR(), getI());
    sprintf_s(tr, 49, "%1.2f(cos(%1.2f)+sin(%1.2f)i)", ab, f, f);
    return tr;
}
void child::writef(ofstream& out)
{
    if (out.is_open())
    {
        out.write((char*)getR(), sizeof(getR()));
        out.write((char*)getI(), sizeof(getI()));
    }
};
void child::readf(istream& in)
{
    in.read((char*)getR(), sizeof(getR()));
    in.read((char*)getI(), sizeof(getI()));
};
bool child:: operator == ( child o)
{
    return (getR() == o.getR() && getI() == o.getI());
}
bool  operator < ( child o, child o1)
{
    return ((o.getR() < o1.getR()) && (o.getI() < o1.getI()));
}
bool  operator > ( child o, child o1)
{
    return ((o.getR() > o1.getR()) && (o.getI() > o1.getI()));
}
void child::strToNum()//перевод из строки в число
{
    char ch[15];
    char re[5];
    char im[5];
    int i = 0;
    int i1 = 0;
    for (int i1=0;i1<10;i1++)
    ch[i1]=st[i1];
    while (((ch[i] != '-') || (i == 0)) && (ch[i] != '+'))
    {
        re[i] = ch[i];
        i++;
    }
    setR(atoi(re));
    while (ch[i] != 'i')
    {
        im[i1] = ch[i];
        i++;
        i1++;
    }
    setI(atoi(im));
}