#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
 
int main()
{
	int N;
	char s1[100][10],s2[100][10];
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>s1[i]>>s2[i];
//		cout<<s1[i]<<endl<<s2[i]<<endl;
	}
/*		if(s1[i]=="Rock"){
			if(s2[i]=="Rock") cout<<"Tie"<<endl;
			if(s2[i]=="Scissors") cout<<"Player1"<<endl;
			if(s2[i]=="Paper") cout<<"Player2"<<endl;
		}
		if(s1[i]=="Scissors"){
			if(s2[i]=="Scissors") cout<<"Tie"<<endl;
			if(s2[i]=="Paper") cout<<"Player1"<<endl;
			if(s2[i]=="Rock") cout<<"Player2"<<endl;
		}
		if(s1[i]=="Scissors"){
			if(s2[i]=="Paper") cout<<"Tie"<<endl;
			if(s2[i]=="Rock") cout<<"Player1"<<endl;
			if(s2[i]=="Scissors") cout<<"Player2"<<endl;		
		}
	
*/
for (int i=0;i<N;i++)
	{
		int l1=strlen(s1[i]);
		int l2=strlen(s2[i]);
		if (l1==l2)
		    cout<<"Tie"<<endl;
		else
		{
			if (l1==4)
			{
				if (l2==5)
				  cout<<"Player2"<<endl;
				else
				  cout<<"Player1"<<endl;
			}
			else if(l1==5)
			{
				if (l2==4)
				  cout<<"Player1"<<endl;
				else
				   cout<<"Player2"<<endl;
			}
			else
			{
				if (l2==4)
				  cout<<"Player2"<<endl;
				else
				  cout<<"Player1"<<endl;
			} 
	    }
	}

    
    return 0;
}

 /*
int a[10];
char s1[100],s2[100];
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%s",s1);
        scanf("%s",s2);
        if(s1[0]==s2[0])         //首先判断两者出的是否一样
            a[i]=0;
        if (s1[0]=='R')          //R代表石头
          {
              if(s2[0]=='S') a[i]=1;
              if(s2[0]=='P') a[i]=2;
          }
          if (s1[0]=='P')        //P代表布
          {
              if(s2[0]=='R') a[i]=1;
              if(s2[0]=='S') a[i]=2;
          }
          if (s1[0]=='S')       //S代表剪刀
          {
              if(s2[0]=='R') a[i]=2;
              if(s2[0]=='P') a[i]=1;
          }
          if(a[i]==1) printf("Player1\n");
          if(a[i]==2) printf("Player2\n");
          if(a[i]==0) printf("Tie\n");
    }
 
    return 0;
}*/
