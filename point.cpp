#include <iostream>
#include "point.h"
using namespace std;

Point::Point(int _x,int _y)
{
	x=_x;
	y=_y;
}
void Point::display()
{
	cout<<"("<<x<<","<<y<<")"<<endl;
}
