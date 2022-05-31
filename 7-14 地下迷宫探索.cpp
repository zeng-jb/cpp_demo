#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<math.h>
#include<algorithm>
#include<map>
#include<vector>
#define ll long long
using namespace std;
const int N = 1e3+10;
const int Pi = acos(-1);
int n,m,S;
int g[N][N],vis[N];
void dfs(int u)
{
	int f=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]&&g[u][i]!=-1)
		{
			f=1;
			vis[i]=1;
			printf(" %d",i);//输出u的下一个节点 
			dfs(i);
			printf(" %d",u);//返回u，其实有可能在一个序列中u会出现多次 
		}
	}
} 
int main()
{
	scanf("%d%d%d",&n,&m,&S);
	int a,b;
	memset(g,-1,sizeof(g));
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		g[a][b]=1;
		g[b][a]=1;
	} 
	vis[S]=1;
	printf("%d",S);//符合输出格式 
	dfs(S);
	int f=0;
	for(int i=1;i<=n;i++)//判断图是否连通 
	{
		if(!vis[i])
		{
			f=1;
			break;
		} 
	}
	if(f) printf(" 0");
	return 0;
}

