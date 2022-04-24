#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct linkedlist{
	int roll;
	char name[30];
	struct linkedlist *next;
}Node;
Node *enterData(int n){
	int i=0;
	Node *head = (Node *) malloc(sizeof(Node));
	Node *p = head;
	printf("Enter roll number and name respectively:\n");
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			scanf("%d %s",&(p->roll),p->name);
			p->next = (Node *) malloc(sizeof(Node));
			p=p->next;
		}
		else{
			scanf("%d %s",&(p->roll),p->name);
			p->next = (Node *) malloc(sizeof(Node));
			p = p->next;
		}
	}
	p->next=NULL;
	//p = NULL;
	printf("\nData entered into the list!\n");
	return head;
}
void showAll(Node *head)
{
	Node *p = head;
	while(p->next!=NULL)
	{
		printf("Roll: %d | Name: %s\n",p->roll,p->name);
		p=p->next;
	}
}
void search(Node *head,int rno)
{
	Node *p = head;
	while(1)
	{
		if(p->roll == rno)
		{
			printf("\nName found for Roll No %d: %s\n",p->roll,p->name);
			break;
		}
		else if(p->next == NULL)
		{
			printf("\nNo record found for Roll %d!\n",rno);
			break;
		}

		p = p-> next;
	}
}
void insert(Node *head,int rno)
{
	Node *p = head;
	Node *new = (Node *) malloc(sizeof(Node));
	char name[30];
	printf("Enter the name: ");
	scanf("%s",&name);
	new->roll = rno;
	strcpy(new->name,name);
	int flag = 0;
	while(1)
	{
		if((p->next)->roll == rno)
		{
			new->next=p->next;
			p->next=new;
			flag = 1;
			break;
		}
		else if(p->next == NULL)
		{
			p = new;
			new->next = NULL;
			break;
		}
		else if(p->roll == rno)
		{
			new->next = p;
			head=new;
			flag = 1;
			break;
		}
		p=p->next;
	}
	if(flag)
	{
		p = new->next;
		while(1)
		{
			p->roll++;
			p = p->next;
			if(p->next == NULL)
				break;
		}
	}
}

int main()
{
	Node *first = enterData(5);
	showAll(first);
	printf("\n");
	search(first,3);
	search(first,4);
	insert(first,6);
	showAll(first);
	return 0;
}
