#pragma once
#include "Complex.h"
class Node
{
public:
	Node();
	Node(const Complex& b);
	Node(const child& b);
	Node* next;
	Complex data;
};
class List
{
public:
	//��� ������� ������������ �����a
	List();
	List(const List&);
	~List();
	void addElem(const Complex& c);//������� �� ������
	void deleteElem(int index);//�������� �������� �� ������
	void addElem(const Complex& el,int num);//���������� � �����
	void deleteElem();//�������� ���������� ��������
	void addElem(const child& c);//������� �� ������
	void addElem(const child& el, int num);//���������� � �����
	void print();
private:
	Node* begin;
	Node* tail;
	int length;
};
