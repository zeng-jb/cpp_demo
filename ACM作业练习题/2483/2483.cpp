			
#include<iostream> 
#include  <stdio.h>
#include<vector>
#include <string>  //getline
#include <istream>
using namespace std;
vector<char>arr;//arr�����洢ȥ���ո�ı��ʽ 
char expression_value();
char term_value();
char factor_value();
int mark; //mark����ָʾ��ǰ�ַ�
char expression_value()//������ʽ 
{
char result = term_value();//�Ȼ�õ�һ���� 
while (true)         //ѭ���������е�'|'���� 
{
	if (arr[mark] == '|')//��'|'���ʹ������˾�����ѭ�� 
	{
		mark++;       //�ǵĻ�ȡ��'|'��  
		char value = term_value();//��ȡ'|'����һ�� 
		if (result != 'V')//�������ϵ֪���resultΪ��ֱ�ӷ����棬��Ϊ�ٷ���'|'����һ���ֵ 
		{
			result = value;
		}
	}
	else
		break;
}
return result;
}
char term_value()//������ 
{
	char result = factor_value();//��õ�һ������ 
	while (true)//ѭ���������е�'&'���� 
	{
		if (arr[mark] == '&')//��'&'���ʹ������˾�����ѭ��
			{
			mark++;    //�ǵĻ�ȡ��'&'�� 
			char value = factor_value();//��ȡ'&'����һ������ 	
			if (result != 'F')//�������ϵ֪���resultΪ��ֱ�ӷ��ؼ٣���Ϊ�淵��'&'����һ���ֵ
			{
				result = value;
			}
		}
		else
		break;
	}
	return result;
}
char factor_value()//��������
{/*�������������һ���ǵ������ַ����٣�
   ��һ�������ű��ʽͬʱ����ǰ����������ɸ�'!'*/
	char result;
	int counts = 0;//����һ��counts���洢'!'�ĸ��� 
	while (arr[mark] == '!')
	{
		counts++;
		mark++;
	}
	if (arr[mark] == '(')//�����鵽���ӵ�һ�ַ���'('˵������һ�����ʽ 
	{
		mark++;//����'('
		result = expression_value();//��result��ȡ����ı��ʽ��ֵ�ݹ��ȥ 
		mark++;//����')'
	}
	else       //������ǵĻ�˵�����ǵ����ַ�ֱ�ӻ�ȡ 
	{
		result = arr[mark];
		mark++;
	}
	if (counts % 2)//����ж�'!'���������������������Ҫ�ı�ǰ���õ�resultֵ 
	{
		if (result == 'V')
			result = 'F';
		else
			result = 'V';
	}
	return result;
}
int main()
{
	string a;
	int t = 0;
	while (getline (cin, a))//��������
	{
		t++;			//��¼�ڼ������� 
		mark = 0;			//mark��ֵ��Ϊ0 
		arr.resize(0);  //������ֵ��С����Ϊ0 
		for (int i = 0; i < a.size(); i++)//����һ������Ŀո񣬷ǿո�ѹ������ 
		{
			if (a[i] != ' ')
				arr.push_back(a[i]);
		}
		printf("Expression %d: %c\n", t, expression_value());//������ 
	}
	return 0;
}