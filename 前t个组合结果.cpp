#include<bits/stdc++.h>
using namespace std;
int n,m,r,t,sum;
int f[100]={0}; 
int vis[100];
void dfs(int x,int cnt){
	if(sum==t){     //如果到数了退出
		return;
	}
	if(cnt-1==m){
		sum++;
		for (int i=1;i<=m;i++){
			printf(" %d", f[i]);
		}
		printf("\n");
	}
	else{
		for(int i=x;i>0;i--){
			if(!vis[i]){
				vis[i]=1;//标记
				f[cnt]=i;//计数
				dfs(i-1,cnt+1);
				vis[i]=0;
			}
		}
	}
}
int main(){
	scanf("%d %d %d",&n,&m,&t);
	memset(vis,0,sizeof(vis));
	sum=0;
	dfs(n,1);
	return 0;
}

