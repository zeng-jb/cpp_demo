#include<bits/stdc++.h>
using namespace std;
//enum DAY{
//    A=1,B,C,D,E,F,G
//};
//enum Hour{
// 0=1,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F,G,H,I,J,K,L,M,N
//};

int main(){
    string str1,str2,str3,str4;
    cin>>str1>>str2>>str3>>str4;
    int i=0,j=1;
    //DAY day;Hour H;
    while(1){
        if(j==1){
            if(str1[i]==str2[i]&&str1[i]>='A'&&str1[i]<='Z'){
                    switch(str1[i]){
                        case 'A':cout<<"MON ";break;
                        case 'B':cout<<"TUE ";break;
                        case 'C':cout<<"WED ";break;
                        case 'D':cout<<"THU ";break;
                        case 'E':cout<<"FRI ";break;
                        case 'F':cout<<"SAT ";break;
                        case 'G':cout<<"SUN ";break;
                    }
                    j=2;
                }
            
        }else if(j==2&&str1[i]==str2[i]&&((str1[i]>='0'&&str1[i]<='9')||(str1[i]>='A'&&str1[i]<='N'))){
                   switch(str1[i]){
                       case 0:cout<<"00:";break;    
                       case 1:cout<<"01:";break;
                       case 2:cout<<"02:";break;
                       case 3:cout<<"03:";break;
                       case 4:cout<<"04:";break;
                       case 5:cout<<"05:";break;
                       case 6:cout<<"06:";break;
                       case 7:cout<<"07:";break;
                       case 8:cout<<"08:";break;
                       case 9:cout<<"09:";break;
                       case 'A':cout<<"10:";break;   
                       case 'B':cout<<"11:";break;
                       case 'C':cout<<"12:";break; 
                       case 'D':cout<<"13:";break;
                       case 'E':cout<<"14:";break;
                       case 'F':cout<<"15:";break;
                       case 'G':cout<<"16:";break;
                       case 'H':cout<<"17:";break;
                       case 'I':cout<<"18:";break;
                       case 'J':cout<<"19:";break; 
                       case 'K':cout<<"20:";break; 
                       case 'L':cout<<"21:";break; 
                       case 'M':cout<<"22:";break; 
                       case 'N':cout<<"23:";break;     
                   }
            break;
        }
    i++;
    }
    int z=0;
    while(1){
        if(str3[z]==str4[z]&&((str3[z]>='a'&&str3[z]<='z')||(str3[z]>='A'&&str3[z]<='Z'))){printf("%02d\n",z);break;}
        z++;
    }
    return 0;
}
