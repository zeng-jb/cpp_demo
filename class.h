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
	List() ;    //构造函数
	~List() {};   //析构函数
	void Createlist();   //尾插法构造链表
	void Sort(int& a, int& b, int& c); //排序函数a数b字母c字符
	void Output(Node<T> *t);  //输出函数
	void Circlink(Node<T>*& a1, Node<T>*& b1, Node<T>*& c1, int a, int b, int c);   //循环链表操作
private:
	Node<T>* first;     //表头指针
};
