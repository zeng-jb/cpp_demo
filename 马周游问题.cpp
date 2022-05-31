
/*
#include<iostream>
#include <stdlib.h>
#include <iomanip>
 
using namespace std;
 
//�����ε����̣�ע��ʹ�õ�ʱ���Ǵ��±�Ϊ1��ʼ
int board[100][100];
 
int fx[]= {2,1,-1,-2,-2,-1,1,2};
int fy[]= {-1,-2,-2,-1,1,2,2,1};
 
int n; //���̴�С
 
//����x,y ��ʾ���̵�λ��
//���(x,y) ��Ӧλ�����������Ƿ�Ϸ�
bool check(int x,int y)
{
    if(x<1 || y<1 || x>n || y>n || board[x][y] != 0)
        return false;
    return true;
}
 
//������
void outputResult(int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout<<" "<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
 
void runTable(int a,int b,int number)
{
    if(number == n*n) //�Ѿ��������������еĵ�
    {
        outputResult(n); //���
        exit(1);
    }
 
    for(int i=0; i<8; i++) //��ʾÿһ�����а����߷�
    {
        if(check(a + fx[i],b + fy[i]))
        {
            int x = a + fx[i];
            int y = b + fy[i];
 
            board[x][y] = number+1; //�ߵ���һ��λ�ã����������Ϊ number+1
 
            runTable(x, y,number+1);
            board[x][y] = 0;//����
        }
    }
}
 
//�ݹ��߷�
void horseRun(int x,int y)
{
    int number = 1;
    board[x][y] = number; //����ȷ����ʼλ������������Ϊ1
    runTable(x, y,number);
}
 
int main()
{
    //cout<<"�������̴�Сn:";
    cin>>n;
 
    int x,y;
    //cout<<"������������ʼλ��x(1~n),y(1~n):";
    cin>>x>>y;
 
    horseRun(x,y);
    return 0;
}

*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <queue>
using namespace std;

typedef struct {
    int x;
    int y;
} Step;

Step step[8] = { {-2, -1}, {-1, -2}, { 1, -2}, { 2, -1}, { 2, 1}, { 1, 2}, {-1, 2}, {-2,1} };

struct NextPos {
    int nextPosSteps; //��ʾ��һλ���ж������߷����߷��ٵ����ȿ���
    int nextPosDirection; //��һλ������ڵ�ǰλ�õķ�λ
    int nextPosToMidLength; //��ʾ��ǰλ�þ��м����룻�����м��Զ�����ȿ���
    bool operator < (const NextPos &a) const {
        return nextPosSteps > a.nextPosSteps && nextPosToMidLength < a.nextPosToMidLength;
    }
    
};

int board[1000][1000];
int M,N; //���̴�С
//������λ���Ƿ������
bool check(int x, int y) {
    if (x >= 0 && x < M && y >= 0 && y < N && board[x][y] == 0)
        return true;
    return false;
}
//��һλ���ж������߷�
int nextPosHasSteps(int x, int y) {
    int steps = 0;
    for (int i = 0; i < 8; ++i) {
        if (check(x + step[i].x, y + step[i].y))
            steps++;
    }
    return steps;
}
//�ж��Ƿ�ص����
bool returnStart(int x, int y) {
    //У������Ƿ���Իص���㣬Ҳ�������̵��м�λ��
    int midx,midy;
    midx = M / 2 - 1;
    midy = N / 2 - 1;
    for (int i = 0; i < 8; ++i)
        if (x + step[i].x == midx && y + step[i].y == midy)
            return true;
    return false;
}

//������
void outputResult(int xstart,int ystart) {
    int num = M * N;
    int k = num - board[xstart][ystart];
    for (int i = 0; i < M; ++i) {
        //cout<<endl<<endl;
        for (int j = 0; j < N; ++j) {
            board[i][j] = (board[i][j] + k) % num + 1;
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    //cout<<endl<<endl;
}

//ĳһλ�þ����������ĵľ���
int posToMidLength(int x,int y) {
    int midx = M / 2 - 1;
    int midy = N / 2 - 1;
    return (abs(x - midx) + abs(y - midy));
}
 
void runTable(int a,int b,int number)
{
    if(number == n*n) //�Ѿ��������������еĵ�
    {
        outputResult(n); //���
        exit(1);
    }
 
    for(int i=0; i<8; i++) //��ʾÿһ�����а����߷�
    {
        if(check(a + fx[i],b + fy[i]))
        {
            int x = a + fx[i];
            int y = b + fy[i];
 
            board[x][y] = number+1; //�ߵ���һ��λ�ã����������Ϊ number+1
 
            runTable(x, y,number+1);
            board[x][y] = 0;//����
        }
    }
}

void BackTrace(int t, int x, int y,int xstart,int ystart) {
    //�ҵ����
    if (t == M * N && returnStart(x,y)) {//���������̵�����λ�ã����������Իص���㣬�γɻ�·
        outputResult(xstart,ystart);
        exit(1);
    }
    else {
        priority_queue<NextPos> nextPosQueue;
        for (int i = 0; i < 8; ++i) {
            if (check(x + step[i].x, y + step[i].y)) {
                NextPos aNextPos;
                aNextPos.nextPosSteps = nextPosHasSteps(x + step[i].x, y + step[i].y);
                aNextPos.nextPosDirection = i;
                aNextPos.nextPosToMidLength = posToMidLength(x + step[i].x,y + step[i].y);
                nextPosQueue.push(aNextPos);
            }
        }
        
        while(nextPosQueue.size()) {
            int d = nextPosQueue.top().nextPosDirection;
            nextPosQueue.pop();
            x += step[d].x;
            y += step[d].y;
            board[x][y] = t + 1;
            BackTrace(t + 1, x, y,xstart,ystart);
            //����
            board[x][y] = 0;
            x -= step[d].x;
            y -= step[d].y;
        }
    }
}

void horseRun(int xstart,int ystart) {
    //��ʼ������
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;
//    int midx = M / 2 -1;
//    int midy = N / 2 -1;
//    board[midx][midy] = 1; //�����̵��м��λ�ÿ�ʼ������
//    BackTrace(1, midx, midy,xstart,ystart);
	  int number=1;
	  board[xstart][ystart]=number;
	  runTable(xstart,ystart,number);
}

int main() {
    //��������ʼλ��
    int x, y;
    //cout<<"���������̴�Сm*n Ҫ��|m-n|<=2 �� m��n��Ϊż�� �� m,n < 20 :";
    cin>>N;
    M=N;
    //cout<<"��������������ʼλ��--��������0 <= x < "<<M<<"��0 <= y < "<<N<<" :";
    cin>>x>>y;
    horseRun(x,y); //ִ��������
    return 0;
}

