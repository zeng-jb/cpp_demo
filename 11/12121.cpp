#include <iostream>
#include <cstring>
using namespace std;
int main(){
	char a[31];
	int b[31],k=2;
	int i;
	gets(a);
	int alen=strlen(a);
	for( i=0;i<alen-1;i++){
		b[i]=a[i]-'0';
	}
	for( i=0;i<alen-1;i++){
		cout<<b[i]<<" ";
	}
	while(k<=9){
		int flag=0;
		for( i=0;i<alen-2;i++){
			flag=b[i]%k;
			b[i+1]+=flag*10;
		}
		if(flag==0) cout<<k<<" ";
	}
	return 0;
}