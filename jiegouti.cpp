#include <iostream>
#include <string>
using namespace std;

struct  Person{
	string name;
	int count;
}Leader[3]={"li",0,"zhang",0,"sun",0};

int main()
{
	int i,j;
	string Leader_name;
	for(i=0;i<10;i++){
		cin>>Leader_name;
		for(j=0;j<3;j++){
			if(Leader_name==Leader[j].name) Leader[j].count++;
		}
	}
	cout<<endl;
	for(i=0;i<3;i++){
		cout<<Leader[i].name<<":"<<Leader[i].count<<endl;
	}
	return 0;
 } 
