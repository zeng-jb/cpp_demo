#include <iostream>
using namespace std;
void swapref(int *p1,int *p2);         //reference 引用 
int main()
{
	cout<<"--------------------------------"<<endl;
	int iv1=888;
	int *pointer_1;    //定义整形指针 
	pointer_1=&iv1;    //指针指向变量iv1 
	cout<<"iv1       = "<<iv1<<endl;
	cout<<"*pointer_1= "<<*pointer_1<<endl;    //输出指针指向变量的值 
	cout<<"&iv1      = "<<&iv1<<endl;            //输出整形变量iv1的地址，占4个字节 
	cout<<"pointer_1 = "<<pointer_1<<endl;          //指针就是地址，指向变量iv1的地址 ，占4个字节 
	
	
	cout<<"--------------------------------"<<endl;
	int iv2=666;
	int *pointer_2;
	pointer_2=&iv2;
	cout<<"iv2       = "<<iv2<<endl;
	cout<<"*pointer_2= "<<*pointer_2<<endl;
	cout<<"&iv2      = "<<&iv2<<endl;
	cout<<"pointer_2 = "<<pointer_2<<endl;
	
	cout<<"--------------------------------"<<endl;
	//swap(pointer_1,pointer_2);                   //调用函数 
	swap( iv1, iv2 );                            //以实参作为参数调用 
	cout<<"iv1       = "<<iv1<<endl;
	cout<<"iv2       = "<<iv2<<endl;
	cout<<"*pointer_1= "<<*pointer_1<<endl;      //指针交换，指针指向整形变量iv2的值 
	cout<<"*pointer_2= "<<*pointer_2<<endl;
	cout<<"pointer_1 = "<<pointer_1<<endl;       //指针就是地址，指向变量的地址 ，改变也会随着改变 
	cout<<"pointer_2 = "<<pointer_2<<endl;
	
	
	return 0;
}
/*void swap(int *p1,int *p2)   //交换函数，改变指针指向变量的值 
{
	int temp;  //定义整形交换变量值 
	temp=*p1;
	*p1=*p2;
	*p2=temp;
}*/

/*void swappionter(int *p1,int *p2)
{
	int * temp;   //定义整形指针， 交换指针指向的地址 
	temp = p1;
	p1 = p2;
	p2 = temp;
}*/
void swap(int &p1,int &p2)    //交换指针指向变量的地址 
{
	int    temp;             //定义整形变量 
	temp = p1;
	p1 = p2;
	p2 = temp;
}
