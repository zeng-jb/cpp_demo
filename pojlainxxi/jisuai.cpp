#include <iostream>
using namespace std;
int main()
{
	char ch[256];
	int count = 0;
	int i = 0;
	gets_s(ch);
	//cout << ch;
	while (ch[i] != '\0')
	{
		if (ch[i] - '0' >= 0 && ch[i] - '0'  <=9)
			count++;
		i++;
	};
	cout << count << endl;
	return 0;
}