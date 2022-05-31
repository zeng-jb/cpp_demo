/*#include<stdio.h>
int main(){
	int n,m,max=0,map[101][101]={0},s[101][101]={0};
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&m);
		if(m>max) max=m;
		for(int j=0;j<m*10;j++){
			map[i][j]=1;        //初始化 
		}
	}
	int flag=-1;  //flag用于记录是否是同一所学校 
	int sum=1; 	  //sum表示当前座位号 
	for(int i=0;i<max*10;i++){
		for(int j=0;j<n;j++){
			if(map[j][i]){
				if(flag!=j){
					s[j][i]=sum++;
					flag=j;
				}
				else{
					sum+=1;
					s[j][i]=sum++;
					flag=j;
				} 
			}
		} 
	}
	//输出
	for(int i=0;i<n;i++){
		printf("#%d\n",i+1);
		for(int j=0;j<max*10;j++)
			if(s[i][j]){
				printf("%d%c",s[i][j],(j+1)%10?' ':'\n');
			}
	}
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
int num[111];//记录每个学校的队伍数量
int pos[111][11][11];//i学校j队伍中k队员的位置
int maxx,pre;//maxx记录学校中队伍数量的最大值，pre记录上一个被编号的学校
int x;//记录编号
int main()
{
    int n;//学校数量
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>num[i];//每个学校的队伍数量
        maxx=max(maxx,num[i]);//记录最大队伍数量
    }
    for(int j=1; j<=maxx; j++) //以最大队伍数量为上界，为了让每个人都能在这个循环里添加上位置
    {
        for(int k=1; k<=10; k++)//循环每个队员
        {
            for(int i=1; i<=n; i++)//遍历学校开始编号
            {
                if(j<=num[i])//如果当前的队伍数量j小于等于当前学校的队伍数量，说明可以编号，否则不可以，因为该学校里没有队员可以被编号了，都编完号了
                {
                    if(pre==i)//相邻学校的两个队员必须隔位就坐
                        x+=2;
                    else
                        x++;//不是同一个学校的，连续编排
                    pos[i][j][k]=x;//特别有意思的循环，i学校j队伍中k队员的编号就是x
                    pre=i;//记录上一个被编号的学校
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<"#"<<i<<endl;
        for(int j=1;j<=num[i];j++)
        {
            for(int k=1;k<=10;k++)
            {
                if(k<=9)
                    cout<<pos[i][j][k]<<" ";
                else
                    cout<<pos[i][j][k]<<endl;
            }
        }
 
    }
    return 0;
}
