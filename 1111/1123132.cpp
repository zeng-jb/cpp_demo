#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
inline int read(){
	register char ch;
	int score;
	while((score=getchar())>'9'||score<'0');
	for(score-='0';(ch=getchar())>='0'&&ch<='9';score=score*10+ch-'0');
	return score;
}
int main()
{
	int hash[11],a,b,c,d,e,n,score;
	memset(hash,0,sizeof(hash));
	n=read();
	for(int i=0;i<n;i++){
		score=read();
		hash[score/10]++;
	}
	a=hash[10]+hash[9];
	b=hash[8];
	c=hash[7];
	d=hash[6];
	e=hash[5]+hash[4]+hash[3]+hash[2]+hash[1]+hash[0];
	cout<<a<<" "<<b<<' '<<c<<' '<<d<<' '<<e;
//	system("pause");
	return 0;
 } 
