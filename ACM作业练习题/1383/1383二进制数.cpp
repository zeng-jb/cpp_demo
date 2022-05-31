#include <iostream>
using namespace std;
void output(int n);
int main()
{
	int d, n;
	cin >> d;
	for (int i = 1; i <= d; i++) {
		cin >> n;
		output(n);
		cout << endl;
	}
	return 0;
}
void output(int n)
{
	int a[100] = { 0 };
	int digit = 0, index = 1;
	while (n > 0) {
		a[digit++] = n % 2;
		n /= 2;
	}

	for (int i = 0; i <= digit; i++) {
		
		if (a[i] == 1) {
			if (index != 1) cout << " ";
			cout << i;
			index = 0;
		}
	}
}