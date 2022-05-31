#include<iostream>
#include<math.h>
#define PI 3.1415926
using namespace std;

//Circle类
class Circle
{
	public:
		Circle();  //不带参数的默认构造函数
		Circle(int x, int y, int r):x(x),y(y),r(r){	} //采用初始化列表进行初始化的带参构造函数
		~Circle(void)     //析构函数
		{
			cout<<"\nCircle object is being deleted\n"<<endl; 
		}
		//计算圆的面积
		double GetArea()   
		{
			double circle_area;
			circle_area = PI * this->r * this->r;
			return circle_area;
		}
		//显示圆的基本信息
		void Show()  
		{
			cout<<"以下是圆的一些基本信息:"<<endl; 
			cout<<"圆心坐标：（"<<this->x<<" , "<<this->y<<"）"<<endl;
			cout<<"直径D = "<<2*this->r<<endl;
			cout<<"周长 = "<<2*PI*this->r<<endl; 
			cout<<"面积 = "<<GetArea()<<endl; 
		}
		//修改圆的信息
		void Set(int x, int y, int r)  
		{
			this->x=x;
			this->y=y;
			this->r=r;
		}
		//对输入的规范性检查
		int Check_input()  
		{
		    if(this->r<0){
 		    cout<<"输入错误：圆的半径不能为负值!"<<endl;
	    	return -1;
 	        }
 	        return 1;
		}
	private:       //私有成员变量
		int x;
		int y;
		int r;
};

//Rectangle类，和Circle类似，不再赘述
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
			cout<<"以下是矩形的一些基本信息:"<<endl; 
			cout<<"长 = "<<this->x<<" 宽 = "<<this->y<<endl; 
			cout<<"周长 = "<< 2*(this->x + this->y) <<endl; 
			cout<<"面积 = "<<GetArea()<<endl; 
		}
		void Set(int x, int y)
		{
			this->x=x;
			this->y=y;
		}
		int  Check_input()
		{
			if(this->x<=0 || this->y<=0){
				cout<<"输入错误：长度不能为负值或0！"<<endl;
				return -1;
			}
			return 1;
		}
	private:
		int x;
		int y;
};

//Triangle类
class Triangle
{
	public:
		Triangle();
		Triangle(int x1, int y1, int x2, int y2, int x3, int y3): x1(x1),y1(y1),x2(x2),y2(y2),x3(x3),y3(y3){ }
		~Triangle(void)
		{
			cout<<"\nTriangle object is being deleted\n"<<endl; 
		}
		//获取两点间的距离，也就是三角形两个顶点构成的边的长度 
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
		//由三角形的三条边计算三角形的面积，公式可以百度~
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
			cout<<"以下是三角形的一些基本信息:"<<endl;  
			cout<<"周长 = "<<GetPerimeter()<<endl; 
			cout<<"面积 = "<<GetArea()<<endl; 
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
				cout<<"输入错误：三个顶点不能构成三角形"<<endl;
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

//main函数，用于测试
 int main()
 {
 	int x,y,r;
 	int x1,y1,x2,y2,x3,y3;
 	char flag;
 	
 	//圆的测试部分 
 	cout<<"请输入圆的相关信息：圆心（x , y)  半径 r "<<endl;
	cin>>x>>y>>r;
 	Circle* circle_obj = new Circle(x,y,r);
 	if(circle_obj->Check_input()>0){
 		circle_obj->Show(); 
    } 
 	cout<<endl<<"是否需要对圆的信息进行修改？Y/N"<<endl;
	cin>>flag;
	if(flag=='Y'||flag=='y'){
		cout<<"请输入修改后圆的信息： 圆心（x , y)  半径 r "<<endl;
		cin>>x>>y>>r;
		circle_obj->Set(x,y,r);
		if(circle_obj->Check_input()>0){
		    circle_obj->Show();
		}
	
	}
	delete circle_obj;
	
	//矩形的测试部分
	cout<<"请输入矩形的相关信息：长 宽"<<endl;
	cin>>x>>y;
	Rectangle* rectangle_obj = new Rectangle(x,y);
	if(rectangle_obj->Check_input()>0){
		rectangle_obj->Show();
	}
	cout<<endl<<"是否需要对矩形的信息进行修改？Y/N"<<endl;
	cin>>flag;
	if(flag=='Y'||flag=='y'){
		cout<<"请输入修改后矩形的信息：长 宽 "<<endl;
		cin>>x>>y;
		rectangle_obj->Set(x,y);
		if(rectangle_obj->Check_input()>0){
			rectangle_obj->Show();
		}
		
	}
	delete rectangle_obj;
	 
	//三角形测试部分
	cout<<"请输入三角形的三个顶点坐标：(x1,y1) (x2,y2) (x3,y3)"<<endl;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	Triangle* triangle_obj = new Triangle(x1,y1,x2,y2,x3,y3);
	if( triangle_obj->Check_input()>0){
		triangle_obj->Show();
	} 
	cout<<endl<<"是否需要对三角形的顶点坐标进行修改？Y/N"<<endl;
	cin>>flag;
	if(flag=='Y'||flag=='y'){
		cout<<"请输入修改后三角形的三个顶点坐标：(x1,y1) (x2,y2) (x3,y3) "<<endl;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		triangle_obj->Set(x1,y1,x2,y2,x3,y3);
		if(triangle_obj->Check_input()>0){
			triangle_obj->Show();
		}
		
	}
	delete triangle_obj;
	
 	return 0;
 } 

