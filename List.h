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
	//Тут функции односвязного спискa
	List();
	List(const List&);
	~List();
	void addElem(const Complex& c);//вставка по номеру
	void deleteElem(int index);//удаление элемента по номеру
	void addElem(const Complex& el,int num);//Добавление в конец
	void deleteElem();//удаление последнего элемента
	void addElem(const child& c);//вставка по номеру
	void addElem(const child& el, int num);//Добавление в конец
	void print();
private:
	Node* begin;
	Node* tail;
	int length;
};
