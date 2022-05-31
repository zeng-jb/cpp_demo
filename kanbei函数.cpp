#include <iostream>
#include <cstring>
using namespace std;

class Box{
	public:
		static int count;//��̬��Աstatic ���ڶ����������ʼ�� 
	private:
		int length,width,height;
		char *name;
	public:
	Box()
	{
		cout<<"Ĭ�Ϲ��캯��"<<endl; 
		name=NULL;
		count++;
	}
	 
	Box(int x,int y,int z,char *n)
	{
		length=x;
		width=y;
		height=z;
		
		name= new char;
		
		count++;
		
		cout<<"�����ݽṹ����"<<endl;;
		 
	}
	void display()
	{
		cout<<"width="<<width<<",height="<<height<<",length="<<length<<endl;
		if(name!=NULL)
			cout<<name<<endl;
	}
	
static	void print()
	{
		cout<<"count:"<<Box::count<<endl;
	}
	
	~Box()
	{
		if(name!=NULL){
				delete name;
		}
		cout<<"������������"<<endl;
	}
	Box(const Box &t)
	{
		length=t.length;
		width=t.width;
		height=t.height;
		
		count++;
		
		int len=strlen(t.name);
		name=new char[len+1];
		strcpy(name,t.name);
		
		cout<<"�������캯��"<<endl; 
	}
};
 int Box::count=0;


int main(){
	Box a(10,20,30,"box1");
	
	Box b=a;
	b.display();
	
	Box c(b);
	c.display();
	
	
	Box d;
	d=c;
	d.display();
	
	Box e(15,25,45,"box5");
	e.display();
	
	cout<<d.count<<endl;
	cout<<Box::count<<endl; 
	
	Box::print();
	d.print();
	
	return 0;
}
