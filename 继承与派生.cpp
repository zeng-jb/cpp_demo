#include <iostream>


using namespace std;


class Point

{

	

	protected:  //�����������Լ��ļ���ϵͳ������ʡ� 

		int y;

		int x;

	public:

		Point()

		{

			cout<<"PointĬ�Ϲ��캯��"<<endl;

		} 

		Point(int _x,int _y)

		{

			cout<<"Point�������Ĺ��캯��"<<endl;

			x=_x; y=_y;

		}

		void base_display()

		{

			cout<<"("<<x<<","<<y<<")"<<endl; 

		}

		

		~Point()

		{

			cout<<"Point����"<<endl; 

		} 

};


//Ҫʵ��һ��ܣ���ȷ��������ݣ�

//Բ�ģ��뾶�� 

class Circle:virtual public Point

{

	protected:

		int r;

	public:

		Circle(int _r)

		{

			cout<<"Circle�Ĺ��캯��"<<endl; 

			r=_r;

		} 

		Circle(int _x,int _y,int _r):Point(_x,_y)

		{

			cout<<"Circle�Ĺ��캯��"<<endl; 

			r=_r;

		} 

		

		void display()

		{   

			cout<<"Radius="<<r<<endl; 

		}

			

		~Circle()

		{

			cout<<"Circle����"<<endl;

		}

};


//�̳и���ķ�ʽ��

//(1)ͨ���̳з�ʽ

//(2)ͨ������µĳ�Ա 

//(3)����ͬ��������ͬ������ 


//�̳�ʱ�����캯����ִ��˳��

//��ִ�л���Ĺ��캯��

//��ִ��������Ĺ��캯���� 

//��������ִ��˳�������෴�� 



//����������£����캯����ִ��˳��

//��ִ�ж����Ա�Ĺ��캯��

//��ִ��������Ĺ��캯���� 

//��ִ��������Ĺ��캯���� 


//���м̳������������£����캯����ִ��˳��

//��ִ�л���Ĺ��캯���� 

//���ж�������ʱ���ǰ��ռ̳е�˳�򹹽��� 

//��ִ�ж����Ա�Ĺ��캯����

//���ж�������Ա��ʱ�򣬰�������˳�򹹽������ǰ���ʼ�����˳�� 

//��ִ��������Ĺ��캯���� 

//��ִ��������Ĺ��캯����


class A

{

	protected:

		int x;

		int y; 

	public:

		

		

		A()

		{

			cout<<"A���캯��"<<endl; 

		}

		A(int x)

		{

			cout<<"A���������캯��"<<endl; 

		}

		~A()

		{

			cout<<"A��������"<<endl;	

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

			cout<<"BĬ�Ϲ��캯��"<<endl;	

		}

		B(int _y)

		{

			cout<<"B���������캯��"<<endl;	

		}

		~B()

		{

			cout<<"B��������"<<endl; 

		}	

 }; 


//˳��ṹ

//��������ִ��˳�������Ϣ�����¼������� 

class Circle2:public A,public B 

{

	private:

		Point c;  //�����Ա 

		

		int r;

	public:

		Circle2()

		{

			cout<<"Circle2Ĭ�Ϲ��캯��"<<endl;

			r=0;

		}

		Circle2(int _x,int _y,int _r):B(_y),c(_x,_y),A(_x) 

		{

			r=_r;

			cout<<"Circle2���������캯��"<<endl;

		} 

		void display()

		{

			c.base_display();

			cout<<r<<endl; 

		}

		~Circle2()

		{

			cout<<"Circle2��������"<<endl; 

		} 

		

};


//�����ͬ��������ĳ�ͻ

//���ӻ�����::,�����������Ƴ�ͻ�ĳ�Ա�� 

//����ԭ��������ͬ�����ǡ� 

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

//Դ��ͬһ�����ȵĳ�ͻ

//ͨ�������ķ���������� 

//ʵ�������ķ����ǵ�һ��������ʱ���ڻ���ǰ����virtual 

//�����Ĺ��캯������ִ�С� 

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
