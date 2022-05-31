#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#define INF 0x3f3f3f
#define maxn 10001
using namespace std;
int graph[maxn][maxn];
int n,m;
void init()
{
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            if(i==j)
                graph[i][j]=0;
            else
                graph[i][j]=INF;
        }
    }
 
}
void floyd()
{
    for(int k=1; k<=n; ++k)
    {
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=n; ++j)
            {
                if(graph[i][j]>graph[i][k]+graph[k][j])
                {
                    graph[i][j]=graph[i][k]+graph[k][j];
                }
 
            }
        }
 
    }
 
}
int main()
{
 
    cin>>n>>m;
    init();
    for(int i=0; i<m; ++i)
    {
        int a,b;
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
 
    }
    floyd();
    int f=0;//0表示连通 1表示不连通
    for(int j=1; j<=n; ++j)
    {
        if(graph[1][j]==INF)
        {
            f=1;
            break;
        }
 
    }
 
    int k;
    cin>>k;
    while(k--)
    {
        int num;
        cin>>num;
        double average=0;
        for(int j=1; j<=n; ++j)
        {
            if(graph[num][j]!=INF)
                average+=graph[num][j];
 
        }
        average=1.0/(average*1.0/(n-1));
        if(f==1)
        {
            printf("Cc(%d)=%.2f\n",num,0);
 
        }
        else
            printf("Cc(%d)=%.2f\n",num,average);
 
 
    }
    return 0;
}
