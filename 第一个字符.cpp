#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
 
char str1[100001];
char str2[100001];
 
int main()
{
    gets(str1);
    strcpy(str2,str1);    
    int flag = 0;
    for(int i = 0;i<strlen(str1);i++)
    {
        int sum = 0;
        for(int j = 0;j<strlen(str2);j++)
        {
            if(str1[i]!=str2[j])
            sum++;
        }
        if(sum == (strlen(str2)-1))
        {
            cout<<str1[i]<<endl;
            break;
        }
        else 
        {
            flag++;
            if(flag == strlen(str2))
            {
                cout<<"no"<<endl;
                break;
            }
        }
    }
    return 0;
}
