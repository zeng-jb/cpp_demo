#include <iostream>


using namespace std;


//��̬��

// ���ࡪ�������麯�� 

// ������ �������¶����麯��

// �������vitual ͬ������

// ���ء� 


// ��ֵ���ݣ����е���������� 


class A

{

	public:

		virtual void display()

		{

			cout<<"A"<<endl;

		}

		~A()

		{

			cout<<"����A"<<endl;

		} 

 } ;

 

class B:public A

{

	public:

		virtual void display()

		{

			A::display();  //���ӻ�������::

			

			((A)(*this)).display();  //���ڸ�ֵ���ݣ���������ת���� 

			

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

			cout<<"����C"<<endl;

		}

};


//������������ 

//�麯�������ã�


//��������ͳһ�Ľ��档

//���麯����û�к�������麯����

//�����ࣺ������һ�����麯������ 

//����������ã��������� 

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


//������˳�� 

//������˳�� 






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

	//������һ�����飬ȥ���治ͬ�ʵĶ��� 

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
