//#include <iostream>
//using namespace std;
////产生排列 输入n 输出所有可能排列			字典序排列 
////PERMUTATIONS1
//int p[11], vis[11];
//void perml(int m,int n){
//	if(m==n){
//		for(int i=0;i<n;i++)
//			cout<<p[i];
//		cout<<endl;
//	}
//	else{
//		for(int i=1;i<=n;i++){
//			if(!vis[i]){
//				vis[i] = 1;
//				p[m] = i;
//				perml(m+1, n);
//				vis[i] = 0;
//			}
//		}
//	}
//} 
//
//int main(){
//	int n;
//	cin>>n;
//	perml(0,n);
//}



#include <iostream>  
#include <algorithm>  
using namespace std; 

int main()  
{  
	int n;
	cin>>n;
    int num[10];
    for(int i=0;i<n;i++){
    	num[i]=n-i;
	}
    do  
    {  
        for(int i=0;i<n;i++){
			cout<<num[i];
		}
		cout<<endl;
    }while(prev_permutation(num,num+n));  //生成排列的函数在 <algorithm>库 逆序生成 
    return 0;  
}  

//
//#include <iostream>  
//#include <algorithm>  
//using namespace std; 
//
//int main()  
//{  
//	int n;
//	cin>>n;
//    int num[10];
//    for(int i=0;i<n;i++){
//    	num[i]=i+1;
//	}
//    do  
//    {  
//        for(int i=0;i<n;i++){
//			cout<<num[i];
//		}
//		cout<<endl;
//    }while(next_permutation(num,num+n));  //生成排列的函数在 <algorithm>库 顺序生成 
//    return 0;  
//}  

