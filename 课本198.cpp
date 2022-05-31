#include <iostream>
#include <string>
using namespace std;
	struct Student
	{
		int num;
		string name;
		char sex;
		float score;
	};
int main()
{

	Student stu;
	Student *p=&stu;
	
	stu.num=00110;
	stu.name="wang feng";
	stu.sex='f';
	stu.score=89.5;
	
	cout<<stu.num<<" "<<stu.name<<" "<<stu.sex<<" "<<stu.score<<endl;
	
	return 0;
}
