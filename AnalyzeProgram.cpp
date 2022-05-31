// AnalyzeProgram.cpp: ʵ���ļ�
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
		buf = buf + c;	//����ȡ���ַ���ӵ�buf�ַ�����������
		num++;
	}

	buf[num] = '\0';
	//����۲�
	//cout<<buf<<endl;
}

AnalyzeProgram::~AnalyzeProgram()
{
}





// AnalyzeProgram ��Ϣ�������

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
		//cout<<s<<"\t\t\t\t"<<"�ؼ���"<<endl;
		result = result + s + "\t\t\t\t" + "�ؼ���" + "\r\n";
		break;
	case ID:
		//cout<<s<<"\t\t\t\t"<<"��ʶ��"<<endl;
		result = result + s + "\t\t\t\t" + "��ʶ��" + "\r\n";
		break;
	case NUM:
		//cout<<s<<"\t\t\t\t"<<"��"<<endl;
		result = result + s + "\t\t\t\t" + "��" + "\r\n";
		break;
	case STR:
		//cout<<s<<"\t\t\t\t"<<"�ַ���"<<endl;
		result = result + s + "\t\t\t\t" + "�ַ���" + "\r\n";
		break;
	case OPER:
		//cout<<s<<"\t\t\t\t"<<"�����"<<endl;
		result = result + s + "\t\t\t\t" + "�����" + "\r\n";
		break;
	case NOTE:
		//cout<<s<<"\t\t\t\t"<<"ע�ͷ�"<<endl;
		result = result + s + "\t\t\t\t" + "ע�ͷ�" + "\r\n";
		break;
	case SPEC:
		//cout<<s<<"\t\t\t\t"<<"�����ַ�"<<endl;
		result = result + s + "\t\t\t\t" + "�����ַ�" + "\r\n";
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
		//�����ո���Ʊ��,�޳�
		while (ch == ' ' || ch == '\t' || ch == '\n')
		{	
			i++;
			ch = buf[i];
		}
		//�������ĸ���»��߿�ͷ�����п����ǹؼ��ֻ��ʶ��
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
			{	//���������

				while (ch == '.' || isDigit(ch))
				{
					s = s + ch;
					i++;
					ch = buf[i];
				}
				type = NUM;
				print(s, type);
				s = "";	//���
			}

			else
			{	//�ж��Ƿ�Ϊ����������������ַ�����ע��

				type = OPER;	//Ĭ�������Ϊ�����
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
					if (ch == '/')	//�����Ϊ����*/,��ע�ͽ�����־
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
					case '/':	//����ע�ͷ������
						s = s + ch;
						type = NOTE;
						i++;
						while ((ch = buf[i]) != '\n') //����ע������
						{ i++; }
						break;
					case '*':
						s = s + ch;
						type = NOTE;
						i++;
						while ((ch = buf[i]) != '*' && buf[i + 1] != '/') //����ע������
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
							ch = buf[i];	//����'\''�����
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



