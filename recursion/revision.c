#include <stdio.h>
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
int main()
{
	Node *first = enterData(10);
	showAll(first);
	return 0;
}
