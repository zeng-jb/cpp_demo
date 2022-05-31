
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include<string>
#include<fstream> 
#define M 20 
using namespace std;
string keyword[9] = { "main","if","int","for","while","do","return","break","continue" };//�ؼ���=1
  //��ʶ��ֵ=2
  //����ֵ=3
char arithmetic[4] = { '+','-','*','/' }; //���������=4
char relation[6] = { '=','>','<','>=','<=','!=' };//��ϵ�����=4
char border[6] = { ';',',','{','}','(',')' };    //�ָ���=5

/**�ж��Ƿ�Ϊ�ؼ���**/
bool IsKeyword(string word) {
	for (int i = 0; i<9; i++) {
		if (keyword[i] == word) {
			return true;
		}
	}
	return false;
}
/**�ж��Ƿ�Ϊ���������**/
bool IsArithmetic(char ch) {
	for (int i = 0; i<4; i++) {
		if (arithmetic[i] == ch) {
			return true;
		}
	}
	return false;
}
/**�ж��Ƿ�Ϊ��ϵ�����**/
bool IsRelation(char ch) {
	for (int i = 0; i<6; i++) {
		if (relation[i] == ch) {
			return true;
		}
	}
	return false;
}
/**�ж��Ƿ�Ϊ�ָ���**/
bool IsBorder(char ch) {
	for (int i = 0; i<6; i++) {
		if (border[i] == ch) {
			return true;
		}
	}
	return false;
}


/**�ж��Ƿ�Ϊ��ĸ**/
bool IsLetter(char ch) {
	if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') return true;
	return false;
}
/**�ж��Ƿ�Ϊ����**/
bool IsDigit(char ch) {
	if (ch >= '0' && ch <= '9') return true;
	return false;
}
// ����
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
	cout  << digit << "  ����" << endl;
	return(ch);
}
// ��ʶ�����ؼ���
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
		cout << alpha << "  �ؼ���" << endl;
	else
		cout << alpha << "  ��ʶ��" << endl;

	return(ch);
}
// ����� �����
char OtherProcess(char ch, FILE* fp)
{
	int i = -1;
	char othertp[M];
	othertp[0] = ch;
	othertp[1] = '\0';
	if (IsArithmetic(ch))//���������
	{
		cout << othertp << "  �����" << endl;
		ch = fgetc(fp);
	}
	if (IsRelation(ch))//��ϵ�����
	{
		ch = fgetc(fp);
		othertp[1] = ch;
		othertp[2] = '\0';
		if (IsRelation(ch))
			cout << othertp << "  �����" << endl;
		else
		{
			othertp[1] = '\0';
			cout  << othertp  << "  �����" << endl;
		}
	}
	if (IsBorder(ch))//�ֽ��
	{
		cout  << othertp <<  "  �ָ���" << endl;
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
	
	if (!fp) // �ж�Դ�ļ��Ƿ����
	    cout<<" �ļ������� "<<endl;
	else
	{
		ch = fgetc(fp); // �����ַ�
		while (ch != EOF) // ����ļ�û�н��� ,��һֱѭ��
		{
			if (IsLetter(ch)) // �������ĸ
				ch = AlphaProcess(ch, fp);
			else if (IsDigit(ch)) // ����
				ch = DigitProcess(ch, fp);
			else
				ch = OtherProcess(ch, fp);
		}
		cout << "end" << endl;
		getchar();
	}
	return 0;
}


