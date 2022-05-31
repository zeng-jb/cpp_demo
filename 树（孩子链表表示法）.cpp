#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 20
#define TElemType char
//���ӱ�ʾ��
typedef struct CTNode{
    int child;//������ÿ�����洢�Ĳ������ݱ������������������д洢��λ���±�
    struct CTNode * next;
}ChildPtr;
typedef struct {
    TElemType data;//������������
    ChildPtr* firstchild;//���������ͷָ��
}CTBox;
typedef struct{
    CTBox nodes[MAX_SIZE];//�洢��������
    int n,r;//���������������λ��
}CTree;
//���ӱ�ʾ���洢��ͨ��
CTree initTree(CTree tree){
    printf("����ڵ�������\n");
    scanf("%d",&(tree.n));
    for(int i=0;i<tree.n;i++){
        printf("����� %d ���ڵ��ֵ��\n",i+1);
        fflush(stdin);
        scanf("%c",&(tree.nodes[i].data));
        tree.nodes[i].firstchild=(ChildPtr*)malloc(sizeof(ChildPtr));
        tree.nodes[i].firstchild->next=NULL;

        printf("����ڵ� %c �ĺ��ӽڵ�������\n",tree.nodes[i].data);
        int Num;
        scanf("%d",&Num);
        if(Num!=0){
            ChildPtr * p = tree.nodes[i].firstchild;
            for(int j = 0 ;j<Num;j++){
                ChildPtr * newEle=(ChildPtr*)malloc(sizeof(ChildPtr));
                newEle->next=NULL;
                printf("����� %d �����ӽڵ���˳����е�λ��",j+1);
                scanf("%d",&(newEle->child));
                p->next= newEle;
                p=p->next;
            }
        }
    }
    return tree;
}

void findKids(CTree tree,char a){
    int hasKids=0;
    for(int i=0;i<tree.n;i++){
        if(tree.nodes[i].data==a){
            ChildPtr * p=tree.nodes[i].firstchild->next;
            while(p){
                hasKids = 1;
                printf("%c ",tree.nodes[p->child].data);
                p=p->next;
            }
            break;
        }
    }
    if(hasKids==0){
        printf("�˽ڵ�ΪҶ�ӽڵ�");
    }
}

int main()
{
    CTree tree;
    tree = initTree(tree);
    //Ĭ�������ڵ�λ������notes[0]��
    tree.r=0;
    printf("�ҳ��ڵ� F �����к��ӽڵ㣺");
    findKids(tree,'F');
    return 0;
}
