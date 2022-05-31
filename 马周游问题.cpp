
/*
#include<iostream>
#include <stdlib.h>
#include <iomanip>
 
using namespace std;
 
//马周游的棋盘，注意使用的时候是从下表为1开始
int board[100][100];
 
int fx[]= {2,1,-1,-2,-2,-1,1,2};
int fy[]= {-1,-2,-2,-1,1,2,2,1};
 
int n; //棋盘大小
 
//参数x,y 表示棋盘的位置
//检测(x,y) 对应位置在棋盘中是否合法
bool check(int x,int y)
{
    if(x<1 || y<1 || x>n || y>n || board[x][y] != 0)
        return false;
    return true;
}
 
//输出结果
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
    if(number == n*n) //已经走完棋盘中所有的点
    {
        outputResult(n); //输出
        exit(1);
    }
 
    for(int i=0; i<8; i++) //表示每一个格都有八种走法
    {
        if(check(a + fx[i],b + fy[i]))
        {
            int x = a + fx[i];
            int y = b + fy[i];
 
            board[x][y] = number+1; //走到下一个位置，设置其序号为 number+1
 
            runTable(x, y,number+1);
            board[x][y] = 0;//回溯
        }
    }
}
 
//递归走法
void horseRun(int x,int y)
{
    int number = 1;
    board[x][y] = number; //首先确定起始位置这个格是序号为1
    runTable(x, y,number);
}
 
int main()
{
    //cout<<"输入棋盘大小n:";
    cin>>n;
 
    int x,y;
    //cout<<"输入马周游起始位置x(1~n),y(1~n):";
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
    int nextPosSteps; //表示下一位置有多少种走法；走法少的优先考虑
    int nextPosDirection; //下一位置相对于当前位置的方位
    int nextPosToMidLength; //表示当前位置距中间点距离；距离中间点远的优先考虑
    bool operator < (const NextPos &a) const {
        return nextPosSteps > a.nextPosSteps && nextPosToMidLength < a.nextPosToMidLength;
    }
    
};

int board[1000][1000];
int M,N; //棋盘大小
//检测这个位置是否可以走
bool check(int x, int y) {
    if (x >= 0 && x < M && y >= 0 && y < N && board[x][y] == 0)
        return true;
    return false;
}
//下一位置有多少种走法
int nextPosHasSteps(int x, int y) {
    int steps = 0;
    for (int i = 0; i < 8; ++i) {
        if (check(x + step[i].x, y + step[i].y))
            steps++;
    }
    return steps;
}
//判断是否回到起点
bool returnStart(int x, int y) {
    //校验最后是否可以回到起点，也就是棋盘的中间位置
    int midx,midy;
    midx = M / 2 - 1;
    midy = N / 2 - 1;
    for (int i = 0; i < 8; ++i)
        if (x + step[i].x == midx && y + step[i].y == midy)
            return true;
    return false;
}

//输出结果
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

//某一位置距离棋盘中心的距离
int posToMidLength(int x,int y) {
    int midx = M / 2 - 1;
    int midy = N / 2 - 1;
    return (abs(x - midx) + abs(y - midy));
}
 
void runTable(int a,int b,int number)
{
    if(number == n*n) //已经走完棋盘中所有的点
    {
        outputResult(n); //输出
        exit(1);
    }
 
    for(int i=0; i<8; i++) //表示每一个格都有八种走法
    {
        if(check(a + fx[i],b + fy[i]))
        {
            int x = a + fx[i];
            int y = b + fy[i];
 
            board[x][y] = number+1; //走到下一个位置，设置其序号为 number+1
 
            runTable(x, y,number+1);
            board[x][y] = 0;//回溯
        }
    }
}

void BackTrace(int t, int x, int y,int xstart,int ystart) {
    //找到结果
    if (t == M * N && returnStart(x,y)) {//遍历了棋盘的所以位置，并且最后可以回到起点，形成回路
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
            //回溯
            board[x][y] = 0;
            x -= step[d].x;
            y -= step[d].y;
        }
    }
}

void horseRun(int xstart,int ystart) {
    //初始化棋盘
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;
//    int midx = M / 2 -1;
//    int midy = N / 2 -1;
//    board[midx][midy] = 1; //从棋盘的中间的位置开始马周游
//    BackTrace(1, midx, midy,xstart,ystart);
	  int number=1;
	  board[xstart][ystart]=number;
	  runTable(xstart,ystart,number);
}

int main() {
    //马周游起始位置
    int x, y;
    //cout<<"请输入棋盘大小m*n 要求：|m-n|<=2 且 m和n都为偶数 且 m,n < 20 :";
    cin>>N;
    M=N;
    //cout<<"请输入马周游起始位置--横纵坐标0 <= x < "<<M<<"和0 <= y < "<<N<<" :";
    cin>>x>>y;
    horseRun(x,y); //执行马周游
    return 0;
}

