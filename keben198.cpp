#include <iostream>
#include <string>
using namespace std;
	
int main()
{
struct Student
	{
		int num;
	//	string name;
	//	char sex;
		float score;
		struct  student *next;
	};
	Student a,b,c,*p,*head;

	
	a.num=1001;a.score=79.5;
	b.num=1002;b.score=98.5;
	c.num=1003;c.score=88.5;
	head=&a;
	a.next=&b;
	b.next=&c;
	c.next=NULL;
	p=head;
	
	do{
		cout<<p->num<<" "<<p->score<<endl;
		p=p->next;
	}while(p!=NULL);
/*	stu.num=10010;
	stu.name="wang feng";
	stu.sex='f';
	stu.score=89.5;
	
	cout<<stu.num<<" "<<stu.name<<" "<<stu.sex<<" "<<stu.score<<endl;
	cout<<(*p).num<<" "<<(*p).name<<" "<<(*p).sex<<" "<<(*p).score<<endl;
	cout<<p->num<<" "<<p->name<<" "<<p->sex<<" "<<p->score<<endl;*/
	
	return 0;
}
