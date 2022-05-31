#include <iostream>
#include <cstring>
using namespace std;

class Box{
	private:
	int length,width,height;
	
	public:
	Box()
	{
		cout<<"默认构造函数"<<endl; 
	}
	 
	Box(int x,int y,int z)
	{
		length=x;
		width=y;
		height=z;
		cout<<"带数据结构参数";
		 
	}
	void display()
	{
		cout<<"widht="<<width<<endl;
	}
	~Box()
	{
		cout<<"调用析构函数"<<endl;
	}
	Box(const Box &t)
	{
		length=t.length;
		width=t.height;
		height=t.height;
		cout<<"拷贝构造函数"<<endl; 
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
