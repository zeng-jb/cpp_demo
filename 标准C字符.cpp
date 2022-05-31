#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	string s;
	int index=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[0]>='0'&&s[0]<='9') {
			index=1;
		}
		if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z'||s[i]>='0'&&s[i]<='9'||s[i]=='_')
			continue;
		else {
			index=1;	
		}
	}
	if(index==0) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}
