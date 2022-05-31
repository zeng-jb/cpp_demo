#include <iostream>
using namespace std;

class Complex
{
public:
	Complex() {
		real = 0; image = 0;
	}
	Complex(int r, int i)
	{
		real = r;
		image = i;
		
	}

	void display() {
		cout << real<< "+" << image << "i"<<endl;
	}
	operator +
private:
	int real;
	int image;
};
int()
{

	Complex c1(2, 3);
	Complex c2(-1, 4);

	c1.dispaly();
	c2.dispaly();
	return 0;
}