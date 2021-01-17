#pragma once
#include "Complex.h"
template<typename T>
class List
{
	class Node
	{
	public:
		Node()
		{ next = nullptr; };
		Node(T b) 
		{
			next = nullptr;
			data = b;
		};
		Node* next;
		T data;
	};
public:
	List();
	List(const List&);
	~List();
	void addElem(T c);//���������� � �����
	void deleteElem(int index);//�������� �������� �� ������
	void addElem(T el,int num);//������� �� ������
	void deleteElem();//�������� ���������� ��������
	void print();
private:
	Node* begin;
	Node* tail;
	int length;
};
template<typename T>
List<T>::List()
{
    begin = nullptr;
    tail = nullptr;
    length = 0;
}
template<typename T>
List<T>::List(const List& other)//����������� �����������
{
    begin = nullptr;
    length = other.length;
    if (other.length == 0) return;
    begin = new Node(other.begin->data); // �������� �� ������� ������ � �����
    Node* otherTmp = other.begin->next;
    Node* thisTmp = begin;
    Node* newNode = nullptr;
    while (otherTmp != nullptr) {//������������ ����������� ������
        newNode = new Node(otherTmp->data);
        thisTmp->next = newNode;
        otherTmp = otherTmp->next;
        thisTmp = thisTmp->next;
    }
}
template<typename T>
List<T>::~List()
{
    Node* tmp = begin;
    Node* del = nullptr;
    while (tmp != nullptr)
    {
        del = tmp;
        tmp = tmp->next;
        delete del;
    }
}
template<typename T> void List<T>::addElem(T el)
{
    if (begin == nullptr)// ���� ��� ���������   
    {
        begin = new Node(el);
        tail = begin;
        length++;
        return;
    }
    Node* newNode = new Node(el); // ������� ����� �������
    Node* tmp = begin;
    while (tmp->next != nullptr) tmp = tmp->next; // ������� �� ���������� ��������
    tmp->next = newNode; // ��������� ����� ������� ������ ����� ����������
    tail = newNode;
    length++;
}
template<typename T>
void List<T>::addElem(T el, int num)//������� �� ������
{
    if (begin == nullptr)// ���� ��� ���������   
    {
        begin = new Node(el);
        tail = begin;
        length++;
        return;
    }
    if (num == 1)
    {
        Node* newNode = new Node(el);
        newNode->next = begin;
        begin = newNode;
        length++;
        return;
    }
    if (num == length)
    {
        Node* newNode = new Node(el); // ������� ����� �������
        Node* tmp = begin;
        for (int i = 1; i < num - 1; i++) tmp = tmp->next; // ������� �� ����������� ��������
        newNode->next = tmp->next;
        tmp->next = newNode; // ��������� ����� ������� ������ ����� �����������
        length++;
        return;
    }
    Node* newNode = new Node(el); // ������� ����� �������
    Node* tmp = tail;
    tmp->next = newNode; // ��������� ����� ������� ������ ����� �����������
    tail = newNode;
    length++;
}
template<typename T>
void List<T>::deleteElem(int index)//�������� �������� �� ����������� ������
{
    if (index < 1 || index > length) return;
    if (length == 1) {
        delete begin;
        delete tail;
        begin = nullptr;
        tail = nullptr;
        length = 0;
        return;
    }
    if (index == 1)
    { // ���� ������� ������
        Node* newBegin = begin->next; // ����� ������
        delete begin; // ������� ������
        begin = newBegin; // ����������� ����� ��������� �� ����� ������
        length--;
        return;
    }
    if (index == length) { // ���� ������� ��������� �������
        Node* tmp = begin;
        for (int i = 1; i < index - 1; i++) tmp = tmp->next; // ������� �� �������������� ��������
        delete tmp->next; // �������
        tmp->next = nullptr; // ��������� �� ��������� ������� = 0
        tail = tmp;
        length--;
        return;
    }
    Node* tmp = begin;
    for (int i = 1; i < index - 1; i++)
        tmp = tmp->next;// ������� �� ��������, ��������� �� �������� ���� �������
    Node* del = tmp->next; // ��������� �������
    tmp->next = del->next; // ������������ ���������
    delete del; // ������� �������
    length--;
}
template<typename T>
void List<T>::deleteElem() //�������� ���������� ��������
{
    Node* tmp = begin;
    while (tmp->next != tail) tmp = tmp->next; // ������� �� �������������� ��������
    delete tmp->next; // �������
    tmp->next = nullptr; // ��������� �� ��������� ������� = 0
    tail = tmp;
    length--;
}
template<typename T>
void List<T>::print()
{
    int i = 1;
    Node* tmp = begin;
    cout << "Printing the full list of elems: " << endl;
    while (tmp != nullptr)
    {
        cout << "Elem number: " << i << endl;
        cout << "Elem data " << tmp->data;
        cout << endl;
        i++;
        tmp = tmp->next;
    }
}
