#include <iostream>
using namespace std;
void Panlindrom(int num);
int main()
{
	int a[50], i = 0, j;
	cin >> a[i];
	while (a[i])
	{
		++i;
		cin >> a[i];
	}
	for (j = 0; j < i; j++) {
		Panlindrom(a[j]);
	}
	return 0;
}
void Panlindrom(int num)
{
	int number[50] = { 0 }, base, judge, base_num[17] = { 0 };
	int n,i,j,index=0;
	for (base = 2; base < 17; base++)
	{
		n = num;
		judge = 0;
		for (i = 0; n != 0; i++) {
			number[i] = n % base;
			n = n / base;
		}
		for (j = 0; j < i / 2; j++) {
			if (number[j] != number[i - j - 1]) {
				judge = 1;
				break;
			}
		}
		if (judge == 0) {
			base_num[base] = 1;
			index += 1;
		}
	}
	if (index == 0) {
		cout << "Number " << num << " is not a palindrom";
	}
	else {
		cout << "Number "<<num<<" is palindrom in basis";
		for (i = 0; i < 17; i++) {
			if (base_num[i] == 1) cout << " " << i;
		}
	}
	cout << endl;
}