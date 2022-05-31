#include<iostream>
using namespace std;
#define MAXN 1010
#define MAXM 3010
#define INF 0xffff

typedef struct GNode{
    int n;
    int e;
    int AdjMatrix[MAXN][MAXN];
};

struct GNode g;
int lowcost[MAXN];
int closest[MAXN];
int cost = 0;     //��¼��С�ܻ���

void Prim(int v)
{
    int mincost;
    for(int i = 1;i<=g.n;i++)
    {
        lowcost[i] = g.AdjMatrix[v][i];
        closest[i] = v;
    }
    for(int i  = 1;i<g.n;i++)//Ѱ��n-1����
    {
        int mincost = INF;
        int k = -1;
        for(int j = 1;j<=g.n;j++)    //Ѱ�����е���̱߼��뵽v������
        {
            if(lowcost[j]!=0&&lowcost[j]<mincost)
            {
                mincost = lowcost[j];
                k = j;
            }
        }
        if(k!=-1)
        {
            lowcost[k] = 0;  //���k�ҵ�
            cost+=mincost;   //��������
        }
        else   //������Ҳ�Ҳ���������k
            break;
        for(int j = 1;j<=g.n;j++)
        {
            if(g.AdjMatrix[k][j]!=0&&g.AdjMatrix[k][j]<lowcost[j])
            {
                lowcost[j] = g.AdjMatrix[k][j];
                closest[j] = k;
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    g.e = m;
    g.n = n;
    //�ڽӾ����ʼ��
    for(int i = 0;i<=n;i++)
        for(int j = 0;j<=n;j++)
        {
            if(i==j)
                g.AdjMatrix[i][j] = 0;
            else
                g.AdjMatrix[i][j] = INF;
        }
    //�����ڽӾ���
    for(int i = 0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        g.AdjMatrix[a][b] = g.AdjMatrix[b][a] = w;
    }
    Prim(1);
    int flagAll = 1;
    for(int i = 1;i<=g.n;i++)
    {
        if(lowcost[i]!=0)
        {
            flagAll = 0;
            break;
        }
    }
    if(flagAll)
        cout<<cost<<endl;
    else
        cout<<"-1"<<endl;
    return 0;
}
