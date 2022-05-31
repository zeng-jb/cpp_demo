#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Student{
	int ID;
	char name[20];
};
//公用体    身份 
	union  Type
	{
		int a;
		char b;
		float c;
		double d;
		//不是有四个成员，而是说四种数据 
	   } ;  
enum weekday{sun,mon,tue,wed
}; 
enum Month{jan,fab,mar
};
int main(int argc, char** argv) {
	//视频监控卫星数据
	//只有最后一次成员输入值有效的  公用一个存储空间  大小是成员最大的储存空间 
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
