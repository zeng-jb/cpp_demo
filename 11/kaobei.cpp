#include <iostream>
#include <cstring>
using namespace std;

class Box{
	private:
	int length,width,height;
	
	public:
	Box()
	{
		cout<<"Ĭ�Ϲ��캯��"<<endl; 
	}
	 
	Box(int x,int y,int z)
	{
		length=x;
		width=y;
		height=z;
		cout<<"�����ݽṹ����";
		 
	}
	void display()
	{
		cout<<"widht="<<width<<endl;
	}
	~Box()
	{
		cout<<"������������"<<endl;
	}
	Box(const Box &t)
	{
		length=t.length;
		width=t.height;
		height=t.height;
		cout<<"�������캯��"<<endl; 
	}
};

int main(){
	Box a(10,20,30);
	
	Box b=a;
	b.display();
	
	Box c(b);
	c.display();
	
	
	Box d;
	d=c;
	d.display();
	
	
	return 0;
}
