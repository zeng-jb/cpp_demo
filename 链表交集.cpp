//#include <iostream>
//using namespace std;
//typedef struct list{
//	int data;
//	struct list*next;
//}link;
//list input(){
//	int c;
//	link *head,*last,*p;
//	head=new link;
//	last=head;
//	
//	cin>>c;
//	while(c!=-1){
//		p=new link;
//		p->next=NULL;
//		p->data=c;
//		last->next=p;
//		last=p;
//		cin>>c;
//	}
//	return *head;
//}
//list sort(list s1,list s2){
//	link *head,*last,*del;
//	head=new link;
//	last=head;
//	last->next=NULL; 
//	while(s1->next!=NULL){
//		while(s2->next!=NUll){
//			if(s1->data < s2->data)break;
//			else if(s1->data > s2->data) s2=s2->next;
//			else{
//				link temp=new link;
//				temp->next=NULL;
//				temp->data=s2->data;
//				last->next=temp;
//				last=temp;
//				s2=s2->next;
//				break;
//			}
//		}
//		s1=s1->next;
//		if(s1==NULL||s2==NULL)break;
//	}
//	last->next=NULL;
//	t=head;
//	head=head->next;
//	delete t;
//	return head;
//}
//int main(){
//	link *s1,*s2,*s3;
//	s1=input();
//	s2=input();
//	s3=sort(s1,s2);
//	if(s3==NULL) cout<<"NULL"<<endl;
//	else{
//		while(s3->next!=NULL){
//			cout<<s3->data;
//		}
//	}
//}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *Next;
} *link;

link createLink()   // ���β����ӽ�㣬���������ͷ����
{
	link head, last, p;
	int x;
	head = (link)malloc(sizeof(struct Node));
	last = head;
	
	while( scanf("%d", &x) != EOF && x != -1 )
	{
		p = (link)malloc(sizeof(struct Node));
		p->Next = NULL;
		p->data = x;
		last->Next = p;
		last = p;
	}
	
	return head;
}

link Find(link p, link q)  // Ѱ�Ҿ�����ͬ data �Ľ��
{
	link head, last, t; // ����һ���µ�ͷ��β�ͣ�t ����ɾ���յ�ͷ���
	/* ��Ϊͷ���Ϊ�գ����Դ���һ����㿪ʼ */
	p = p->Next;  
	q = q->Next;
	
	head = last = (link)malloc(sizeof(struct Node)); 
	last->Next = NULL;
	
	while( p ) 
	{
		while( q )
		{
			if( p->data < q->data )  // ���p����ֵС��q��p�����
			{
				break; 
		// ��Ϊ��һ��ѭ��ÿ��ִ�ж�����p���ƣ�����ֱ���˳��ڶ���ѭ��
			}
			else if( p->data == q->data ) // ������ֵ��ͬ������β��
			{
				link temp = (link)malloc(sizeof(struct Node));
				temp->Next = NULL;
				temp->data = p->data;
				last->Next = temp;
				last = temp;
				q = q->Next;
				break;
			}	
			else // ���p����ֵ����q��q�����
			{
				q = q->Next;
			}
		}
		p = p->Next; // p�����
		if( q==NULL || p==NULL ) break; // �κ�һ������ָ��Ϊ�ռ�����
	}
	
	last->Next = NULL;
	/* ɾ��ͷ���ս�㣬ͷ������ */
	t = head;
	head = head->Next;
	free(t);
	
	return head;
}

void printLink(link p) // �������ֵ
{
	if(p == NULL)
	{
		printf("NULL");
		return ;
	}
	while(p->Next) // ���p����һ����㲻Ϊ�գ����¸���㲻�ǽ�β�ս��
	{
		printf("%d ", p->data);
		p = p->Next;
	}
	printf("%d", p->data); 
}

int main()
{
	link p, q, result;
	
	p = createLink();
	q = createLink();
	result = Find(p, q); 
	printLink(result);
	
	return 0;
}
 

