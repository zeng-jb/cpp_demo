#include <iostream>

#include <cstring>

using namespace std;


class Point

{

	public:

		friend ostream& operator <<(ostream &out,Point &X);

		friend Point & operator ++(Point &p);

		friend Point & operator ++(Point &p,int);

		Point()

		{

			x=0;

			y=0;

		} 

		

		Point(int i,int j)

		{

			x=i;y=j;	

		}

		

		Point operator -()

		{

			x=-x;

			y=-y;

			return *this;

		}

		

		operator double()

		{

			double a=x+y;

			

			return a;

				

		} 

		//什么时候必须要定义赋值运算符重载函数

		//和拷贝构造函数一样，当有指针成员，并且有内存开辟的情况。 

		Point & operator =(Point &P)

		{

			cout<<"调用赋值运算符重载函数"<<endl; 

			x=P.x;

			y=P.y;

			

			return *this;

		}

		

	

		

		

	private:

		int x;

		int y;

};


Point & operator ++(Point &p)

	{

		p.x=p.x+1;

		p.y=p.y+1;

			

		return p;

	}

	Point & operator ++(Point &p,int)

		{

			Point T(p.x,p.y);

			

			p.x=p.x+1;

			p.y=p.y+1;

			

			return T;

		}

ostream& operator <<(ostream &out,Point &X)

{

	out<<"x="<<X.x<<",y="<<X.y<<endl;

}


int main(int argc, char** argv) 

{

		

	Point X(100,200);

		

	Point Y;

	

	Y=X;

	

	cout<<X<<endl;  

	cout<<Y<<endl;  

	

	return 0;

}
