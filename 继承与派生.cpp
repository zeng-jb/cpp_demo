#include <iostream>


using namespace std;


class Point

{

	

	protected:  //就是允许在自己的家族系统里面访问。 

		int y;

		int x;

	public:

		Point()

		{

			cout<<"Point默认构造函数"<<endl;

		} 

		Point(int _x,int _y)

		{

			cout<<"Point带参数的构造函数"<<endl;

			x=_x; y=_y;

		}

		void base_display()

		{

			cout<<"("<<x<<","<<y<<")"<<endl; 

		}

		

		~Point()

		{

			cout<<"Point析构"<<endl; 

		} 

};


//要实现一项功能，明确改造的内容，

//圆心，半径。 

class Circle:virtual public Point

{

	protected:

		int r;

	public:

		Circle(int _r)

		{

			cout<<"Circle的构造函数"<<endl; 

			r=_r;

		} 

		Circle(int _x,int _y,int _r):Point(_x,_y)

		{

			cout<<"Circle的构造函数"<<endl; 

			r=_r;

		} 

		

		void display()

		{   

			cout<<"Radius="<<r<<endl; 

		}

			

		~Circle()

		{

			cout<<"Circle析构"<<endl;

		}

};


//继承改造的方式：

//(1)通过继承方式

//(2)通过添加新的成员 

//(3)定义同名函数，同名覆盖 


//继承时：构造函数的执行顺序

//先执行基类的构造函数

//再执行派生类的构造函数。 

//析构函数执行顺序正好相反。 



//类的组合情况下：构造函数的执行顺序

//先执行对象成员的构造函数

//再执行派生类的构造函数。 

//再执行派生类的构造函数。 


//既有继承又有组合情况下：构造函数的执行顺序

//先执行基类的构造函数。 

//当有多个基类的时候，是按照继承的顺序构建。 

//先执行对象成员的构造函数，

//当有多个对象成员的时候，按声明的顺序构建，不是按初始化表的顺序。 

//再执行派生类的构造函数。 

//再执行派生类的构造函数。


class A

{

	protected:

		int x;

		int y; 

	public:

		

		

		A()

		{

			cout<<"A构造函数"<<endl; 

		}

		A(int x)

		{

			cout<<"A带参数构造函数"<<endl; 

		}

		~A()

		{

			cout<<"A析构函数"<<endl;	

		}	

};


class B

{

	protected:

		int x;

		int y;

		

	public:

		B()

		{

			cout<<"B默认构造函数"<<endl;	

		}

		B(int _y)

		{

			cout<<"B带参数构造函数"<<endl;	

		}

		~B()

		{

			cout<<"B析构函数"<<endl; 

		}	

 }; 


//顺序结构

//面向对象的执行顺序基于消息或者事件触发。 

class Circle2:public A,public B 

{

	private:

		Point c;  //对象成员 

		

		int r;

	public:

		Circle2()

		{

			cout<<"Circle2默认构造函数"<<endl;

			r=0;

		}

		Circle2(int _x,int _y,int _r):B(_y),c(_x,_y),A(_x) 

		{

			r=_r;

			cout<<"Circle2带参数构造函数"<<endl;

		} 

		void display()

		{

			c.base_display();

			cout<<r<<endl; 

		}

		~Circle2()

		{

			cout<<"Circle2析构函数"<<endl; 

		} 

		

};


//解决不同基类引起的冲突

//增加基类名::,用于区分名称冲突的成员。 

//访问原则，派生类同名覆盖。 

class Circle3:public A,public B

{

	protected:

		int x;

		int y;

	public:

		Circle3()

		{

			

		}

		void display()

		{

			cout<<x<<y<<endl;

			cout<<A::x<<A::y<<endl; 

			cout<<B::x<<B::y<<endl;

		}	

};

//源于同一个祖先的冲突

//通过虚基类的方法来解决。 

//实现虚基类的方法是第一层派生的时候，在基类前增加virtual 

//虚基类的构造函数最先执行。 

class Cylinder:virtual public Point,public Circle

{

	public:

		Cylinder():Circle(10)

		{

				

		}

		void display()

		{

			//cout<<Point::x<<Circle::y<<endl;

			cout<<x<<endl;

			cout<<y<<endl;	

		}	

};






int main(int argc, char** argv) {


	Point p(10,20);

	

	Circle c(100,200,300);

	

	Point *pt=&c;

	

	pt->base_display();

	

	

	return 0;

}
