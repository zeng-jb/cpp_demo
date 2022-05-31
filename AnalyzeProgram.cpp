// AnalyzeProgram.cpp: 实现文件
//

#include "AnalyzeProgram.h"
#include<stdlib.h>
#include<iostream>
using namespace std;
// AnalyzeProgram



AnalyzeProgram::AnalyzeProgram()
{
//	fstream infile;
//	infile.open(path, ios::in);
//	if (!infile)
//	{
//		cerr << path << " can't open ! " << endl;
//	}
	FILE * fp;
	fp=fopen("E:\\test.txt","r");
	
	num = 0;
	while (true)
	{
		char c;
		c = fgetc(fp);
		if (c != EOF)
		{
			break;
		}
		buf = buf + c;	//将读取的字符添加到buf字符串缓冲区中
		num++;
	}

	buf[num] = '\0';
	//输出观察
	//cout<<buf<<endl;
}

AnalyzeProgram::~AnalyzeProgram()
{
}





// AnalyzeProgram 消息处理程序

bool AnalyzeProgram::isDigit(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return true;
	}
	return false;
}

bool AnalyzeProgram::isLetter(char ch)
{
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a'&& ch <= 'z'))
	{
		return true;
	}
	return false;
}

bool AnalyzeProgram::isKeyWord(string s)
{
	int n = sizeof(keyword) / sizeof(keyword[0]);
	for (int i = 0; i < n; i++)
	{
		if (s == keyword[i])
		{
			return true;
		}
	}
	return false;
}

void AnalyzeProgram::print(string s, TYPE type)
{
	switch (type)
	{
	case KEYW:
		//cout<<s<<"\t\t\t\t"<<"关键字"<<endl;
		result = result + s + "\t\t\t\t" + "关键字" + "\r\n";
		break;
	case ID:
		//cout<<s<<"\t\t\t\t"<<"标识符"<<endl;
		result = result + s + "\t\t\t\t" + "标识符" + "\r\n";
		break;
	case NUM:
		//cout<<s<<"\t\t\t\t"<<"数"<<endl;
		result = result + s + "\t\t\t\t" + "数" + "\r\n";
		break;
	case STR:
		//cout<<s<<"\t\t\t\t"<<"字符串"<<endl;
		result = result + s + "\t\t\t\t" + "字符串" + "\r\n";
		break;
	case OPER:
		//cout<<s<<"\t\t\t\t"<<"运算符"<<endl;
		result = result + s + "\t\t\t\t" + "运算符" + "\r\n";
		break;
	case NOTE:
		//cout<<s<<"\t\t\t\t"<<"注释符"<<endl;
		result = result + s + "\t\t\t\t" + "注释符" + "\r\n";
		break;
	case SPEC:
		//cout<<s<<"\t\t\t\t"<<"特殊字符"<<endl;
		result = result + s + "\t\t\t\t" + "特殊字符" + "\r\n";
		break;
	default:
		break;
	}
}

string AnalyzeProgram::getResult()
{
	return result;
}

void AnalyzeProgram::analyse()
{
	//enum TYPE {KEYW,ID,NUM,STR,OPER,NOTE,SPEC};
	TYPE type;
	string s,s1;
	int i = 0;
	char ch;
	while (i <= num && (ch = buf[i]) != '\0')
	{
		//遇到空格和制表符,剔除
		while (ch == ' ' || ch == '\t' || ch == '\n')
		{	
			i++;
			ch = buf[i];
		}
		//如果是字母或下划线开头，则有可能是关键字或标识符
		if (isLetter(ch) || ch == '_')
		{	
			while (isLetter(ch) || isDigit(ch) || ch == '_')
			{
				s = s + ch;
				i++;
				ch = buf[i];
			}

			if (isKeyWord(s))
				{ type = KEYW; }
			else 
				{ type = ID; }
			print(s, type);
			s = "";
		}

		else
		{
			if (isDigit(ch))
			{	//如果是数字

				while (ch == '.' || isDigit(ch))
				{
					s = s + ch;
					i++;
					ch = buf[i];
				}
				type = NUM;
				print(s, type);
				s = "";	//清空
			}

			else
			{	//判断是否为运算符、串、特殊字符、或注释

				type = OPER;	//默认情况下为运算符
				switch (ch)
				{
				case '[':
				case ']':
				case '(':
				case ')':
				case '%':
				case '~':
				case '^':
				//case ',':
				case '.':
				{
					s = s + ch;
					i++;
					break;
				}
				case '=':
				{
					s = s + ch;
					i++;
					ch = buf[i];
					if (ch == '=')
					{
						s = s + ch;
						i++;
					}
					break;
				}
				case '+':
				{
					s = s + ch;
					i++;
					ch = buf[i];
					if (ch == '+' || ch == '=')
					{
						s = s + ch;
						i++;
					}
					break;
				}
				case '-':
				{
					s = s + ch;
					i++;
					ch = buf[i];
					if (ch == '-' || ch == '>' || ch == '=')
					{
						s = s + ch;
						i++;
					}
					break;
				}
				case '*':
				{
					s = s + ch;
					i++;
					ch = buf[i];
					if (ch == '/')	//此情况为碰到*/,即注释结束标志
					{
						s = s + ch;
						type = NOTE;
						i++;
					}
					else 
					{
						if (ch == '=')
						{
							s = s + ch;
							i++;
						}
					}
					break;
				}
				case '/':
				{
					s = s + ch;
					i++;
					ch = buf[i];
					switch (ch)
					{
					case '/':	//单行注释符的情况
						s = s + ch;
						type = NOTE;
						i++;
						while ((ch = buf[i]) != '\n') //忽略注释内容
						{ i++; }
						break;
					case '*':
						s = s + ch;
						type = NOTE;
						i++;
						while ((ch = buf[i]) != '*' && buf[i + 1] != '/') //忽略注释内容
						{ i++; }
						break;
					case '=':
						s = s + ch;
						i++;
						break;
					default:
						break;
					}
					break;
				}
				case '<':
				{
					s = s + ch;
					i++;
					ch = buf[i];
					switch (ch)
					{
					case '<':
					case '=':
						s = s + ch;
						i++;
						break;
					default:
						break;
					}
					break;
				}
				case '>':
				{
					s = s + ch;
					i++;
					ch = buf[i];
					switch (ch)
					{
					case '>':
					case '=':
						s = s + ch;
						i++;
						break;
					default:
						break;
					}
					break;
				}
				case '&':
				{
					s = s + ch;
					i++;
					ch = buf[i];
					if (ch == '&')
					{
						s = s + ch;
						i++;
					}
					break;
				}
				case '|':
				{
					s = s + ch;
					i++;
					ch = buf[i];
					if (ch == '|')
					{
						s = s + ch;
						i++;
					}
					break;
				}
				case '!':
				{
					s = s + ch;
					i++;
					ch = buf[i];
					if (ch == '=')
					{
						s = s + ch;
						i++;
					}
					break;
				}
				case '\'':
				{
					s = s + ch;
					i++;
					ch = buf[i];
					while (ch != '\'')
					{
						s = s + ch;
						i++;
						if (ch == '\\')
						{
							ch = buf[i];	//处理'\''的情况
							s = s + ch;
							i++;
						}
						ch = buf[i];
					}
					s = s + ch;
					type = STR;
					i++;
					break;
				}
				case '\"':
				{
					s = s + '"';
					i++;
					ch = buf[i];
					while (ch != '"')
					{
						s = s + ch;
						i++;
						ch = buf[i];
					}
					s = s + '"';
					type = STR;
					i++;
					break;
				}
				default:
				{
					type = SPEC;
					s = s + ch;
					i++;
					break;
				}

				}
				print(s, type);
				s = "";
			}
		}
	}
}



