#pragma once

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// AnalyzeProgram
//C++�Ĺؼ���
const string keyword[] = {
        "asm", "auto", "bool", "break", "case", "catch", "char", "class",
        "const", "const_cast", "continue", "default", "delete", "do", "double", "dynamic_cast",
        "else", "enum", "explicit", "export", "extern", "false", "float",
        "for", "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace",
        "new", "operator", "private", "protected", "public", "register",
        "reinterpret_cast", "return", "short", "signed", "sizeof", "static",
        "static_cast", "struct", "switch", "template",
        "this", "throw", "true", "try", "typedef", "typeid", "typename",
        "union", "unsigned", "using", "virtual", "void", "volatile", "wchar_t", "while"
};

//ö�����ͣ���������ʷ���������ı�ʶ
enum TYPE { KEYW, ID, NUM, STR, OPER, NOTE, SPEC };

class AnalyzeProgram
{

public:
	AnalyzeProgram();  //���캯�����򿪴��������ļ�
	//�ж��Ƿ�Ϊ����
	bool isDigit(char ch);

	//�ж��Ƿ�Ϊ��ĸ
	bool isLetter(char ch);

	//�ж��Ƿ�Ϊ�ؼ���
	bool isKeyWord(string s);

	void print(string s, TYPE type);

	//����������
	void analyse();
	//��ȡ�������
	string getResult();
	
	virtual ~AnalyzeProgram();

protected:
	
	string buf;		//������
	int num;   //����������
	string result;  //�洢�������
	
};



