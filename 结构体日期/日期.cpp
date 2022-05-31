#include <iostream>
using namespace std;
struct date
{
	int year;
	int month;
	int day;
};
void print(date &d){
	int i,  sum = 0;
	int m[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int y = d.year;
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
		m[1] = 29;
	}
	for (i = 0; i < d.month - 1; i++) {
		sum += m[i];
	}
	sum += d.day;

	cout << sum << endl;
}
int main()
{
	date d;
	cout << "ÇëÊäÈëÈÕÆÚ" << endl;
	cin >> d.year >> d.month >> d.day;
	print(d);
	system("pause");
	return 0;
}