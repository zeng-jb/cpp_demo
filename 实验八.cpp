#include <iostream>
using namespace std;
void swapref(int *p1,int *p2);         //reference ���� 
int main()
{
	cout<<"--------------------------------"<<endl;
	int iv1=888;
	int *pointer_1;    //��������ָ�� 
	pointer_1=&iv1;    //ָ��ָ�����iv1 
	cout<<"iv1       = "<<iv1<<endl;
	cout<<"*pointer_1= "<<*pointer_1<<endl;    //���ָ��ָ�������ֵ 
	cout<<"&iv1      = "<<&iv1<<endl;            //������α���iv1�ĵ�ַ��ռ4���ֽ� 
	cout<<"pointer_1 = "<<pointer_1<<endl;          //ָ����ǵ�ַ��ָ�����iv1�ĵ�ַ ��ռ4���ֽ� 
	
	
	cout<<"--------------------------------"<<endl;
	int iv2=666;
	int *pointer_2;
	pointer_2=&iv2;
	cout<<"iv2       = "<<iv2<<endl;
	cout<<"*pointer_2= "<<*pointer_2<<endl;
	cout<<"&iv2      = "<<&iv2<<endl;
	cout<<"pointer_2 = "<<pointer_2<<endl;
	
	cout<<"--------------------------------"<<endl;
	//swap(pointer_1,pointer_2);                   //���ú��� 
	swap( iv1, iv2 );                            //��ʵ����Ϊ�������� 
	cout<<"iv1       = "<<iv1<<endl;
	cout<<"iv2       = "<<iv2<<endl;
	cout<<"*pointer_1= "<<*pointer_1<<endl;      //ָ�뽻����ָ��ָ�����α���iv2��ֵ 
	cout<<"*pointer_2= "<<*pointer_2<<endl;
	cout<<"pointer_1 = "<<pointer_1<<endl;       //ָ����ǵ�ַ��ָ������ĵ�ַ ���ı�Ҳ�����Ÿı� 
	cout<<"pointer_2 = "<<pointer_2<<endl;
	
	
	return 0;
}
/*void swap(int *p1,int *p2)   //�����������ı�ָ��ָ�������ֵ 
{
	int temp;  //�������ν�������ֵ 
	temp=*p1;
	*p1=*p2;
	*p2=temp;
}*/

/*void swappionter(int *p1,int *p2)
{
	int * temp;   //��������ָ�룬 ����ָ��ָ��ĵ�ַ 
	temp = p1;
	p1 = p2;
	p2 = temp;
}*/
void swap(int &p1,int &p2)    //����ָ��ָ������ĵ�ַ 
{
	int    temp;             //�������α��� 
	temp = p1;
	p1 = p2;
	p2 = temp;
}
