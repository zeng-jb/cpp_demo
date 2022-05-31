#include<iostream>
#include<math.h>
#define PI 3.1415926
using namespace std;

//Circle��
class Circle
{
	public:
		Circle();  //����������Ĭ�Ϲ��캯��
		Circle(int x, int y, int r):x(x),y(y),r(r){	} //���ó�ʼ���б���г�ʼ���Ĵ��ι��캯��
		~Circle(void)     //��������
		{
			cout<<"\nCircle object is being deleted\n"<<endl; 
		}
		//����Բ�����
		double GetArea()   
		{
			double circle_area;
			circle_area = PI * this->r * this->r;
			return circle_area;
		}
		//��ʾԲ�Ļ�����Ϣ
		void Show()  
		{
			cout<<"������Բ��һЩ������Ϣ:"<<endl; 
			cout<<"Բ�����꣺��"<<this->x<<" , "<<this->y<<"��"<<endl;
			cout<<"ֱ��D = "<<2*this->r<<endl;
			cout<<"�ܳ� = "<<2*PI*this->r<<endl; 
			cout<<"��� = "<<GetArea()<<endl; 
		}
		//�޸�Բ����Ϣ
		void Set(int x, int y, int r)  
		{
			this->x=x;
			this->y=y;
			this->r=r;
		}
		//������Ĺ淶�Լ��
		int Check_input()  
		{
		    if(this->r<0){
 		    cout<<"�������Բ�İ뾶����Ϊ��ֵ!"<<endl;
	    	return -1;
 	        }
 	        return 1;
		}
	private:       //˽�г�Ա����
		int x;
		int y;
		int r;
};

//Rectangle�࣬��Circle���ƣ�����׸��
class Rectangle
{
	public:
		Rectangle();
		Rectangle(int x, int y): x(x),y(y){ } 
		~Rectangle(void)
		{
			cout<<"\nRectangle object is being deleted\n"<<endl; 
		}
		int GetArea()
		{
			return this->x * this->y;
		}
		void Show()
		{
			cout<<"�����Ǿ��ε�һЩ������Ϣ:"<<endl; 
			cout<<"�� = "<<this->x<<" �� = "<<this->y<<endl; 
			cout<<"�ܳ� = "<< 2*(this->x + this->y) <<endl; 
			cout<<"��� = "<<GetArea()<<endl; 
		}
		void Set(int x, int y)
		{
			this->x=x;
			this->y=y;
		}
		int  Check_input()
		{
			if(this->x<=0 || this->y<=0){
				cout<<"������󣺳��Ȳ���Ϊ��ֵ��0��"<<endl;
				return -1;
			}
			return 1;
		}
	private:
		int x;
		int y;
};

//Triangle��
class Triangle
{
	public:
		Triangle();
		Triangle(int x1, int y1, int x2, int y2, int x3, int y3): x1(x1),y1(y1),x2(x2),y2(y2),x3(x3),y3(y3){ }
		~Triangle(void)
		{
			cout<<"\nTriangle object is being deleted\n"<<endl; 
		}
		//��ȡ�����ľ��룬Ҳ�����������������㹹�ɵıߵĳ��� 
		double GetLength(int x1, int y1, int x2 ,int y2)
		{
			double side_length;
			side_length = sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
			return side_length;
		}
		double GetPerimeter()
		{
			double a,b,c;
		    double perimeter;
			a = GetLength(this->x1, this->y1, this->x2, this->y2);
			b = GetLength(this->x1, this->y1, this->x3, this->y3);
			c = GetLength(this->x2, this->y2, this->x3, this->y3);
			perimeter = a + b + c ;
			return perimeter;
		}
		//�������ε������߼��������ε��������ʽ���԰ٶ�~
		double GetArea()
		{
			double a,b,c;
		    double p;
			double area;
			a = GetLength(this->x1, this->y1, this->x2, this->y2);
			b = GetLength(this->x1, this->y1, this->x3, this->y3);
			c = GetLength(this->x2, this->y2, this->x3, this->y3);
			p = GetPerimeter()/2.0;
			area = sqrt( p*(p-a)*(p-b)*(p-c) ); 
			return area;
		}
		void Show()
		{
			cout<<"�����������ε�һЩ������Ϣ:"<<endl;  
			cout<<"�ܳ� = "<<GetPerimeter()<<endl; 
			cout<<"��� = "<<GetArea()<<endl; 
		} 
		void Set(int x1, int y1, int x2, int y2, int x3, int y3){
			this->x1 = x1;
			this->y1 = y1;
			this->x2 = x2;
			this->y2 = y2;
			this->x3 = x3;
			this->y3 = y3;
		}
		int Check_input()
		{
			if( (this->x1-this->x2)*(this->y2-this->y3) == (this->x2-this->x3)*(this->y1-this->y2) ){
				cout<<"��������������㲻�ܹ���������"<<endl;
				return -1;
			}
			return 1;
		}
	private:
		int x1;
		int y1;
		int x2;
		int y2;
		int x3;
		int y3;
 } ;

//main���������ڲ���
 int main()
 {
 	int x,y,r;
 	int x1,y1,x2,y2,x3,y3;
 	char flag;
 	
 	//Բ�Ĳ��Բ��� 
 	cout<<"������Բ�������Ϣ��Բ�ģ�x , y)  �뾶 r "<<endl;
	cin>>x>>y>>r;
 	Circle* circle_obj = new Circle(x,y,r);
 	if(circle_obj->Check_input()>0){
 		circle_obj->Show(); 
    } 
 	cout<<endl<<"�Ƿ���Ҫ��Բ����Ϣ�����޸ģ�Y/N"<<endl;
	cin>>flag;
	if(flag=='Y'||flag=='y'){
		cout<<"�������޸ĺ�Բ����Ϣ�� Բ�ģ�x , y)  �뾶 r "<<endl;
		cin>>x>>y>>r;
		circle_obj->Set(x,y,r);
		if(circle_obj->Check_input()>0){
		    circle_obj->Show();
		}
	
	}
	delete circle_obj;
	
	//���εĲ��Բ���
	cout<<"��������ε������Ϣ���� ��"<<endl;
	cin>>x>>y;
	Rectangle* rectangle_obj = new Rectangle(x,y);
	if(rectangle_obj->Check_input()>0){
		rectangle_obj->Show();
	}
	cout<<endl<<"�Ƿ���Ҫ�Ծ��ε���Ϣ�����޸ģ�Y/N"<<endl;
	cin>>flag;
	if(flag=='Y'||flag=='y'){
		cout<<"�������޸ĺ���ε���Ϣ���� �� "<<endl;
		cin>>x>>y;
		rectangle_obj->Set(x,y);
		if(rectangle_obj->Check_input()>0){
			rectangle_obj->Show();
		}
		
	}
	delete rectangle_obj;
	 
	//�����β��Բ���
	cout<<"�����������ε������������꣺(x1,y1) (x2,y2) (x3,y3)"<<endl;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	Triangle* triangle_obj = new Triangle(x1,y1,x2,y2,x3,y3);
	if( triangle_obj->Check_input()>0){
		triangle_obj->Show();
	} 
	cout<<endl<<"�Ƿ���Ҫ�������εĶ�����������޸ģ�Y/N"<<endl;
	cin>>flag;
	if(flag=='Y'||flag=='y'){
		cout<<"�������޸ĺ������ε������������꣺(x1,y1) (x2,y2) (x3,y3) "<<endl;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		triangle_obj->Set(x1,y1,x2,y2,x3,y3);
		if(triangle_obj->Check_input()>0){
			triangle_obj->Show();
		}
		
	}
	delete triangle_obj;
	
 	return 0;
 } 

