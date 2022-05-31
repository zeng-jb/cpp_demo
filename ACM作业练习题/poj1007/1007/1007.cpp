/*#include <iostream>
using namespace std;

int	input(int n, int m)
{
	char DNA[m][n];
	int i, j, z;
	for ( i = 0; i < m; i++) {
		for ( j = 0; j < n; j++) {
			getchar(DNA[i][j]);
		}
	}
	int a[m] = { 0 };
	for (i = 0; i < m; i++) {
		z = 0;
		for (j = z; j < n; j++) {
			if ((int)DNA[i][z] > (int)DNA[i][j]) a[i]++;
			if (j == n) z++;
			if (z == n) break;
		}
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	input(n, m);
	
}
*/

#include <iostream>
#define INF 0xffffff		//定义最大地址

using namespace std;

char str[200][200];		//二维数组写入字符串每一个字符的值
int num[200];			//逆序数的值

int main()
{
	int m, n;
	memset(num, 0, sizeof(num));
	cin >> n;
	cin >> m;

	num[0] = INF;		//初始化num[0]为最大地址，方便后来的选择排序法输出字符串数组
	for (int i = 1; i <= m; i++)
	{
		cin >> str[i];

		//求出逆序数
		for (int j = 0; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (str[i][j] > str[i][k])
				{
					num[i]++;
				}
			}
		}

	}

	int p = 0;

	//选择排序法，输出字符串数组
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (num[j] < num[p])
			{
				p = j;
			}
		}
		cout << str[p] << endl;
		num[p] = INF;		//将当前num[p]置为最大地址，方便下一个循环的比较

	}

	system("pause");
	return 0;

}