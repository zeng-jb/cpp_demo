/*#include<stdio.h>
int main(){
	int n,m,max=0,map[101][101]={0},s[101][101]={0};
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&m);
		if(m>max) max=m;
		for(int j=0;j<m*10;j++){
			map[i][j]=1;        //��ʼ�� 
		}
	}
	int flag=-1;  //flag���ڼ�¼�Ƿ���ͬһ��ѧУ 
	int sum=1; 	  //sum��ʾ��ǰ��λ�� 
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
	//���
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
int num[111];//��¼ÿ��ѧУ�Ķ�������
int pos[111][11][11];//iѧУj������k��Ա��λ��
int maxx,pre;//maxx��¼ѧУ�ж������������ֵ��pre��¼��һ������ŵ�ѧУ
int x;//��¼���
int main()
{
    int n;//ѧУ����
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>num[i];//ÿ��ѧУ�Ķ�������
        maxx=max(maxx,num[i]);//��¼����������
    }
    for(int j=1; j<=maxx; j++) //������������Ϊ�Ͻ磬Ϊ����ÿ���˶��������ѭ���������λ��
    {
        for(int k=1; k<=10; k++)//ѭ��ÿ����Ա
        {
            for(int i=1; i<=n; i++)//����ѧУ��ʼ���
            {
                if(j<=num[i])//�����ǰ�Ķ�������jС�ڵ��ڵ�ǰѧУ�Ķ���������˵�����Ա�ţ����򲻿��ԣ���Ϊ��ѧУ��û�ж�Ա���Ա�����ˣ����������
                {
                    if(pre==i)//����ѧУ��������Ա�����λ����
                        x+=2;
                    else
                        x++;//����ͬһ��ѧУ�ģ���������
                    pos[i][j][k]=x;//�ر�����˼��ѭ����iѧУj������k��Ա�ı�ž���x
                    pre=i;//��¼��һ������ŵ�ѧУ
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
