
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include<string>
#include<fstream> 
#define M 20 
using namespace std;
string keyword[9] = { "main","if","int","for","while","do","return","break","continue" };//关键字=1
  //标识符值=2
  //常数值=3
char arithmetic[4] = { '+','-','*','/' }; //算术运算符=4
char relation[6] = { '=','>','<','>=','<=','!=' };//关系运算符=4
char border[6] = { ';',',','{','}','(',')' };    //分隔符=5

/**判断是否为关键字**/
bool IsKeyword(string word) {
	for (int i = 0; i<9; i++) {
		if (keyword[i] == word) {
			return true;
		}
	}
	return false;
}
/**判断是否为算术运算符**/
bool IsArithmetic(char ch) {
	for (int i = 0; i<4; i++) {
		if (arithmetic[i] == ch) {
			return true;
		}
	}
	return false;
}
/**判断是否为关系运算符**/
bool IsRelation(char ch) {
	for (int i = 0; i<6; i++) {
		if (relation[i] == ch) {
			return true;
		}
	}
	return false;
}
/**判断是否为分隔符**/
bool IsBorder(char ch) {
	for (int i = 0; i<6; i++) {
		if (border[i] == ch) {
			return true;
		}
	}
	return false;
}


/**判断是否为字母**/
bool IsLetter(char ch) {
	if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') return true;
	return false;
}
/**判断是否为数字**/
bool IsDigit(char ch) {
	if (ch >= '0' && ch <= '9') return true;
	return false;
}
// 常数
char DigitProcess(char ch, FILE* fp)
{
	int i = -1;
	char digit[M];
	while ((IsDigit(ch)))
	{
		digit[++i] = ch;
		ch = fgetc(fp);
	}
	digit[i + 1] = '\0';
	cout  << digit << "  常数" << endl;
	return(ch);
}
// 标识符、关键字
char AlphaProcess(char ch, FILE* fp)
{
	int i = -1;
	char alpha[M];
	while (IsLetter(ch) || (IsDigit(ch)))
	{
		alpha[++i] = ch;
		ch = fgetc(fp);
	}
	alpha[i + 1] = '\0';
	if(IsKeyword(alpha))
		cout << alpha << "  关键字" << endl;
	else
		cout << alpha << "  标识符" << endl;

	return(ch);
}
// 运算符 、界符
char OtherProcess(char ch, FILE* fp)
{
	int i = -1;
	char othertp[M];
	othertp[0] = ch;
	othertp[1] = '\0';
	if (IsArithmetic(ch))//算术运算符
	{
		cout << othertp << "  运算符" << endl;
		ch = fgetc(fp);
	}
	if (IsRelation(ch))//关系运算符
	{
		ch = fgetc(fp);
		othertp[1] = ch;
		othertp[2] = '\0';
		if (IsRelation(ch))
			cout << othertp << "  运算符" << endl;
		else
		{
			othertp[1] = '\0';
			cout  << othertp  << "  运算符" << endl;
		}
	}
	if (IsBorder(ch))//分界符
	{
		cout  << othertp <<  "  分隔符" << endl;
		ch = fgetc(fp);
	}
	ch = fgetc(fp);
	return(ch);
}
int main()
{
	char ch;
	FILE * fp;
	fp=fopen("E:\\test.txt","r");
	
	if (!fp) // 判断源文件是否存在
	    cout<<" 文件不存在 "<<endl;
	else
	{
		ch = fgetc(fp); // 读入字符
		while (ch != EOF) // 如果文件没有结束 ,就一直循环
		{
			if (IsLetter(ch)) // 如果是字母
				ch = AlphaProcess(ch, fp);
			else if (IsDigit(ch)) // 数字
				ch = DigitProcess(ch, fp);
			else
				ch = OtherProcess(ch, fp);
		}
		cout << "end" << endl;
		getchar();
	}
	return 0;
}


