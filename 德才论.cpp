#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
 
struct na{
public:
	long long num;
	int cai;
	int de;
	int sum;
	na(int s,long long n,int d,int c):sum(s),num(n),de(d),cai(c){};	
};
 
 
bool ga(const na &a1,const na &a2){
	if(a1.sum!=a2.sum)
		return a1.sum>a2.sum;
	else if(a1.de!=a2.de){
		return a1.de>a2.de;
	}else{
		return a1.num<a2.num;
	}
}
 
 
int main(){

	vector<na> ma,mb,mc,md;
	vector<na>::iterator li;
	int n,l,h;
	cin>>n>>l>>h;
	long long num;
	int de,cai;
	int i=0,touchl=0;
	while(i<n){
		scanf("%lld%d%d",&num,&de,&cai);
		if(de>=l&&cai>=l){
			++touchl;
			na x(de+cai,num,de,cai);
			if(de>=h&&cai>=h){
				ma.push_back(x);
			}else if(de>=h&&cai<h){
				mb.push_back(x);
			}else if(de<h&&de>=cai){
				mc.push_back(x);
			}else{
				md.push_back(x);
			}
		}
		++i;
	}
 
	sort(ma.begin(),ma.end(),ga);
	sort(mb.begin(),mb.end(),ga);
	sort(mc.begin(),mc.end(),ga);
	sort(md.begin(),md.end(),ga);
 
	printf("%d\n",touchl);
 
	for(li=ma.begin();li!=ma.end();++li){
		printf("%lld %d %d\n",li->num,li->de,li->cai);
	}
	//cout<<"Aend"<<endl;
	for(li=mb.begin();li!=mb.end();++li){
		printf("%lld %d %d\n",li->num,li->de,li->cai);
	}
	//cout<<"Bend"<<endl;
	for(li=mc.begin();li!=mc.end();++li){
		printf("%lld %d %d\n",li->num,li->de,li->cai);
	}
	//cout<<"Cend"<<endl;
	for(li=md.begin();li!=md.end();++li){
		printf("%lld %d %d\n",li->num,li->de,li->cai);
	}
 
 
	//}
}
