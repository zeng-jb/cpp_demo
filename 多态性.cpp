#include <iostream>


using namespace std;


//多态性

// 基类——声明虚函数 

// 派生类 ——重新定义虚函数

// 如果不加vitual 同名覆盖

// 重载。 


// 赋值兼容，公有的派生类对象 


class A

{

	public:

		virtual void display()

		{

			cout<<"A"<<endl;

		}

		~A()

		{

			cout<<"析构A"<<endl;

		} 

 } ;

 

class B:public A

{

	public:

		virtual void display()

		{

			A::display();  //增加基类名称::

			

			((A)(*this)).display();  //基于赋值兼容，向基类对象转换。 

			

		//	((A *)this)->display();

			

			//a.display();

			 

			cout<<"B"<<endl;

		}

};

 

class C:public A

{

	public:

		void display()

		{

			cout<<"C"<<endl;

			

		}

		~C()

		{

			cout<<"析构C"<<endl;

		}

};


//虚析构函数。 

//虚函数的作用：


//用来构建统一的界面。

//纯虚函数：没有函数体的虚函数。

//抽象类：至少有一个纯虚函数的类 

//抽象类的作用：构建界面 

class Geometry

{

	public:

		virtual float zhouchang()=0;

		virtual float area()=0;

 }; 


class Triangle:public Geometry

{

	public:

	  	float zhouchang()

		{

			return 10;	

		}	

		float area()

		{

			return 20;

		}

 }; 


class Rectangle:public Geometry

{

	public:

	  	float zhouchang()

		{

			return 20;	

		}	

		float area()

		{

			return 40;

		}

 };


//构建的顺序： 

//析构的顺序 






int main(int argc, char** argv) {


/*

	Triangle t;

	Rectangle rec;

	

	Geometry *p=&t;

	cout<<p->zhouchang()<<endl;

	cout<<p->area()<<endl;

	

	p=&rec;

	cout<<p->zhouchang()<<endl;

	cout<<p->area()<<endl;

*/

/*

	//可以用一个数组，去保存不同质的对象。 

	A *a[2];

	

	B b;

	C c;

	a[0]=&b;

	a[1]=&c;

	

	for(int i=0;i<2;i++)

	{

		a[i]->display();

	}

*/	

	


	return 0;

}
