#include <iostream>
#include <string>
using namespace std;
struct Person
{
	string name;
	int count;
} leader[3]={"A",0,"B",0,"C",0};
int main()
{
	int i,j;
	string leader_name;
	for(i=0;i<10;i++){
		cin>>leader_name;
		for(j=0;j<3;j++){
			if(leader_name==leader[j].name)
				leader[j].count++;
		}
	}
	cout<<endl;
	for(i=0;i<3;i++)
	{
		cout<<leader[i].name<<":"<<leader[i].count<<endl;
	}
	system("pause");
	return 0;
}