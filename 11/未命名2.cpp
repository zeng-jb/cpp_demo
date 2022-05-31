#include <iostream>
using namespace std;

class A{
	private:
		int i;
	public:
		A(int a): i(a),j(a),k(1000){
			i=a;
		}
		A(){
			cout<<"A默认构造函数";
		}
		~A(){
			cout<<"A默认析构造函数";
		}
	void setI();
};
int main()
{
/*	Car A;
	A.setData();
	A. showData();
	
	A.addoil;
	A.driving();
	
	struct 
	private
	public
	
	//构造函数 
	
	Car B;
	B. */
	
	
	A a(10);
	
	int i(1);
	cout<<i<<endl;
	float b(2.14);
	cout<<b<<endl; 
	
	int *p=new int (10);
	delete p;
	a *p=new A;
	q->print();
	
	A *q=new A;
	A *q=&a;
	const int a;
 } 
