#include <stdio.h>
int main()
{
	//��ʼ��
	int price=0,bill=0;
	
	//�������Ʊ��
	printf("���������Ʊ�棺");
	scanf("%d %d",&price,&bill);
	
	//����
	if (bill<price)
	{
	printf("�Բ������Ǯ������\n");
    }
    else
	{
	printf("����%dԪ��\n",bill-price); 
    }
    
	return 0;
}
