#include <iostream> 
using namespace std;
class Point{
	public:
		Point(int _x,int _y)
		{
			cout<<"Ĭ�Ϲ��캯��"<<endl; 
			x=_x;y=_y;
		}
	/*	~Point()
		{
			cout<<"��������"<<endl;			
		}*/
		void display(){
			cout<<"("<<x<<"."<<y<<")"<<endl;
		}
//	private:

	protected:
		int x=0;
		int y=0;
		
};
//��ȷ��������� 
class  Circle : protected Point
{
	protected:
		int r;
	public:
	Circle()
	{
		r=0;
	}
	Circle(int _r)
	{
		r=_r;
	}
	void display(){
			cout<<"("<<x<<"."<<y<<")"<<endl;
			cout<<"r="<<r<<endl;
		}
}; 
int main()
{
	Circle c;
	c.display();
	
	Point a;
	a.display();
	
	Point::display();
	return 0;
 } 
