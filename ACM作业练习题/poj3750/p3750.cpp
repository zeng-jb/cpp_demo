/*
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n, w, s;
	char c = ',';
	cin >> n;
	char name[64][15];
	for (int i = 0; i < n; i++) {
		cin >> name[i];
	}
	cin >> w >> c >> s;

	int count = 0;
	int point[64] = { 0 };
	int i=w-1;
		int index = 0;
	
	
		while(index<n) {
			
			while (point[i] == 1) {
				if (i == n) i = 0;
				else i = i + 1;
			}
			count++;
			if(count == s) {
				
				
				cout << name[i] << endl;
				point[i] = 1;
				count = 0;
				index++;
					
			}
			
			
		}
		cout << endl;
		return 0;
}*/


#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

const int N = 64;
const int N2 = 15;
char name[N][N2 + 1];

int main()
{
	int n, w, s, pos;

	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++)
			scanf("%s", name[i]);

		scanf("%d,%d", &w, &s);

		pos = w - 2;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < s; j++) {    // 走s步
				pos++;              // 一步一步走
				if (pos >= n)
					pos %= n;       // 循环
				if (name[pos][0] == '\0')
					j--;
			}
			printf("%s\n", name[pos]);  // 走s步后输出人名

			name[pos][0] = '\0';           // 标记输出
		}
	}

	return 0;
}