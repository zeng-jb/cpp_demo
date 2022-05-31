			
#include<iostream> 
#include  <stdio.h>
#include<vector>
#include <string>  //getline
#include <istream>
using namespace std;
vector<char>arr;//arr用来存储去掉空格的表达式 
char expression_value();
char term_value();
char factor_value();
int mark; //mark用来指示当前字符
char expression_value()//处理表达式 
{
char result = term_value();//先获得第一个项 
while (true)         //循环处理所有的'|'符号 
{
	if (arr[mark] == '|')//是'|'符就处理不是了就跳出循环 
	{
		mark++;       //是的话取下'|'符  
		char value = term_value();//获取'|'的下一项 
		if (result != 'V')//由运算关系知如果result为真直接返回真，若为假返回'|'符后一项的值 
		{
			result = value;
		}
	}
	else
		break;
}
return result;
}
char term_value()//处理项 
{
	char result = factor_value();//获得第一个因子 
	while (true)//循环处理所有的'&'符号 
	{
		if (arr[mark] == '&')//是'&'符就处理不是了就跳出循环
			{
			mark++;    //是的话取下'&'符 
			char value = factor_value();//获取'&'的下一个因子 	
			if (result != 'F')//由运算关系知如果result为假直接返回假，若为真返回'&'符后一项的值
			{
				result = value;
			}
		}
		else
		break;
	}
	return result;
}
char factor_value()//处理因子
{/*因子有两种情况一种是单个的字符真或假，
   另一种是括号表达式同时因子前面可能有若干个'!'*/
	char result;
	int counts = 0;//先用一个counts来存储'!'的个数 
	while (arr[mark] == '!')
	{
		counts++;
		mark++;
	}
	if (arr[mark] == '(')//如果检查到因子第一字符是'('说明它是一个表达式 
	{
		mark++;//拿下'('
		result = expression_value();//用result获取里面的表达式的值递归回去 
		mark++;//拿下')'
	}
	else       //如果不是的话说明它是单个字符直接获取 
	{
		result = arr[mark];
		mark++;
	}
	if (counts % 2)//最后判断'!'符的数量如果是奇数则需要改变前面获得的result值 
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
	while (getline (cin, a))//多组输入
	{
		t++;			//记录第几组输入 
		mark = 0;			//mark初值赋为0 
		arr.resize(0);  //容器初值大小设置为0 
		for (int i = 0; i < a.size(); i++)//处理一下输入的空格，非空格压入容器 
		{
			if (a[i] != ' ')
				arr.push_back(a[i]);
		}
		printf("Expression %d: %c\n", t, expression_value());//输出结果 
	}
	return 0;
}