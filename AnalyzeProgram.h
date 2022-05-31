#pragma once

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// AnalyzeProgram
//C++的关键字
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

//枚举类型，用于输出词法分析结果的标识
enum TYPE { KEYW, ID, NUM, STR, OPER, NOTE, SPEC };

class AnalyzeProgram
{

public:
	AnalyzeProgram();  //构造函数，打开待分析的文件
	//判断是否为数字
	bool isDigit(char ch);

	//判断是否为字母
	bool isLetter(char ch);

	//判断是否为关键字
	bool isKeyWord(string s);

	void print(string s, TYPE type);

	//分析主过程
	void analyse();
	//获取分析结果
	string getResult();
	
	virtual ~AnalyzeProgram();

protected:
	
	string buf;		//缓冲区
	int num;   //缓冲区长度
	string result;  //存储分析结果
	
};



