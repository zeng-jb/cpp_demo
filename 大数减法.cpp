#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char a[210],b[210];
	int c[210],d[210];
	int i,j,k,alen,blen;
	gets(a);
	//cin>>"\n";
	gets(b);
	alen=strlen(a);blen=strlen(b);
	for(i=0;i<alen;i++){
		c[alen-1-i]=a[i]-'0';
	} 
	for(j=0;j<blen;j++){
		d[blen-1-j]=b[j]-'0';
	}
	
/*	for(i=0;i<alen;i++){
		cout<<c[i];
	}
	cout<<endl;
	for(j=0;j<blen;j++){
		cout<<d[j];
	}*/
	int t;
	for(i=0;i<alen;i++){
		t=c[i]-d[i];
		if(t<0){
			c[i+1]-=1;
			c[i]=t+10;
		}else  c[i]=t;
		if(i==blen) break;
	}
	while(c[alen-1]==0) alen--;
	for(i=alen-1;i>=0;i--){
	//	if(c[i]==0) continue;
		 cout<<c[i];
	}
	return 0;
 } 
