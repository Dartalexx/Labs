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
	void addElem(T c);//Добавление в конец
	void deleteElem(int index);//удаление элемента по номеру
	void addElem(T el,int num);//вставка по номеру
	void deleteElem();//удаление последнего элемента
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
List<T>::List(const List& other)//Конструктор копирования
{
    begin = nullptr;
    length = other.length;
    if (other.length == 0) return;
    begin = new Node(other.begin->data); // Копируем из старого списка в новый
    Node* otherTmp = other.begin->next;
    Node* thisTmp = begin;
    Node* newNode = nullptr;
    while (otherTmp != nullptr) {//поэлементное копирование списка
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
    if (begin == nullptr)// Если нет элементов   
    {
        begin = new Node(el);
        tail = begin;
        length++;
        return;
    }
    Node* newNode = new Node(el); // Создаем новый элемент
    Node* tmp = begin;
    while (tmp->next != nullptr) tmp = tmp->next; // Доходим до последнего элемента
    tmp->next = newNode; // Вставляем новый элемент списка после последнего
    tail = newNode;
    length++;
}
template<typename T>
void List<T>::addElem(T el, int num)//вставка по номеру
{
    if (begin == nullptr)// Если нет элементов   
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
        Node* newNode = new Node(el); // Создаем новый элемент
        Node* tmp = begin;
        for (int i = 1; i < num - 1; i++) tmp = tmp->next; // Доходим до предыдущего элемента
        newNode->next = tmp->next;
        tmp->next = newNode; // Вставляем новый элемент списка после предыдущего
        length++;
        return;
    }
    Node* newNode = new Node(el); // Создаем новый элемент
    Node* tmp = tail;
    tmp->next = newNode; // Вставляем новый элемент списка после предыдущего
    tail = newNode;
    length++;
}
template<typename T>
void List<T>::deleteElem(int index)//удаление элемента по логическому номеру
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
    { // Если удаляем корень
        Node* newBegin = begin->next; // Новый корень
        delete begin; // Удаляем корень
        begin = newBegin; // Присваиваем корню указатель на новый корень
        length--;
        return;
    }
    if (index == length) { // Если удаляем последний элемент
        Node* tmp = begin;
        for (int i = 1; i < index - 1; i++) tmp = tmp->next; // Доходим до предпоследнего элемента
        delete tmp->next; // удаляем
        tmp->next = nullptr; // указатель на удаленный элемент = 0
        tail = tmp;
        length--;
        return;
    }
    Node* tmp = begin;
    for (int i = 1; i < index - 1; i++)
        tmp = tmp->next;// Доходим до элемента, следующий от которого надо удалить
    Node* del = tmp->next; // удаляемый элемент
    tmp->next = del->next; // перекидываем указатели
    delete del; // удаляем элемент
    length--;
}
template<typename T>
void List<T>::deleteElem() //удаление последнего элемента
{
    Node* tmp = begin;
    while (tmp->next != tail) tmp = tmp->next; // Доходим до предпоследнего элемента
    delete tmp->next; // удаляем
    tmp->next = nullptr; // указатель на удаленный элемент = 0
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
