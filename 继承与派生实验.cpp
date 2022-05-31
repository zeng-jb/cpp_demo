#include<iostream>
using namespace std;
#define PI 3.14159
class Shape
{
public:
	Shape(){}
	~Shape(){}
	virtual void Draw() = 0;
	virtual double Area() = 0;
};

class Rectangle :public Shape
{
public:
	Rectangle() :a(0), b(0){}    //
	Rectangle(int x, int y) :a(x), b(y) {}
	virtual void Draw()
	{
		cout << "Rectangle area:" << Area() << endl;
	}
	virtual double Area()
	{
		return a * b;
	}
private:
	int a;
	int b;
};

class Circle :public Shape
{
public:
	Circle(double x) :r(x) {}
	virtual void Draw()
	{
		cout << "Circle area:" << Area() << endl;
	}
	virtual double Area()
	{
		return PI*r*r;
	}
private:
	double r;
};

class Square :public Rectangle
{
public:
	Square(int length) :a(length) {}
	virtual void Draw()
	{
		cout << "Square area:" << Area() << endl;
	}
	virtual double Area()
	{
		return a*a;
	}
private:
	int a;
};

int main()
{
	Rectangle rect(10, 20);
	Square square(10);
	Circle circle(8);

	Shape *p;
	p = &rect;
	
	p->Draw();
	p = &square;
	
	p->Draw();
	p = &circle;
	
	p->Draw();

    return 0;
}


