#include <iostream>
using namespace std;
struct Color
{
	int r, g, b;
}rgb[16];
int main()
{
	for (int i = 0; i < 16; i++) {
		cin >> rgb[i].r >> rgb[i].g >> rgb[i].b;
	}
	int R, G, B;
	int min;
	while (1) {
		cin >> R >> G >> B;
		if (R == -1 && G == -1 && B == -1) return 0;
		min= (R - rgb[0].r) * (R - rgb[0].r) + (G - rgb[0].g) * (G - rgb[0].g) + (B - rgb[0].b) * (B - rgb[0].b);
		int D,j=0;
		for (int i = 1; i < 16; i++) {
			D = (R - rgb[i].r) * (R - rgb[i].r) + (G - rgb[i].g) * (G - rgb[i].g) + (B - rgb[i].b) * (B - rgb[i].b);
			if (min > D) {
				min = D; j = i;
			}
		}
		cout << "(" << R << "," << G << "," << B << ")";
		cout << " maps to ";
		cout << "(" << rgb[j].r << "," << rgb[j].g << "," << rgb[j].b  << ")";
		cout << endl;
	}
}