#include <iostream>
#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
#define MAX  10

int d[8][2] = { 2,1,2,-1,-2,1,-2,-1,1,2,1,-2,-1,2,-1,-2 };
struct Node
{
    int x, y;
    int time;
    /*friend bool operator <(Person a ,Person b)
    {
        return a.time>b.time;
    }*/
};

int vis[MAX][MAX];

bool inMap(int x, int y) {
    if (x < 0 || x >= 8 || y < 0 || y >= 8)
    {
        return false;
    }
    return true;

}


int BFS(int startX, int startY, int targetX, int targetY) {
    memset(vis, 0, sizeof(vis));
    Node s;
    s.x = startX;
    s.y = startY;
    s.time = 0;
    vis[startX][startY] = 1;
    queue<Node> q;
    q.push(s);
    Node now, next;
    while (!q.empty())
    {
        now = q.front();
        q.pop();

        if (now.x == targetX && now.y == targetY)
        {
            return now.time;
        }


        for (int i = 0; i < 8; i++)
        {
            next.x = now.x + d[i][0];
            next.y = now.y + d[i][1];

            if (inMap(next.x, next.y) && vis[next.x][next.y] == 0)
            {
                next.time = now.time + 1;
                vis[next.x][next.y] = 1;
                q.push(next);
            }
        }
    }


}


int main() {
    string from, to;
    while (cin >> from >> to)
    {
        int startX, startY;
        int targetX, targetY;
        startX = from[0] - 'a';
        startY = from[1] - '1';
        targetX = to[0] - 'a';
        targetY = to[1] - '1';
        //  cout <<" " <<startX <<" " << startY<< " " << targetX<<" " << targetY<< endl;
        cout << "To get from " << from << " to " << to << " takes " << BFS(startX, startY, targetX, targetY) << " knight moves." << endl;
    }
}
