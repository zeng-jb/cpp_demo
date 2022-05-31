#pragma once
#include <iostream>
using namespace std;

template<class T>
struct Node
{
	T data;
	Node* link;
};

template <class T>
class List
{
public:
	List() ;    //���캯��
	~List() {};   //��������
	void Createlist();   //β�巨��������
	void Sort(int& a, int& b, int& c); //������a��b��ĸc�ַ�
	void Output(Node<T> *t);  //�������
	void Circlink(Node<T>*& a1, Node<T>*& b1, Node<T>*& c1, int a, int b, int c);   //ѭ���������
private:
	Node<T>* first;     //��ͷָ��
};
