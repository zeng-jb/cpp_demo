//#include <iostream>
//using namespace std;
//long Fibonacci(long n){
//	if(n==1||n==2) return 1;
//	else if(n<=0) return 0;
//	else return Fibonacci(n-1)+Fibonacci(n-2);
//}
//int main(){
//	cout<<"输入数列的n项"<<endl;
//	long n;
//	cin>>n;
//	cout<<Fibonacci(n)<<endl;
//	return 0;
//}

#include <iostream>
using namespace std;
int f(int n){
	int f1=1,f2=1,fn=0;
	if(n==1||n==2) return 1;
	else{
		for(int i=3;i<=n;i++){
			fn=(f1+f2)%998244353;
			f2=f1;
			f1=fn;
		}
	}
	return fn;
}
int main(){
	int n;
	cin>>n;
	cout<<f(n)<<endl;
	return 0;
}
