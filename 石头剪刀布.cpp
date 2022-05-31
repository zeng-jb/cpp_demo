#include <bits/stdc++.h>
#include <map>
#include <string.h>
#include <iostream>
using namespace std;
int main(){
	int n,jwin=0,ywin=0;
	string str;
	map<char,int> jia,yi;
	cin>>n;
	for(int i=0;i<=n;i++){
		getline(cin,str);
		
		if(((str[0]=='C')&&(str[2]=='J'))||((str[0]=='J')&&(str[2]=='B'))||((str[0]=='B')&&(str[2]=='C'))){
			jwin++;
			jia[str[0]]+=1;
		}
		if(((str[0]=='C')&&(str[2]=='B'))||((str[0]=='J')&&(str[2]=='C'))||((str[0]=='B')&&(str[2]=='J'))){
			ywin++;
			yi[str[2]]+=1;
		}
	}
	printf("%d %d %d\n",jwin,n-jwin-ywin,ywin);
	printf("%d %d %d\n",ywin,n-jwin-ywin,jwin);
	char a,b;
	a=jia['B']>=jia['C'] ? (jia['B']>=jia['J'] ? 'B' : 'J') : (jia['C']>=jia['J'] ? 'C' : 'J');
	b=yi['B']>=yi['C'] ? (yi['B']>=yi['J'] ? 'B' : 'J') : (yi['C']>=yi['J'] ? 'C' : 'J');
	printf("%c %c\n",a,b);
	return 0;
} 
