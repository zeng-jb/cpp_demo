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

link createLink()   // 向结尾处添加结点，创建单向加头链表
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

link Find(link p, link q)  // 寻找具有相同 data 的结点
{
	link head, last, t; // 创建一个新的头和尾巴，t 用于删除空的头结点
	/* 因为头结点为空，所以从下一个结点开始 */
	p = p->Next;  
	q = q->Next;
	
	head = last = (link)malloc(sizeof(struct Node)); 
	last->Next = NULL;
	
	while( p ) 
	{
		while( q )
		{
			if( p->data < q->data )  // 如果p结点的值小于q，p向后移
			{
				break; 
		// 因为第一层循环每次执行都会让p后移，所以直接退出第二层循环
			}
			else if( p->data == q->data ) // 如果结点值相同，加入尾部
			{
				link temp = (link)malloc(sizeof(struct Node));
				temp->Next = NULL;
				temp->data = p->data;
				last->Next = temp;
				last = temp;
				q = q->Next;
				break;
			}	
			else // 如果p结点的值大于q，q向后移
			{
				q = q->Next;
			}
		}
		p = p->Next; // p向后移
		if( q==NULL || p==NULL ) break; // 任何一个链表指针为空即结束
	}
	
	last->Next = NULL;
	/* 删除头部空结点，头结点后移 */
	t = head;
	head = head->Next;
	free(t);
	
	return head;
}

void printLink(link p) // 输出链表值
{
	if(p == NULL)
	{
		printf("NULL");
		return ;
	}
	while(p->Next) // 如果p的下一个结点不为空，即下个结点不是结尾空结点
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
 

