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
#define INF 0xffffff		//��������ַ

using namespace std;

char str[200][200];		//��ά����д���ַ���ÿһ���ַ���ֵ
int num[200];			//��������ֵ

int main()
{
	int m, n;
	memset(num, 0, sizeof(num));
	cin >> n;
	cin >> m;

	num[0] = INF;		//��ʼ��num[0]Ϊ����ַ�����������ѡ����������ַ�������
	for (int i = 1; i <= m; i++)
	{
		cin >> str[i];

		//���������
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

	//ѡ�����򷨣�����ַ�������
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
		num[p] = INF;		//����ǰnum[p]��Ϊ����ַ��������һ��ѭ���ıȽ�

	}

	system("pause");
	return 0;

}