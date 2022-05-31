/*#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
#define N 10
string s[N];
bool vis[N][N];
int n, ans;

bool check(int x, int y) {
	for (int i = x - 1; i >= 0; i--) {
		if (vis[i][x]) return 0;
		if (s[i][y] == 'X') break;
	}
	for (int i = y - 1; i >= 0; i--) {
		if (vis[x][i]) return 0;
		if (s[x][i] == 'X') break;
	}
	return true;
}

void dfs(int pos, int k) {
	if (pos == n * n) {
		ans = max(ans, k);
		return;
	}

	int x = pos / n;
	int y = pos % n;
	if (s[x][y] == '.' && check(x, y)) {                 //判断是否符合条件
		vis[x][y] = true;
		dfs(pos + 1, k + 1);
		vis[x][y] = 0;
	}
	dfs(pos + 1, k);
}

int main()
{
	//	freopen("ccf.txt","r",stdin);
	while (cin >> n && n) {
		memset(vis, 0, sizeof(vis));
		cin.ignore();
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		ans = 0;
		dfs(0, 0);
		cout << ans << endl;
	}
	return 0;
}

*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#define MAXN 10
using namespace std;
char map[MAXN][MAXN];
int hang[MAXN][MAXN];
int lie[MAXN][MAXN];
int G[110][110];
int pipei[MAXN];
bool used[MAXN];
int N, M;
void init()
{
    memset(G, 0, sizeof(G));

}
void getMap()
{
    for (int i = 0; i < N; i++)
    {
       // scanf("%s", map[i]);
        cin >> map[i];
    }
}
int find(int x, int n)
{
    for (int i = 0; i < n; i++)
    {
        int y = G[x][i];
        if (y && !used[i])
        {
            used[i] = true;
            if (pipei[i] == -1 || find(pipei[i], n))
            {
                pipei[i] = x;
                return 1;
            }
        }
    }
    return 0;
}
void solve()
{
    int ans = 0;
    int an = 0;
    for (int i = 0; i < N; i++, an++)
    {

        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 'X' && j + 1 < N && map[i][j + 1] != 'X')an++;
            hang[i][j] = an;
        }

    }
    int ann = 0;
    for (int j = 0; j < N; j++, ann++)
    {

        for (int i = 0; i < N; i++)
        {
            if (map[i][j] == 'X' && i + 1 < N && map[i + 1][j] != 'X')ann++;
            lie[i][j] = ann;
        }

    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] != 'X')G[hang[i][j]][lie[i][j]] = 1;
        }
    }
    memset(pipei, -1, sizeof(pipei));
    for (int i = 0; i < an; i++)
    {
        memset(used, false, sizeof(used));
        ans += find(i, ann);
    }
    printf("%d\n", ans);
}
int main()
{
    while ((cin>>N) && N)
    {
        init();
        getMap();
        solve();
    }
    return 0;
}