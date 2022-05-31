#include <iostream>
#include <string>
#include <math.h>
using namespace std;
void sort(int sum){
	int num=sum;
	int flag=0;
	while(num>0){
		num=num/10;
		flag++;
	}
	flag-=1;
	while(sum>0){
		
		num=sum/pow(10,flag);
		sum=sum%(int)(pow(10,flag--));
		switch(num){
		case 0:cout<<"ling";break;
		case 1:cout<<"yi";break;
		case 2:cout<<"er";break;
		case 3:cout<<"san";break;
		case 4:cout<<"si";break;
		case 5:cout<<"wu";break;
		case 6:cout<<"liu";break;
		case 7:cout<<"qi";break;
		case 8:cout<<"ba";break;
		case 9:cout<<"jiu";break;
	}
	if(flag>=0)	
	cout<<" ";
	}
	cout<<endl;
}
int main(){
	string str;
	int sum=0;
	cin>>str;
	for(int i=0;str[i]!='\0';i++)sum+=str[i]-'0';
	if(sum==0){cout<<"ling";return 0;}
	sort(sum);
	return 0;
}
