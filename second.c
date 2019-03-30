#include<stdio.h>
#include"linkedlist.c"
#include<stdlib.h> 


int main()
{
	ElemType inte; //声明一个整数用于插入链表 
	char choice;
	char* s;   //用来读取多余的指令 
	printf("郑重声明：作者太菜，这个程序的链表数据只能输入整数，若输入其他类型的数据，\n可能会发生莫名其妙的事情。切记切记！！！\n\n");
	printf("如果真的不小心输入了其他东西，请关掉程序重新来过(((o(*?▽?*)o)))\n\n");
	printf("如果有什么改进意见欢迎提出，虽然我不一定能改得了23333\n\n");
	printf("现在请输入一串整数以创造一个链表，若输入完成请输入-1：\n");
	
	
	LNode *head;  //头结点 
	LNode *p;     //用以向链表插入数据 
	
	head = (LNode*)malloc(sizeof(LNode));
	head->next = NULL;
	p = head;
	
	
	int res;
	res = scanf("%d",&inte);
	Rescan( res, inte);
	gets(s);  //输入一个整数 
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
	else printf("输入错误"); 
	 
	
	
	if(head->next)
	{
		printf("现在输出链表里的数据：\n"); 
		TraverseList(head, PrintElem);
		printf("\n");
	}
	
	printf("\n\n请告诉我你接下来想干什么？\n\n");
	
	while(1)
	{
		getchar();
		printf("-------------------------------------------\n");
		printf("|  a.初始化链表                            |\n");
		printf("|  b.继续输入数据(以输入-1为结束标志)      |\n");
		printf("|  c.判断某个数在不在你的链表里            |\n");
		printf("|  d.倒序输出链表里的数据                  |\n");
		printf("|  e.打印链表里的数据                      |\n");
		printf("|  f.销毁链表并退出                        |\n");
		printf("-------------------------------------------\n\n");
		
		scanf("%c",&choice);   //输入选项 
		
		if(choice != 'a' && choice != 'b' && choice != 'c' && choice !='d' && choice != 'e' && choice != 'f' )
		{
			getchar();
			printf("指令错误\n\n"); 
		}
		
		else if (choice=='a')
		{
			int res;
			res=InitList(&head);
			if(res==1)
			{
				printf("清空成功\n\n");
				p = head; 
			}
			else
			{
				printf("失败了\n\n"); 
			}
		}
		
		else if(choice=='b')
		{
			printf("请输入数据：\n");
			scanf("%d",&inte);  //输入一个整数 
			while(inte != -1)
			{
				LNode* tail = (LNode*)malloc(sizeof(LNode));
				tail->data = inte;
				InsertList(p, tail);
				p = p->next;
				scanf("%d",&inte);
			}
			
			printf("现在输出链表里的数据为：\n"); 
			TraverseList(head, PrintElem);
			printf("\n\n");
		}
		
		else if(choice=='c')
		{
			printf("请输入那个数：");
			scanf("%d",&inte);
			int res; 
			res=SearchList(head, inte);
			if(res==0)
			{
				printf("\n你的链表里没有这个数。\n");
			}
			else
			{
				printf("\n找到了！\n\n");
			}
		}
		
		else if(choice=='d')
		{
			if(head->next)
			{
			ReverseList(&head);
			printf("倒序输出的数据为：\n\n");
			TraverseList(head, PrintElem);
			printf("\n");
			}
			else{
				printf("链表里无数据");
			}
			ReverseList(&head);
		}
		
		else if(choice=='e')
		{
			if(head->next)
			{
				printf("现在输出链表里的数据：\n"); 
				TraverseList(head, PrintElem);
				printf("\n");
			}
			else
			{
				printf("链表里无数据");
			}
		}
		
		else if (choice=='f')
		{
			DestroyList(&head);
			printf("OK，拜拜\n");
			exit(1);  
		}
		
	}
	
	
	return 0;
	
} 
