#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int N,K;
	vector<string> course[2501];
	
	scanf("%d %d",&N,&K); 
	for(int i=0;i<N;i++){
		char name[5];
		scanf("%s",&name);
		int C;
		scanf("%d",&C);
		for(int j=0;j<C;j++){
			int num;
			scanf("%d",&num);
			course[num].push_back(name);
		}
	}
	
	for(int i=1;i<=K;i++){
		printf("%d %d\n",i,course[i].size());
		sort(course[i].begin(),course[i].end());
		for(int j=0;j<course[i].size();j++){
			printf("%s\n",course[i][j].c_str());
			
		}
	}
	return 0;
}
