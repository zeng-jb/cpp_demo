#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Student{
	int ID;
	char name[20];
};
//������    ��� 
	union  Type
	{
		int a;
		char b;
		float c;
		double d;
		//�������ĸ���Ա������˵�������� 
	   } ;  
enum weekday{sun,mon,tue,wed
}; 
enum Month{jan,fab,mar
};
int main(int argc, char** argv) {
	//��Ƶ�����������
	//ֻ�����һ�γ�Ա����ֵ��Ч��  ����һ���洢�ռ�  ��С�ǳ�Ա���Ĵ���ռ� 
	Type t;
	t.a=97;
	t.c=97.5;
	
	cout<<t.a<<endl;
	cout<<t.b<<endl;
	
	cout<<t.c<<endl;
	cout<<t.d<<endl; 
	
	weekday today=wed;
	cout<<today<<endl;
	return 0;
}
