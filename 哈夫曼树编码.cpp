#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <iomanip>

using namespace std; 

//#define NULL 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAX_NUM 32767

typedef char **HuffmanCode;  //��̬��������洢�����������

typedef struct{
    int weight;
    int parent, lchild, rchild;
}HTNode, *HuffmanTree;  //��̬��������洢��������

typedef struct{
    HuffmanTree HT;
    char        *c;
    int         length;
    HuffmanCode HC;
}Huffman;  //�洢�ַ������


void Select(HuffmanTree HT,int end,int *s1,int *s2)//ѡ��HT[1....i-1]����˫����Ȩֵ��С�������ڵ㣬�����Ϊs1��s2
{
    int i;
    int min1=MAX_NUM;
    int min2;
    for (i=1;i<=end;i++)//��������Ȩֵ��С�Ľ��S1
    {
        if (HT[i].parent==0&&HT[i].weight<min1)
        {
            *s1=i;
            min1=HT[i].weight;
        }
    }
    min2=MAX_NUM;
    for(i=1;i<=end;i++)//�������ҳ�S1��Ȩֵ��С�Ľ��S2
    {
        if(HT[i].parent==0&&(*s1!=i)&&min2>HT[i].weight)
        {
            *s2=i;
            min2=HT[i].weight;
        }
    }
}



Huffman HuffmanCoding(Huffman Hfm)
{//���n���ַ���Ȩֵ������0���������������HT�������n���ַ��Ĺ������������HC
    int i, n, m, s1, s2, start;
    int c, f;
    char *cd;
    n = Hfm.length;
    if (n <= 1)  return Hfm;
    m = 2*n-1;
    for(i = n+1; i <= m; ++i) {//ѡ��HT[1....i-1]����˫����Ȩֵ��С�������ڵ㣬�����Ϊs1��s2
        Select(Hfm.HT, i-1, &s1, &s2);
        Hfm.HT[s1].parent = i;//�޸ĸ���λ��
        Hfm.HT[s2].parent = i;
        Hfm.HT[i].lchild = s1;//�޸ĺ���λ��
        Hfm.HT[i].rchild = s2;
        Hfm.HT[i].weight = Hfm.HT[s1].weight + Hfm.HT[s2].weight;//���׽��ȨֵΪ���Һ���Ȩֵ֮��
    }
    //��Ҷ�ӽ�㵽��������ÿ���ַ��Ĺ���������
    Hfm.HC = (HuffmanCode)malloc((n+1)*sizeof(char *));//����n���ַ������ͷָ������
    cd = (char *)malloc(n*sizeof(char));//���������Ĺ����ռ�
    cd[n-1] = '\0';//���������
    
    for (i = 1; i <= n; ++i) {//����ַ������������
        start = n - 1;//���������λ��
        for (c = i, f = Hfm.HT[i].parent; f != 0; c = f, f = Hfm.HT[f].parent) {
            //��Ҷ�ӵ������������
            if (c == Hfm.HT[f].lchild) {
                cd[--start] = '0';
            } else cd[--start] = '1';
        }
        Hfm.HC[i] = (char *)malloc((n-start)*sizeof(char));
        strcpy(Hfm.HC[i], &cd[start]);//��cd���Ʊ��뵽Hfm.HC
    }
    free(cd);//�ͷŹ����ռ�
    return Hfm;
}

Huffman InputHuffman(Huffman Hfm)  //���뺯���������û������ַ�����ӦȨֵ
{
    int i, n;
    printf("�������ַ�����Сn: ");
    scanf("%d", &n);
    
    if (n <= 1) {
        printf("ֻ��һ���ַ����������!\n");//��ֻ��һ����ֵ���������
        printf("\n�������ַ�����Сn: ");
        scanf("%d",&n);
    }
    printf("\n");
    Hfm.HT = (HuffmanTree)malloc((2 * n) * sizeof(HTNode));
    Hfm.c = (char *)malloc((n + 1) * sizeof(char));
    
    for (i = 1; i <= n; i++) {
        printf("�������ַ�: ");
        scanf("%s", &Hfm.c[i]);
        printf("����������Ȩֵ: ");
        scanf("%d", &Hfm.HT[i].weight);
        Hfm.HT[i].parent = 0;
        Hfm.HT[i].lchild = 0;
        Hfm.HT[i].rchild = 0;
        printf("\n");
    }
    for(; i <= 2*n-1; ++i) {
        Hfm.HT[i].weight = 0;
        Hfm.HT[i].parent = 0;
        Hfm.HT[i].lchild = 0;
        Hfm.HT[i].rchild = 0;
    }
    Hfm.length = n;
    return Hfm;
}

Huffman InitHuffman(Huffman Hfm)
{//��ʼ������������Ҫ���û������ַ�����ӦȨֵ
    printf("\n--����������ʼ��--\n");
    int n, i;
    char x;
    FILE *fp;
    fp = fopen("hfmtree", "rt");//���ļ�hfmtree�Զ��ı�����ʽ��
    if (fp == NULL) {
        Hfm = InputHuffman(Hfm);//����InputHuffman�������û������ַ�����ӦȨֵ�������������
        fp = fopen("hfmtree", "wt");
        fprintf(fp, "%d\n", Hfm.length);
        for (i = 1; i <= Hfm.length; i++)
            fprintf(fp, "%c %d  ", Hfm.c[i], Hfm.HT[i].weight);
        rewind(fp);
    } else {
        getchar();
        printf("���������Ѵ��ڣ�\n������Ҫ�½�һ������������(Y/N)? ");//ѯ���Ƿ����³�ʼ��
        scanf("%c", &x);
        if (x == 'Y'|| x == 'y') {
            Hfm = InputHuffman(Hfm);  //����InputHuffman�������û������ַ�����ӦȨֵ�������������
            fp = fopen("hfmtree", "w+");
            fprintf(fp, "%d\n", Hfm.length);
            for (i = 1; i <= Hfm.length; i++)
                fprintf(fp, "%c %d  ", Hfm.c[i], Hfm.HT[i].weight);
            rewind(fp);
        } else { // 'N'||'n'
            fscanf(fp, "%d\n", &n);
            Hfm.c = (char *)malloc((n + 1) * sizeof(char));
            Hfm.HT = (HuffmanTree)malloc((2 * n) * sizeof(HTNode));
            for (i = 1; i <= n; i++)
                fscanf(fp, "%s %d  ", &Hfm.c[i], &Hfm.HT[i].weight);//���Ѿ����ļ��е��ַ������Ӧ��Ȩ�����뵽Hfm.c[i]��&Hfm.HT[i].weight��
            for (i = 1; i <= n; i++) {//��ÿ���ڵ��ʼ��
                Hfm.HT[i].parent = 0;
                Hfm.HT[i].lchild = 0;
                Hfm.HT[i].rchild = 0;
            }
            for(; i <= 2*n-1; ++i) {
                Hfm.HT[i].weight = 0;
                Hfm.HT[i].parent = 0;
                Hfm.HT[i].lchild = 0;
                Hfm.HT[i].rchild = 0;
            }
            Hfm.length = n;
        }
    }
    fclose(fp);
    printf("���������ĳ�ʼ�������!\n\n");
    Hfm = HuffmanCoding(Hfm);
    return Hfm;
}

void Encoding(Huffman Hfm)
{//�����ѽ��õ�Huffman�����粻���ڴ棬����ļ�hfmtree�ж��룩��
    //���ļ�ToBeTran�е����Ľ��б��룬Ȼ�󽫽�������ļ�codefile�С�
    int i = 0, j = 0, n, k = 0;
    char ch[60];
    FILE *fp, *fw;
    n = Hfm.length;
    printf("\n--����--\n");
    
    do {
        printf("1. ��tobetrans.txt�����Ľ��б���\n");
        printf("2. �Լ�����ַ������б���\n");
        printf("����������: ");
        scanf("%d", &k);
        printf("\n");
        if (k == 1) {
            if ((fw = fopen("tobetrans", "r+")) == NULL) {
                printf("tobetrans.txt������!\n\n");
            } else {
                printf("�Ѷ�ȡtobetrans.txt�е�����\n");
                printf("����������: ");
                fscanf(fw, "%s", ch);
                fclose(fw);
                fp = fopen("codefile", "wt+");
                k = 0;
            }
        } else if (k == 2) {
            printf("������Ҫ������ַ���: ");
            scanf("%s", ch);
            printf("����������: ");
            fp = fopen("codefile", "wt+");
            k = 0;
        }
        if (k == 0) {   //����doѭ��
            break;
        }
    } while (k != 1 || k != 2);
    
    while(ch[j]) {
        for (i = 1; i <= n; i++) {
            if (ch[j] == Hfm.c[i]) {
                printf("%s", Hfm.HC[i]);
                fprintf(fp, "%s", Hfm.HC[i]);
                break;
            }
        }
        j++;
    }
    printf("\n�ѽ��������codefile.txt\n\n");
    rewind(fp);
    fclose(fp);
}

void Decoding(Huffman Hfm)
{//�����ѽ��õ�Huffman�����ļ�codefile�еĴ���������룬��������ļ�TextFile�С�
    HuffmanTree p;
    int i, n;
    int j = 0;
    char d[500];
    FILE *fp;
    n = Hfm.length;
    printf("\n--����--\n");
    if((fp = fopen("codefile", "r+")) == NULL) {
        printf("���������������:");
        scanf("%s",d);
    } else {
        fscanf(fp, "%s", d);//���ļ��е��ַ����뵽����d��
        fclose(fp);
    }
    printf("�������codefile.txt��������: ");
    fp = fopen("TextFile","wt+");//��д���ļ�����ʽ��TextFile
    while (d[j]) {
        p = &Hfm.HT[2*n-1];
        while (p->lchild || p->rchild) {
            if (d[j] == '0') {
                i = p->lchild;
                p = &Hfm.HT[i];
            } else {
                i = p->rchild;
                p = &Hfm.HT[i];
            }
            j++;
        }
        printf("%c", Hfm.c[i]);
        fprintf(fp,"%c", Hfm.c[i]);
    }
    printf("\n\n");
    fclose(fp);
}


void Print(Huffman Hfm)
{//���ļ�codefile�Խ��ո�ʽ��ʾ���ն��ϣ�ÿ��50 �����롣
    int i, n;
    int m = 1;//������
    char ch;
    FILE *fprint;
    n = Hfm.length;
    printf("\n--��ӡ�����ļ�--\n");
    
    printf("codefile.txt����: \n");
    
    fprint = fopen("codefile", "rb");
    while (!feof(fprint)) {
        ch = fgetc(fprint);
        printf("%c", ch);
        m++;
        if (m % 50 == 0)//��֤ÿһ�����50���ַ�
            printf("\n");
    }
    fclose(fprint);
    
    
    printf("\n�����ļ�: \n");
    printf("�ַ�\t\tȨֵ\t\t����\n");
    for (i = 1; i <= n; i++) {//��ʾÿһ���ַ���Ӧ�Ĺ���������
        printf("%c\t\t", Hfm.c[i]);
        printf("%d\t\t", Hfm.HT[i].weight);
        printf("");
        puts(Hfm.HC[i]);
    }
    
    printf("\n");
    
}

int numb = 0;
void coprint(HuffmanTree start, HuffmanTree HT)
{//��ӡ��������
    char t = ' ';
    if (start != HT) {
        FILE *TreePrint;
        if ((TreePrint = fopen("TreePrint", "a")) == NULL) {
            printf("�����ļ�ʧ��\n");
            return;
        }
        numb++;
        coprint(HT+start->rchild, HT);
        if (start->lchild != 0 && start->rchild != 0) {
            t = '<';
        }
        cout << setw(5*numb) << start->weight << t << endl;
        fprintf(TreePrint, "%d\n", start->weight);
        coprint(HT+start->lchild, HT);
        numb--;
        fclose(TreePrint);
    }
    
}

void Print_Tree(HuffmanTree HT, int w)
{//ֱ�۴�ӡ��������
    HuffmanTree p;
    p = HT + w;
    printf("��ӡ��������: \n");
    coprint(p, HT);
    printf("��ӡ��ɣ�\n\n");
}



int main()
{
    Huffman Hfm;
    char k;
    while(1) {
        printf("--��������������--         ע: ��_����ո�\n");
        printf("I. ��ʼ��\n");
        printf("C. ����\n");
        printf("D. ����\n");
        printf("P. ��ӡ�����ļ�\n");
        printf("T. ��ӡ��������\n");
        printf("Q. �˳�\n");
        printf("����������: ");
        scanf("%c",&k);
        k=toupper(k);
        switch(k) {
            case 'I':
                Hfm=InitHuffman(Hfm);
                //getchar();
                break;
            case 'C':
                Encoding(Hfm);
                //getchar();
                break;
            case 'D':
                Decoding(Hfm);
                //getchar();
                break;
            case 'P':
                Print(Hfm);
                //getchar();
                break;
            case 'T':
                Print_Tree(Hfm.HT, 2*Hfm.length-1);
                //getchar();
                break;
            case 'Q':
                exit(0);
            default:
            printf("�����������������\n"); }
    }
}
