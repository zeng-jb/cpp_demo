#include <iostream>
#include <cstdio>
#include <cstring>
#include<queue>
using namespace std;
struct node {
    int x, y, t;
    friend bool operator<(node n1, node n2) {
        return n2.t < n1.t;
    }
};
int n, m;
char map[210][210];
int d[210][210];
int ax, ay, rx, ry;
node ft;
int mx[] = { 1,0,-1,0 };
int my[] = { 0,-1,0,1 };

int judge(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return 0;
    }
    if (map[x][y] == '#') {
        return 0;
    }
    if (d[x][y]) {
        return 0;
    }
    return 1;
}

void bfs() {
    priority_queue<node> q;
    ft.x = rx;
    ft.y = ry;
    ft.t = 0;
    q.push(ft);
    d[rx][ry] = 1;
    while (!q.empty()) {
        ft = q.top();
        q.pop();
        //printf("%d,%d,%d\n",ft.x,ft.y,ft.t);
        int x = ft.x;
        int y = ft.y;
        if (x == ax && y == ay) {
            printf("%d\n", ft.t);
            return;
        }
        for (int i = 0; i < 4; i++) {
            x = ft.x + mx[i];
            y = ft.y + my[i];
            if (!judge(x, y)) {
                continue;
            }
            node nt;
            if (map[x][y] == '.' || map[x][y] == 'a') {
                nt.x = x;
                nt.y = y;
                nt.t = ft.t + 1;
                d[x][y] = 1;
                q.push(nt);
            }
            else if (map[x][y] == 'x') {
                nt.x = x;
                nt.y = y;
                nt.t = ft.t + 2;
                d[x][y] = 1;
                q.push(nt);
            }
        }
    }
    printf("Poor ANGEL has to stay in the prison all his life.\n");
}


int main()
{
    while (cin>>n>>m) {
        memset(d, 0, sizeof(d));
        for (int i = 0; i < n; i++) {
            //scanf("%s", map[i]);
            cin >> map[i];
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 'a') {
                    ax = i, ay = j;
                }
                if (map[i][j] == 'r') {
                    rx = i, ry = j;
                }
            }
        }
        bfs();
    }
    return 0;
}