#include<stdio.h>
#include"linkedlist.c"
#include<stdlib.h> 


int main()
{
	ElemType inte; //����һ���������ڲ������� 
	char choice;
	char* s;   //������ȡ�����ָ�� 
	printf("֣������������̫�ˣ�����������������ֻ�������������������������͵����ݣ�\n���ܻᷢ��Ī����������顣�м��мǣ�����\n\n");
	printf("�����Ĳ�С��������������������ص�������������(((o(*?��?*)o)))\n\n");
	printf("�����ʲô�Ľ������ӭ�������Ȼ�Ҳ�һ���ܸĵ���23333\n\n");
	printf("����������һ�������Դ���һ���������������������-1��\n");
	
	
	LNode *head;  //ͷ��� 
	LNode *p;     //����������������� 
	
	head = (LNode*)malloc(sizeof(LNode));
	head->next = NULL;
	p = head;
	
	
	int res;
	res = scanf("%d",&inte);
	Rescan( res, inte);
	gets(s);  //����һ������ 
	if(res==1)
	{
		while(inte != -1 && res ==1)
		{
			LNode* tail = (LNode*)malloc(sizeof(LNode));
			tail->data = inte;
			InsertList(p, tail);
			p = p->next;
			res = scanf("%d",&inte);
		}
	} 
	else printf("�������"); 
	 
	
	
	if(head->next)
	{
		printf("�����������������ݣ�\n"); 
		TraverseList(head, PrintElem);
		printf("\n");
	}
	
	printf("\n\n�����������������ʲô��\n\n");
	
	while(1)
	{
		getchar();
		printf("-------------------------------------------\n");
		printf("|  a.��ʼ������                            |\n");
		printf("|  b.������������(������-1Ϊ������־)      |\n");
		printf("|  c.�ж�ĳ�����ڲ������������            |\n");
		printf("|  d.������������������                  |\n");
		printf("|  e.��ӡ�����������                      |\n");
		printf("|  f.���������˳�                        |\n");
		printf("-------------------------------------------\n\n");
		
		scanf("%c",&choice);   //����ѡ�� 
		
		if(choice != 'a' && choice != 'b' && choice != 'c' && choice !='d' && choice != 'e' && choice != 'f' )
		{
			getchar();
			printf("ָ�����\n\n"); 
		}
		
		else if (choice=='a')
		{
			int res;
			res=InitList(&head);
			if(res==1)
			{
				printf("��ճɹ�\n\n");
				p = head; 
			}
			else
			{
				printf("ʧ����\n\n"); 
			}
		}
		
		else if(choice=='b')
		{
			printf("���������ݣ�\n");
			scanf("%d",&inte);  //����һ������ 
			while(inte != -1)
			{
				LNode* tail = (LNode*)malloc(sizeof(LNode));
				tail->data = inte;
				InsertList(p, tail);
				p = p->next;
				scanf("%d",&inte);
			}
			
			printf("������������������Ϊ��\n"); 
			TraverseList(head, PrintElem);
			printf("\n\n");
		}
		
		else if(choice=='c')
		{
			printf("�������Ǹ�����");
			scanf("%d",&inte);
			int res; 
			res=SearchList(head, inte);
			if(res==0)
			{
				printf("\n���������û���������\n");
			}
			else
			{
				printf("\n�ҵ��ˣ�\n\n");
			}
		}
		
		else if(choice=='d')
		{
			if(head->next)
			{
			ReverseList(&head);
			printf("�������������Ϊ��\n\n");
			TraverseList(head, PrintElem);
			printf("\n");
			}
			else{
				printf("������������");
			}
			ReverseList(&head);
		}
		
		else if(choice=='e')
		{
			if(head->next)
			{
				printf("�����������������ݣ�\n"); 
				TraverseList(head, PrintElem);
				printf("\n");
			}
			else
			{
				printf("������������");
			}
		}
		
		else if (choice=='f')
		{
			DestroyList(&head);
			printf("OK���ݰ�\n");
			exit(1);  
		}
		
	}
	
	
	return 0;
	
} 
